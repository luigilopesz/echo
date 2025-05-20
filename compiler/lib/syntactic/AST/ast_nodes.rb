require_relative "node"
require_relative "../symboltable/symboltable"

# Represents the value returned by a '>>' statement or from a block/function
class ReturnValue
  attr_reader :value # This will be a [actual_value, type_string] pair or a special marker

  def initialize(value)
    @value = value
  end
end

# Global access to the current symbol table
class Assignment # Using this class as a namespace for the symbol_table, as in original
  @symbol_table = nil # Will be initialized by the interpreter
  def self.symbol_table
    @symbol_table
  end

  def self.symbol_table=(table)
    @symbol_table = table
  end
end


# --- Helper for type conversion/checking ---
def ensure_type(value, current_type, expected_type, operation_description)
  unless current_type == expected_type
    # Basic coercion for num from txt if possible for some operations,
    # but Echo is strictly typed based on declarations.
    # For now, raise error for type mismatch.
    raise StandardError, "Type Mismatch for #{operation_description}: Expected #{expected_type}, but got #{current_type} for value '#{value}'."
  end
  value
end

def value_to_echo_string(value, type)
  case type
  when "txt"
    value
  when "num"
    value.to_s # Consider formatting for floats if needed
  when "bool"
    value.to_s # Ruby's true.to_s is "true", false.to_s is "false"
  when "list"
    "[" + value.map { |v, t| value_to_echo_string(v, t) }.join(", ") + "]" # Assuming list elements are [val, type]
  when "obj"
    # Assuming obj_value is a hash like {key_sym: {value: val, type: type_str}}
    members = value.map do |key, member_info|
      "#{key}: #{value_to_echo_string(member_info[:value], member_info[:type])}"
    end.join("; ")
    "{#{members}}"
  when "silent"
    "silent"
  else
    value.to_s # Default
  end
end


# --- AST Node Definitions with Evaluate Methods ---

class BinOp < Node # Children: [left_operand, right_operand], Value: operator
  def evaluate
    if @value == 'BLOCK' # Represents a sequence of statements (a block)
      # Blocks manage their own scope if they are not function bodies or special constructs
      # This 'BLOCK' is usually the root of a program or body of if/loop etc.
      # Scope for these is typically handled by the calling node (FuncDec, IfNode, LoopNode)

      last_evaluated_result = [nil, "silent"] # Default for an empty block
      @children.each do |child_statement|
        eval_result = child_statement.evaluate
        if eval_result.is_a?(ReturnValue)
          return eval_result # Propagate return upwards
        end
        last_evaluated_result = eval_result # Keep track of the last non-return result
      end
      return last_evaluated_result # Result of the block is the result of its last statement
    end

    # Binary operations
    left_val, left_type = @children[0].evaluate
    return [left_val, left_type] if left_val.is_a?(ReturnValue) # Should not happen if parser is correct about expr

    right_val, right_type = @children[1].evaluate
    return [right_val, right_type] if right_val.is_a?(ReturnValue)

    # puts "[DEBUG BinOp '#{@value}'] Left: #{left_val.inspect}(#{left_type}), Right: #{right_val.inspect}(#{right_type})" if $DEBUG

    case @value
    when '+', '-', '*', '/'
      ensure_type(left_val, left_type, "num", "Arithmetic operation '#{@value}' left operand")
      ensure_type(right_val, right_type, "num", "Arithmetic operation '#{@value}' right operand")
      case @value
      when '+' then [left_val + right_val, "num"]
      when '-' then [left_val - right_val, "num"]
      when '*' then [left_val * right_val, "num"]
      when '/'
        raise ZeroDivisionError, "Runtime Error: Division by zero" if right_val == 0
        [left_val.to_f / right_val.to_f, "num"] # Ensure float division for num
      end
    when '++' # Concatenation
      # Coerce operands to string for concatenation as per Echo spec (implicitly)
      s_left = value_to_echo_string(left_val, left_type)
      s_right = value_to_echo_string(right_val, right_type)
      [s_left + s_right, "txt"]
    when '&&', '\\\\' # Logical AND, OR (double backslash for OR token value)
      ensure_type(left_val, left_type, "bool", "Logical operation '#{@value}' left operand")
      # Short-circuiting for logical operators
      if @value == '&&'
        return [false, "bool"] unless left_val
      elsif @value == '\\\\' # OR
        return [true, "bool"] if left_val
      end
      ensure_type(right_val, right_type, "bool", "Logical operation '#{@value}' right operand") # Evaluate right only if necessary
      case @value
      when '&&'   then [left_val && right_val, "bool"]
      when '\\\\' then [left_val || right_val, "bool"]
      end
    when '==', '!='
      # Allow comparison between any two types, result is bool.
      # Echo spec doesn't specify strict type equality for ==/!=, usually means compare values.
      # For simplicity, we'll compare values directly. More complex objects/lists might need deep comparison.
      res = left_val == right_val
      res = !res if @value == '!='
      [res, "bool"]
    when '<', '>', '<=', '>='
      # Relational ops typically on num or txt
      if left_type == "num" && right_type == "num"
        # proceed
      elsif left_type == "txt" && right_type == "txt"
        # proceed
      else
        raise StandardError, "Runtime Error: Relational operation '#{@value}' requires operands of same type (num or txt). Got #{left_type} and #{right_type}."
      end
      case @value
      when '<'  then [left_val < right_val, "bool"]
      when '>'  then [left_val > right_val, "bool"]
      when '<=' then [left_val <= right_val, "bool"]
      when '>=' then [left_val >= right_val, "bool"]
      end
    else
      raise StandardError, "Runtime Error: Unknown binary operator '#{@value}'"
    end
  end
end

class UnOp < Node # Children: [operand], Value: operator
  def evaluate
    operand_val, operand_type = @children[0].evaluate
    return [operand_val, operand_type] if operand_val.is_a?(ReturnValue)

    case @value
    when '-' # Unary minus
      ensure_type(operand_val, operand_type, "num", "Unary minus operation")
      [-operand_val, "num"]
    when '!' # Logical NOT
      ensure_type(operand_val, operand_type, "bool", "Logical NOT operation")
      [!operand_val, "bool"]
    else
      raise StandardError, "Runtime Error: Unknown unary operator '#{@value}'"
    end
  end
end

class NumVal < Node
  def evaluate
    [@value, "num"]
  end
end

class TxtVal < Node
  def evaluate
    [@value, "txt"]
  end
end

class BoolVal < Node
  def evaluate
    [@value, "bool"]
  end
end

class Identifier < Node
  def evaluate
    var_info = Assignment.symbol_table.get(@value) # @value is the identifier name
    [var_info[:value], var_info[:type]]
  end
end

class NoOp < Node
  def evaluate
    [nil, "silent"]
  end
end

class VarDeclNode < Node
  attr_accessor :var_name, :var_type, :init_expr
  def initialize(var_name, var_type_str, init_expr = nil)
    super(var_name)
    @var_name = var_name
    @var_type = var_type_str
    @init_expr = init_expr
    @children = [@init_expr].compact
  end

  def evaluate
    if Assignment.symbol_table.is_declared_locally?(@var_name)
      raise StandardError, "Runtime Error: Variable '#{@var_name}' already declared in this scope."
    end

    val_to_store = nil
    type_to_store = @var_type

    if @init_expr
      init_val, init_type = @init_expr.evaluate
      return [init_val, init_type] if init_val.is_a?(ReturnValue) # Should not happen in var decl expr

      # Type checking for declaration
      # Echo seems to allow `num n << get;` which means `get` (txt) can initialize `num`.
      # This implies some level of type coercion on assignment, or a more dynamic interpretation.
      # For now, let's be strict unless specific coercions are defined.
      # If @var_type is 'num' and init_type is 'txt', try to coerce
      if @var_type == "num" && init_type == "txt"
        coerced_val = init_val.to_s.match?(/\A-?\d+(\.\d+)?([eE][-+]?\d+)?\z/) ? init_val.to_f : nil
        if coerced_val.nil?
            raise StandardError, "Runtime Error: Cannot coerce txt '#{init_val}' to num for variable '#{@var_name}'."
        end
        init_val = coerced_val
        init_type = "num"
      elsif @var_type == "txt" && init_type != "txt" # Coerce anything to txt if var is txt
        init_val = value_to_echo_string(init_val, init_type)
        init_type = "txt"
      elsif @var_type == "bool" && init_type == "num" # 0 is false, others true
        init_val = (init_val != 0)
        init_type = "bool"
      elsif @var_type == "bool" && init_type == "txt" # "" is false, others true
        init_val = (!init_val.empty?)
        init_type = "bool"
      end

      if @var_type != "list" && @var_type != "obj" && # For primitives and non-collections
         init_type != @var_type
        raise StandardError, "Runtime Error: Type mismatch for variable '#{@var_name}'. Expected #{@var_type} but got #{init_type} from initializer."
      elsif (@var_type == "list" && init_type != "list") || (@var_type == "obj" && init_type != "obj")
         # Allow assigning any specific list/obj to a var of type list/obj
         # But don't allow assigning, say, a num to a list var.
         raise StandardError, "Runtime Error: Type mismatch for variable '#{@var_name}'. Expected #{@var_type} but got #{init_type}."
      end
      val_to_store = init_val
    else # Default initialization values if no initializer
      case @var_type
      when "num"    then val_to_store = 0
      when "txt"    then val_to_store = ""
      when "bool"   then val_to_store = false
      when "list"   then val_to_store = [] # Ruby array to hold [value, type] elements later
      when "obj"    then val_to_store = {} # Ruby hash
      # silent type variables are not really a thing
      end
    end

    Assignment.symbol_table.set(@var_name, { value: val_to_store, type: type_to_store, is_func: false })
    [nil, "silent"] # Variable declaration is a statement, doesn't yield a value
  end
end

class AssignmentNode < Node
  attr_accessor :lvalue, :expression
  def initialize(lvalue_node, expression_node)
    super()
    @lvalue = lvalue_node
    @expression = expression_node
    @children = [lvalue_node, expression_node]
  end

  def evaluate
    new_val, new_type = @expression.evaluate
    return [new_val, new_type] if new_val.is_a?(ReturnValue)

    if @lvalue.is_a?(Identifier)
      var_name = @lvalue.value
      var_info = Assignment.symbol_table.get(var_name) # Must exist
      raise StandardError, "Runtime Error: Cannot assign to '#{var_name}' because it's a function." if var_info[:is_func]

      declared_type = var_info[:type]
      # Type Coercion similar to VarDeclNode
      if declared_type == "num" && new_type == "txt"
        coerced_val = new_val.to_s.match?(/\A-?\d+(\.\d+)?([eE][-+]?\d+)?\z/) ? new_val.to_f : nil
        if coerced_val.nil?
            raise StandardError, "Runtime Error: Cannot coerce txt '#{new_val}' to num for assignment to '#{var_name}'."
        end
        new_val = coerced_val
        new_type = "num"
      elsif declared_type == "txt" && new_type != "txt"
        new_val = value_to_echo_string(new_val, new_type)
        new_type = "txt"
      elsif declared_type == "bool" && new_type == "num"
        new_val = (new_val != 0)
        new_type = "bool"
      elsif declared_type == "bool" && new_type == "txt"
        new_val = (!new_val.empty?)
        new_type = "bool"
      end

      if declared_type != "list" && declared_type != "obj" && new_type != declared_type
        raise StandardError, "Runtime Error: Type mismatch assigning to '#{var_name}'. Expected #{declared_type} but got #{new_type}."
      elsif (declared_type == "list" && new_type != "list") || (declared_type == "obj" && new_type != "obj")
        raise StandardError, "Runtime Error: Type mismatch assigning to '#{var_name}'. Expected collection type #{declared_type} but got #{new_type}."
      end

      Assignment.symbol_table.update(var_name, { value: new_val, type: declared_type, is_func: false })
      [new_val, declared_type]
    elsif @lvalue.is_a?(MemberAccessNode)
      obj_val, obj_type = @lvalue.object_expr.evaluate
      ensure_type(obj_val, obj_type, "obj", "Member assignment target")
      member_name = @lvalue.member_name.to_sym

      unless obj_val.key?(member_name) && obj_val[member_name].is_a?(Hash) && obj_val[member_name].key?(:type)
          raise StandardError, "Runtime Error: Member '#{member_name}' does not exist or is not properly structured in object."
      end
      member_declared_type = obj_val[member_name][:type]

      # Coercion for object members
      if member_declared_type == "num" && new_type == "txt"
        coerced_val = new_val.to_s.match?(/\A-?\d+(\.\d+)?([eE][-+]?\d+)?\z/) ? new_val.to_f : nil
        new_val = coerced_val if !coerced_val.nil?
        new_type = "num" if !coerced_val.nil?
      # Add other coercions if needed
      end
      
      if new_type != member_declared_type
        raise StandardError, "Runtime Error: Type mismatch for object member '#{member_name}'. Expected #{member_declared_type}, got #{new_type}."
      end
      obj_val[member_name][:value] = new_val
      [new_val, new_type] # Assignment expression returns the assigned value
    elsif @lvalue.is_a?(IndexAccessNode)
      collection_val, collection_type = @lvalue.collection_expr.evaluate
      index_val, index_type = @lvalue.index_expr.evaluate

      if collection_type == "list"
        ensure_type(index_val, index_type, "num", "List index")
        if index_val < 0 || index_val >= collection_val.length
          raise StandardError, "Runtime Error: List index #{index_val} out of bounds."
        end
        # For lists of [value, type], we'd need to know expected type of elements or be fully dynamic.
        # Echo lists are heterogeneous: [1, "a", true]. The stored value `collection_val` is already a Ruby array of actual values.
        # So, we just replace the value. Type of list elements isn't strictly enforced *within* the list by VarDecl.
        collection_val[index_val.to_i] = [new_val, new_type] # Store [value, type] in list
        [new_val, new_type]
      elsif collection_type == "obj" && index_type == "txt" # obj["key"] << val
         key_sym = index_val.to_sym
         unless collection_val.key?(key_sym) && collection_val[key_sym].is_a?(Hash) && collection_val[key_sym].key?(:type)
            raise StandardError, "Runtime Error: Key '#{index_val}' does not exist or is not properly structured for indexed assignment in object."
         end
         member_declared_type = collection_val[key_sym][:type]
         if new_type != member_declared_type
            raise StandardError, "Runtime Error: Type mismatch for object member '#{index_val}' (via index). Expected #{member_declared_type}, got #{new_type}."
         end
         collection_val[key_sym][:value] = new_val
         [new_val, new_type]
      else
        raise StandardError, "Runtime Error: Indexed assignment target must be a list (with num index) or obj (with txt index)."
      end
    else
      raise StandardError, "Runtime Error: Invalid lvalue for assignment."
    end
  end
end

class FuncDecNode < Node
  attr_accessor :func_name, :params, :return_type_str, :body
  def initialize(func_name, params_array, return_type_str, body_node)
    super(func_name)
    @func_name = func_name
    @params = params_array # Array of ParamNode(type_str, name_str)
    @return_type_str = return_type_str
    @body = body_node
    @children = [*params_array, body_node]
  end

  def evaluate
    # Store the function itself (this node) in the symbol table
    # along with its signature details.
    param_signatures = @params.map { |p| { name: p.param_name, type: p.param_type_str } }
    Assignment.symbol_table.set(@func_name, {
      value: self, # The AST node itself
      type: @return_type_str, # This is the return type
      is_func: true,
      params: param_signatures
    })
    [nil, "silent"] # Function declaration is a statement
  end
end

class ParamNode < Node # Helper for FuncDecNode, already defined. No evaluate.
  attr_accessor :param_type_str, :param_name
  def initialize(param_type_str, param_name)
    super(param_name)
    @param_type_str = param_type_str
    @param_name = param_name
  end
end

class FuncCallNode < Node
  attr_accessor :func_name_node, :args_exprs
  def initialize(func_name_node, args_exprs_array)
    # func_name_node is expected to be an IdentifierNode
    super(func_name_node.value) # Store func_name string in @value
    @func_name_node = func_name_node
    @args_exprs = args_exprs_array
    @children = args_exprs_array
  end

  def evaluate
    func_name = @func_name_node.value
    func_info = Assignment.symbol_table.get(func_name)

    unless func_info && func_info[:is_func]
      raise StandardError, "Runtime Error: '#{func_name}' is not a function or not declared."
    end

    func_dec_node = func_info[:value] # This is the FuncDecNode
    expected_params = func_info[:params] # Array of {name:, type:} hashes

    if @args_exprs.length != expected_params.length
      raise StandardError, "Runtime Error: Function '#{func_name}' expected #{expected_params.length} arguments, but got #{@args_exprs.length}."
    end

    # Evaluate arguments in the current scope
    evaluated_args = @args_exprs.map do |arg_expr|
      arg_val, arg_type = arg_expr.evaluate
      # Propagate return if an argument expression somehow contains a return. (Unlikely but defensive)
      return [arg_val, arg_type] if arg_val.is_a?(ReturnValue)
      [arg_val, arg_type]
    end

    # Create new scope for the function call
    old_symbol_table = Assignment.symbol_table
    Assignment.symbol_table = old_symbol_table.create_child_scope

    # Set parameters in the new scope with evaluated argument values
    expected_params.zip(evaluated_args).each_with_index do |(param_sig, (arg_val, arg_type)), i|
      if param_sig[:type] != arg_type
        # Add coercion for function arguments if Echo supports it, similar to assignment
        can_coerce = false
        if param_sig[:type] == "num" && arg_type == "txt"
            coerced_val = arg_val.to_s.match?(/\A-?\d+(\.\d+)?([eE][-+]?\d+)?\z/) ? arg_val.to_f : nil
            if !coerced_val.nil?
                arg_val = coerced_val
                arg_type = "num"
                can_coerce = true
            end
        elsif param_sig[:type] == "txt" # auto-coerce to txt
            arg_val = value_to_echo_string(arg_val, arg_type)
            arg_type = "txt"
            can_coerce = true
        end
        unless can_coerce || param_sig[:type] == arg_type # re-check after coercion
          Assignment.symbol_table = old_symbol_table # Restore before error
          raise StandardError, "Runtime Error: Type mismatch for argument #{i+1} ('#{param_sig[:name]}') in function '#{func_name}'. Expected #{param_sig[:type]}, got #{arg_type}."
        end
      end
      Assignment.symbol_table.set(param_sig[:name], { value: arg_val, type: param_sig[:type], is_func: false })
    end

    # Evaluate the function body in the new scope
    result_from_body = func_dec_node.body.evaluate

    Assignment.symbol_table = old_symbol_table # Restore scope

    expected_return_type = func_dec_node.return_type_str

    if result_from_body.is_a?(ReturnValue)
      actual_ret_val, actual_ret_type = result_from_body.value
      if expected_return_type == "silent" && !(actual_ret_val.nil? && actual_ret_type == "silent")
         raise StandardError, "Runtime Error: Function '#{func_name}' is silent and should not return an explicit value."
      end
      if expected_return_type != "silent" && actual_ret_type != expected_return_type
        # Coercion for return type
        if expected_return_type == "num" && actual_ret_type == "txt"
            coerced_val = actual_ret_val.to_s.match?(/\A-?\d+(\.\d+)?([eE][-+]?\d+)?\z/) ? actual_ret_val.to_f : nil
            if !coerced_val.nil?
                return [coerced_val, "num"]
            end
        elsif expected_return_type == "txt" # auto-coerce to txt
             return [value_to_echo_string(actual_ret_val, actual_ret_type), "txt"]
        end
        raise StandardError, "Runtime Error: Return type mismatch for function '#{func_name}'. Expected #{expected_return_type}, got #{actual_ret_type}."
      end
      return [actual_ret_val, actual_ret_type]
    else # Implicit return (result of last statement in the block)
      if expected_return_type != "silent"
        # If the block's natural result matches the expected type, allow it.
        implicit_val, implicit_type = result_from_body
        if implicit_type == expected_return_type
            return [implicit_val, implicit_type]
        end
        # Coercion for implicit return
        if expected_return_type == "num" && implicit_type == "txt"
            coerced_val = implicit_val.to_s.match?(/\A-?\d+(\.\d+)?([eE][-+]?\d+)?\z/) ? implicit_val.to_f : nil
            if !coerced_val.nil?
                return [coerced_val, "num"]
            end
        elsif expected_return_type == "txt"
             return [value_to_echo_string(implicit_val, implicit_type), "txt"]
        end

        raise StandardError, "Runtime Error: Function '#{func_name}' expected to return #{expected_return_type} but implicitly returned #{implicit_type} (or nothing if block was empty)."
      end
      return [nil, "silent"] # Implicit return for a silent function
    end
  end
end

class ReturnOpNode < Node
  def initialize(expression_node = nil)
    super()
    @children = [expression_node].compact
  end

  def evaluate
    if @children.empty? # Should ideally not happen if parser enforces expression for '>>'
      return ReturnValue.new([nil, "silent"])
    else
      val, type = @children[0].evaluate
      # If val itself is a ReturnValue (e.g. `>> (>> 5)`), unwrap it. This is unusual.
      if val.is_a?(ReturnValue)
          return val
      end
      return ReturnValue.new([val, type])
    end
  end
end

class IfNode < Node
  attr_accessor :condition, :if_block, :otif_clauses, :else_block
  def initialize(condition_node, if_block_node, otif_clauses = [], else_block_node = nil)
    super()
    @condition = condition_node
    @if_block = if_block_node
    @otif_clauses = otif_clauses
    @else_block = else_block_node
    @children = [condition_node, if_block_node, *otif_clauses, else_block_node].compact
  end

  def evaluate
    cond_val, cond_type = @condition.evaluate
    ensure_type(cond_val, cond_type, "bool", "If statement condition")

    result = [nil, "silent"] # Default result if no branch taken that returns a value

    old_symbol_table = Assignment.symbol_table
    Assignment.symbol_table = old_symbol_table.create_child_scope

    if cond_val
      result = @if_block.evaluate
    else
      otif_triggered = false
      @otif_clauses.each do |otif_node|
        otif_cond_val, otif_cond_type = otif_node.condition.evaluate
        ensure_type(otif_cond_val, otif_cond_type, "bool", "Otif statement condition")
        if otif_cond_val
          result = otif_node.block.evaluate
          otif_triggered = true
          break
        end
      end
      if !otif_triggered && @else_block
        result = @else_block.evaluate
      end
    end
    Assignment.symbol_table = old_symbol_table
    result # Propagate ReturnValue if present, or the block's natural result
  end
end

class OtifNode < Node # Helper for IfNode
  attr_accessor :condition, :block
  def initialize(condition_node, block_node)
    super()
    @condition = condition_node
    @block = block_node
    @children = [condition_node, block_node]
  end
  # Evaluation logic is handled by IfNode#evaluate
end


class LoopTimesNode < Node
  attr_accessor :count_expr, :block
  def initialize(count_expr_node, block_node)
    super()
    @count_expr = count_expr_node
    @block = block_node
    @children = [count_expr_node, block_node]
  end

  def evaluate
    count_val, count_type = @count_expr.evaluate
    ensure_type(count_val, count_type, "num", "Loop times count")
    raise StandardError, "Runtime Error: Loop count must be a non-negative integer." unless count_val >= 0 && count_val.to_i == count_val

    old_symbol_table = Assignment.symbol_table
    
    count_val.to_i.times do
      # Create a new scope for each iteration of the loop body block
      # This means variables declared inside loop don't persist across iterations in the same "slot"
      # but are fresh, though they can shadow outer scope.
      Assignment.symbol_table = old_symbol_table.create_child_scope
      eval_result = @block.evaluate
      Assignment.symbol_table = old_symbol_table # Restore to the loop's parent scope for next iteration's child
      return eval_result if eval_result.is_a?(ReturnValue) # Propagate return
    end
    # After loop, ensure the original symbol table is active
    Assignment.symbol_table = old_symbol_table
    [nil, "silent"] # Loop itself doesn't yield a value unless a return happens
  end
end

class LoopForEachNode < Node
  attr_accessor :item_var_name, :collection_expr, :block
  def initialize(item_var_name_str, collection_expr_node, block_node)
    super(item_var_name_str)
    @item_var_name = item_var_name_str
    @collection_expr = collection_expr_node
    @block = block_node
    @children = [collection_expr_node, block_node]
  end

  def evaluate
    collection_val, collection_type = @collection_expr.evaluate
    unless collection_type == "list" || collection_type == "txt" # Can iterate over list or txt (chars)
      raise StandardError, "Runtime Error: For-each loop target must be a list or txt, got #{collection_type}."
    end

    iterable = []
    if collection_type == "list"
      # collection_val is expected to be a Ruby array of [value, type] pairs
      iterable = collection_val
    elsif collection_type == "txt"
      # Iterate over characters of a string. Each char is a "txt".
      iterable = collection_val.chars.map { |char| [char, "txt"] }
    end

    old_symbol_table = Assignment.symbol_table

    iterable.each do |item_value_pair_or_char_pair|
      item_val, item_type = item_value_pair_or_char_pair

      # Create a new scope for each iteration for the item variable
      current_iter_scope = old_symbol_table.create_child_scope
      Assignment.symbol_table = current_iter_scope
      
      # Set the loop item variable in this new iteration scope
      # The type of item_var_name is inferred from the elements.
      Assignment.symbol_table.set(@item_var_name, { value: item_val, type: item_type, is_func: false })

      eval_result = @block.evaluate
      
      # Restore scope to the one active *before* this iteration's sub-scope was made.
      # This means variables declared inside the loop are local to that iteration's block.
      Assignment.symbol_table = old_symbol_table
      
      return eval_result if eval_result.is_a?(ReturnValue) # Propagate return
    end
    Assignment.symbol_table = old_symbol_table # Ensure restoration after loop
    [nil, "silent"]
  end
end


class ShowNode < Node
  def initialize(expression_node)
    super()
    @children = [expression_node]
  end
  def evaluate
    val_to_print, type = @children[0].evaluate
    return [val_to_print, type] if val_to_print.is_a?(ReturnValue)
    
    output_string = value_to_echo_string(val_to_print, type)
    Kernel.puts output_string
    [nil, "silent"] # show is a statement
  end
end

class GetNode < Node
  def initialize
    super()
  end
  def evaluate
    # In a real environment, this would read from actual stdin
    # For testing, you might redirect $stdin or mock this.
    input_str = $stdin.gets.chomp
    [input_str, "txt"]
  end
end

class BubbleNode < Node
  def initialize(block_node)
    super()
    @children = [block_node]
  end
  def evaluate
    old_symbol_table = Assignment.symbol_table
    # Create a completely isolated scope for 'bubble'
    Assignment.symbol_table = old_symbol_table.create_child_scope(isolated: true)

    eval_result = @children[0].evaluate # Evaluate the block

    Assignment.symbol_table = old_symbol_table # Restore original scope
    # Bubble's result is the result of its block, can propagate ReturnValue
    eval_result
  end
end

class TryOopsNode < Node
  attr_accessor :try_block, :oops_block
  def initialize(try_block_node, oops_block_node)
    super()
    @try_block = try_block_node
    @oops_block = oops_block_node
    @children = [try_block_node, oops_block_node]
  end

  def evaluate
    eval_result = [nil, "silent"]
    old_symbol_table = Assignment.symbol_table
    
    # Scope for try block
    Assignment.symbol_table = old_symbol_table.create_child_scope
    begin
      eval_result = @try_block.evaluate
    rescue StandardError, NameError, ZeroDivisionError => e # Catch typical runtime errors
      # puts "[DEBUG] Caught error in TRY: #{e.message}"
      Assignment.symbol_table = old_symbol_table # Restore before oops block
      Assignment.symbol_table = old_symbol_table.create_child_scope # New scope for oops block
      # Optionally, make error info available in oops_block's scope
      # Assignment.symbol_table.set("__error_message", {value: e.message, type: "txt", is_func: false})
      eval_result = @oops_block.evaluate
    ensure
      Assignment.symbol_table = old_symbol_table # Always restore scope
    end
    eval_result # Propagate ReturnValue if present
  end
end

class ListLiteralNode < Node
  def initialize(element_expr_nodes_array)
    super()
    @children = element_expr_nodes_array
  end
  def evaluate
    # Echo lists are heterogeneous. Each element is stored as [value, type].
    elements_with_types = @children.map do |expr_node|
      val, type = expr_node.evaluate
      # Propagate return if an element expression somehow contains a return.
      return ReturnValue.new([val,type]) if val.is_a?(ReturnValue) # This structure is a bit off for RV
      # ReturnValue should be checked and returned directly
      return val if val.is_a?(ReturnValue) 
      [val, type]
    end
    [elements_with_types, "list"]
  end
end

class ObjectLiteralNode < Node
  def initialize(member_assignment_nodes_array)
    super() # member_assignment_nodes_array contains VarDeclNode instances for "type key << value"
    @children = member_assignment_nodes_array
  end
  def evaluate
    obj_hash = {} # Ruby hash to represent the Echo object
    # Object literals create their own temporary scope for evaluating members
    # to avoid polluting the outer scope or prematurely resolving external variables
    # if keys were expressions (though Echo keys are identifiers here).
    # This isn't strictly necessary if all keys are plain identifiers and values are standard exprs.

    @children.each do |member_decl_node| # Each child is a VarDeclNode
      key_name = member_decl_node.var_name
      # The value for the key needs to be evaluated.
      # The VarDeclNode's init_expr is what holds the value expression.
      member_val, member_type = member_decl_node.init_expr.evaluate
      return [member_val, member_type] if member_val.is_a?(ReturnValue) # Propagate return

      # Type check against the declared type for the member in the object literal
      if member_decl_node.var_type != member_type
         # Add coercion here if needed, similar to VarDecl/Assignment
        raise StandardError, "Runtime Error: Type mismatch for object member '#{key_name}'. Declared as #{member_decl_node.var_type}, got #{member_type}."
      end
      obj_hash[key_name.to_sym] = { value: member_val, type: member_decl_node.var_type }
    end
    [obj_hash, "obj"]
  end
end

class MemberAccessNode < Node
  attr_accessor :object_expr, :member_name
  def initialize(object_expr_node, member_name_str)
    super(member_name_str)
    @object_expr = object_expr_node
    @member_name = member_name_str
    @children = [object_expr_node]
  end
  def evaluate
    obj_val, obj_type = @object_expr.evaluate
    return [obj_val, obj_type] if obj_val.is_a?(ReturnValue)

    ensure_type(obj_val, obj_type, "obj", "Member access target")
    member_sym = @member_name.to_sym

    unless obj_val.is_a?(Hash) && obj_val.key?(member_sym) && obj_val[member_sym].is_a?(Hash)
      raise StandardError, "Runtime Error: Member '#{@member_name}' not found or object not properly structured."
    end
    member_info = obj_val[member_sym]
    [member_info[:value], member_info[:type]]
  end
end

class IndexAccessNode < Node
  attr_accessor :collection_expr, :index_expr
  def initialize(collection_expr_node, index_expr_node)
    super()
    @collection_expr = collection_expr_node
    @index_expr = index_expr_node
    @children = [collection_expr_node, index_expr_node]
  end
  def evaluate
    collection_val, collection_type = @collection_expr.evaluate
    return [collection_val, collection_type] if collection_val.is_a?(ReturnValue)

    index_val, index_type = @index_expr.evaluate
    return [index_val, index_type] if index_val.is_a?(ReturnValue)

    if collection_type == "list"
      ensure_type(index_val, index_type, "num", "List index")
      idx = index_val.to_i
      # Collection_val for a list is an array of [value, type] pairs
      if idx < 0 || idx >= collection_val.length
        raise StandardError, "Runtime Error: List index #{idx} out of bounds (length #{collection_val.length})."
      end
      list_element_val, list_element_type = collection_val[idx]
      return [list_element_val, list_element_type]
    elsif collection_type == "obj"
      ensure_type(index_val, index_type, "txt", "Object key for indexed access")
      member_sym = index_val.to_sym
      unless collection_val.is_a?(Hash) && collection_val.key?(member_sym) && collection_val[member_sym].is_a?(Hash)
        raise StandardError, "Runtime Error: Key '#{index_val}' not found in object or object not properly structured."
      end
      member_info = collection_val[member_sym]
      return [member_info[:value], member_info[:type]]
    elsif collection_type == "txt" # String indexing
        ensure_type(index_val, index_type, "num", "String index")
        idx = index_val.to_i
        if idx < 0 || idx >= collection_val.length
            raise StandardError, "Runtime Error: String index #{idx} out of bounds (length #{collection_val.length})."
        end
        return [collection_val[idx], "txt"] # A character from the string
    else
      raise StandardError, "Runtime Error: Indexed access target must be a list, obj (with txt key), or txt (with num key). Got #{collection_type}."
    end
  end
end

$DEBUG = ENV['DEBUG']