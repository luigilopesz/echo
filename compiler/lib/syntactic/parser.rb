require_relative "AST/node"
require_relative "AST/ast_nodes"
# SymbolTable might be used for semantic checks during parsing in a more advanced version
# require_relative "symboltable/symboltable"

class Parser
  def initialize(tokens)
    @tokens = tokens # Array of Token objects, with EOF at the end
    @pos = 0
    # Operator precedence: lower number = higher precedence
    @precedence = {
      "OR"     => 1, # \\ (logical OR)
      "AND"    => 2, # &&
      "EQ"     => 3, # ==
      "NEQ"    => 3, # !=
      "LT"     => 4, # <
      "GT"     => 4, # >
      "LTE"    => 4, # <=
      "GTE"    => 4, # >=
      "CONCAT" => 5, # ++
      "PLUS"   => 6, # +
      "MINUS"  => 6, # - (binary)
      "MUL"    => 7, # *
      "DIV"    => 7, # /
    }
  end

  def peek(offset = 0)
    lookahead_pos = @pos + offset
    return @tokens.last if lookahead_pos >= @tokens.length # Fallback to EOF
    @tokens[lookahead_pos]
  end

  def current_token
    peek(0)
  end

  def consume(expected_type = nil, expected_value = nil)
    token = @tokens[@pos]

    if token.nil? || (token.type == "EOF" && (expected_type != "EOF" && !expected_type.nil?))
      if expected_type && expected_type != "EOF"
        raise "Parse Error: Unexpected end of input. Expected #{expected_type}."
      elsif token.nil? && expected_type != "EOF"
        raise "Parse Error: Unexpected end of token stream (nil token). Expected #{expected_type || 'any token'}."
      end
    end

    if token.type == "EOF" && expected_type && expected_type != "EOF"
        raise "Parse Error: Unexpected end of input. Expected token type #{expected_type} but got EOF."
    end


    if expected_type && token.type != expected_type
      raise "Parse Error: Expected token type #{expected_type} but got #{token.type} ('#{token.value}') at position #{@pos}. Next: #{peek(1)&.type}"
    end
    if expected_value && token.value != expected_value
      raise "ParseError: Expected value '#{expected_value}' for type #{token.type}, but got '#{token.value}' at position #{@pos}"
    end

    @pos += 1 if @pos < @tokens.length
    token
  end

  def parse_program
    statements = []
    while current_token.type != 'EOF'
      statements << parse_declaration
    end
    BinOp.new('BLOCK', statements)
  end

  def parse_declaration
    token_type = current_token.type
    case token_type
    when "ECHO_KEYWORD"
      parse_func_definition # Semicolon handled by func_definition or not needed if it's a block
    when "TYPE_TXT", "TYPE_NUM", "TYPE_BOOL", "TYPE_OBJ", "TYPE_LIST", "TYPE_SILENT"
      node = parse_variable_declaration # This will now consume its own semicolon
      # consume("SEMI", ";") # Semicolon is now consumed by parse_variable_declaration
      node
    when "IDENTIFIER"
      # Look ahead to distinguish reassignment, member/index based lvalue assignment, or function call statement
      # This logic needs to correctly identify the start of an lvalue for assignment
      # or a function call.
      # If it's `ID << ...` or `ID.member << ...` or `ID[index] << ...` it's an assignment.
      # If it's `ID(...)` it's a function call.
      
      # Try parsing as a potential lvalue first for assignment context
      # This is a bit complex because parse_lvalue itself consumes tokens.
      # We might need a way to "peek" further or backtrack if it's not an assignment.
      # For now, let's assume if it starts like an expression that could be an lvalue,
      # and is followed by ASSIGN, it's a reassignment. Otherwise, it's an expression statement.

      if is_start_of_lvalue_followed_by_assign?
        node = parse_reassignment
        consume("SEMI", ";")
        node
      else # Assume it's an expression statement (e.g., function call)
        expr_node = parse_expression
        consume("SEMI", ";")
        expr_node
      end

    when "IF_KEYWORD"
      parse_if_statement # Semicolon not typically after block structures
    when "LOOP_KEYWORD"
      parse_loop_statement # Semicolon not typically after block structures
    when "SHOW_KEYWORD"
      node = parse_show_statement
      consume("SEMI", ";")
      node
    when "RETURN_OP"
      node = parse_return_statement
      consume("SEMI", ";")
      node
    when "BUBBLE_KEYWORD"
      parse_bubble_statement # Semicolon not typically after block structures
    when "TRY_KEYWORD"
      parse_try_oops_statement # Semicolon not typically after block structures
    when "LBRACE"
      parse_block # Semicolon not typically after block structures
    when "SEMI"
      consume("SEMI")
      NoOp.new
    else
      begin
        expr = parse_expression
        consume("SEMI", ";")
        return expr
      rescue StandardError => e
        raise "Parse Error: Invalid start of a declaration or statement. Unexpected token '#{current_token.value}' of type '#{current_token.type}'. Original error: #{e.message}"
      end
    end
  end
  
  # Helper to check if the current sequence looks like `lvalue <<`
  def is_start_of_lvalue_followed_by_assign?
    # This is a simplified check. A proper way might involve trying to parse an lvalue
    # without consuming tokens, or having parse_expression be able to return a specific
    # "potential_lvalue" type.
    # For now, check if it's an IDENTIFIER and the *next* significant token is ASSIGN,
    # or if it's an IDENTIFIER followed by DOT/LBRACKET sequence then ASSIGN.
    # This lookahead can get complex.
    i = 0
    # Skip potential ID, .ID, [EXPR]
    if peek(i)&.type == "IDENTIFIER"
      i += 1
      while peek(i)&.type == "DOT" || peek(i)&.type == "LBRACKET"
        if peek(i)&.type == "DOT"
          i += 1 # DOT
          return false if peek(i)&.type != "IDENTIFIER"
          i += 1 # IDENTIFIER
        elsif peek(i)&.type == "LBRACKET"
          i += 1 # LBRACKET
          # Skip tokens until matching RBRACKET - this is too complex for a simple lookahead
          # For simplicity, just assume if it starts with ID and has LBRACKET, it could be an lvalue.
          # A more robust solution would be to attempt parsing an lvalue.
          # For now, let's rely on the structure of parse_reassignment.
          # A simple check: if it's an identifier and next is assign, it's likely.
          # If it's identifier then dot/lbracket, it's complex.
          # Let's refine parse_declaration's IDENTIFIER case.
          return true # Heuristic: if it starts with ID and has these, it might be assignable
        end
      end
      return peek(i)&.type == "ASSIGN"
    end
    false
  end


  def parse_type_name
    token = current_token
    case token.type
    when "TYPE_TXT" then consume("TYPE_TXT"); "txt"
    when "TYPE_NUM" then consume("TYPE_NUM"); "num"
    when "TYPE_BOOL" then consume("TYPE_BOOL"); "bool"
    when "TYPE_OBJ" then consume("TYPE_OBJ"); "obj"
    when "TYPE_LIST" then consume("TYPE_LIST"); "list"
    when "TYPE_SILENT" then consume("TYPE_SILENT"); "silent"
    else
      raise "Parse Error: Expected a type name (txt, num, bool, obj, list, silent), got #{token.type}"
    end
  end

  def parse_variable_declaration
    type_str = parse_type_name
    id_token = consume("IDENTIFIER")
    expr_node = nil
    if current_token.type == "ASSIGN" # Check if there's an initializer
      consume("ASSIGN", "<<")
      expr_node = parse_expression
    end
    # Semicolon is consumed here, after the optional initializer
    consume("SEMI", ";")
    VarDeclNode.new(id_token.value, type_str, expr_node)
  end

  def parse_reassignment
    lvalue_node = parse_lvalue
    consume("ASSIGN", "<<")
    expr_node = parse_expression
    # Semicolon for reassignment statements is consumed in parse_declaration
    AssignmentNode.new(lvalue_node, expr_node)
  end

  def parse_lvalue
    expr = parse_primary_expression

    loop do
      if current_token.type == "DOT"
        consume("DOT")
        member_token = consume("IDENTIFIER")
        expr = MemberAccessNode.new(expr, member_token.value)
      elsif current_token.type == "LBRACKET"
        consume("LBRACKET")
        index_expr = parse_expression
        consume("RBRACKET")
        expr = IndexAccessNode.new(expr, index_expr)
      else
        break
      end
    end

    unless expr.is_a?(Identifier) || expr.is_a?(MemberAccessNode) || expr.is_a?(IndexAccessNode)
      raise "Parse Error: Invalid left-hand side in assignment. Found #{expr.class}."
    end
    expr
  end


  def parse_func_definition
    consume("ECHO_KEYWORD")
    return_type_str = parse_type_name
    func_name_token = consume("IDENTIFIER")
    consume("LPAREN", "(")
    params = []
    if current_token.type != "RPAREN"
      loop do
        param_type_str = parse_type_name
        param_name_token = consume("IDENTIFIER")
        params << ParamNode.new(param_type_str, param_name_token.value)
        break unless current_token.type == "COMMA"
        consume("COMMA")
      end
    end
    consume("RPAREN", ")")
    body_node = parse_block
    FuncDecNode.new(func_name_token.value, params, return_type_str, body_node)
  end

  def parse_block
    consume("LBRACE", "{")
    statements = []
    while current_token.type != "RBRACE" && current_token.type != "EOF"
      statements << parse_declaration
    end
    consume("RBRACE", "}")
    BinOp.new('BLOCK', statements)
  end

  def parse_if_statement
    consume("IF_KEYWORD")
    consume("ASSIGN", "<<")
    condition = parse_expression
    if_block = parse_block

    otif_clauses = []
    while current_token.type == "OTIF_KEYWORD"
      consume("OTIF_KEYWORD")
      consume("ASSIGN", "<<")
      otif_condition = parse_expression
      otif_block = parse_block
      otif_clauses << OtifNode.new(otif_condition, otif_block)
    end

    else_block = nil
    if current_token.type == "OTHER_KEYWORD"
      consume("OTHER_KEYWORD")
      else_block = parse_block
    end
    IfNode.new(condition, if_block, otif_clauses, else_block)
  end

  def parse_loop_statement
    consume("LOOP_KEYWORD")
    consume("ASSIGN", "<<")

    if current_token.type == "IDENTIFIER" && peek(1)&.type == "COLON"
      item_var_token = consume("IDENTIFIER")
      consume("COLON")
      collection_expr = parse_expression
      body = parse_block
      LoopForEachNode.new(item_var_token.value, collection_expr, body)
    else
      count_expr = parse_expression
      consume("TIMES_KEYWORD")
      body = parse_block
      LoopTimesNode.new(count_expr, body)
    end
  end

  def parse_show_statement
    consume("SHOW_KEYWORD")
    consume("ASSIGN", "<<")
    expression = parse_expression
    ShowNode.new(expression)
  end

  def parse_return_statement
    consume("RETURN_OP", ">>")
    expression = parse_expression # Assuming return always has an expression, even if it's just for "silent"
    ReturnOpNode.new(expression)
  end

  def parse_bubble_statement
    consume("BUBBLE_KEYWORD")
    block = parse_block
    BubbleNode.new(block)
  end

  def parse_try_oops_statement
    consume("TRY_KEYWORD")
    try_block = parse_block
    consume("OOPS_KEYWORD")
    oops_block = parse_block
    TryOopsNode.new(try_block, oops_block)
  end

  def parse_expression(min_precedence = 0)
    left_expr = parse_primary_or_accessor_expression

    while current_token.type != "EOF"
      token = current_token
      
      break unless ["PLUS", "MINUS", "MUL", "DIV", "CONCAT", "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "AND", "OR"].include?(token.type)
      
      precedence = @precedence[token.type]
      break if precedence.nil? || precedence < min_precedence

      consume(token.type)
      right_expr = parse_expression(precedence + 1) # Standard for left-associativity
      left_expr = BinOp.new(token.value, [left_expr, right_expr])
    end
    left_expr
  end
  
  def parse_primary_or_accessor_expression
    expr = parse_unary_expression

    loop do
      if current_token.type == "LPAREN"
         unless expr.is_a?(Identifier) || expr.is_a?(MemberAccessNode)
            # If 'expr' is not an identifier or member access, it cannot be directly called.
            # This could be a situation like (1+2)(args) which is invalid,
            # or it could be that the LPAREN is part of a different construct.
            # For now, we break, assuming direct calls are on ID or ID.member
            break 
        end
        consume("LPAREN")
        args = []
        if current_token.type != "RPAREN"
          loop do
            args << parse_expression
            break unless current_token.type == "COMMA"
            consume("COMMA")
          end
        end
        consume("RPAREN")
        expr = FuncCallNode.new(expr, args)
      elsif current_token.type == "DOT"
        consume("DOT")
        member_token = consume("IDENTIFIER")
        expr = MemberAccessNode.new(expr, member_token.value)
      elsif current_token.type == "LBRACKET"
        consume("LBRACKET")
        index_expr = parse_expression
        consume("RBRACKET")
        expr = IndexAccessNode.new(expr, index_expr)
      else
        break
      end
    end
    expr
  end
  
  def parse_unary_expression
    if ["NOT", "MINUS"].include?(current_token.type)
      op_token = consume(current_token.type)
      operand = parse_unary_expression
      return UnOp.new(op_token.value, [operand])
    else
      parse_primary_expression
    end
  end

  def parse_primary_expression
    token = current_token
    case token.type
    when "NUM_LITERAL"
      consume("NUM_LITERAL")
      NumVal.new(token.value)
    when "TXT_LITERAL"
      consume("TXT_LITERAL")
      TxtVal.new(token.value)
    when "BOOL_LITERAL"
      consume("BOOL_LITERAL")
      BoolVal.new(token.value)
    when "IDENTIFIER"
      consume("IDENTIFIER")
      Identifier.new(token.value)
    when "GET_KEYWORD"
      consume("GET_KEYWORD")
      GetNode.new
    when "LPAREN"
      consume("LPAREN")
      expr = parse_expression
      consume("RPAREN")
      expr
    when "LBRACKET"
      parse_list_literal
    when "LBRACE"
      parse_object_literal
    else
      raise "Parse Error: Unexpected token in primary expression: '#{token.value}' of type '#{token.type}'"
    end
  end

  def parse_list_literal
    consume("LBRACKET")
    elements = []
    if current_token.type != "RBRACKET"
      loop do
        elements << parse_expression
        break unless current_token.type == "COMMA"
        consume("COMMA")
      end
    end
    consume("RBRACKET")
    ListLiteralNode.new(elements)
  end

  def parse_object_literal
    consume("LBRACE")
    members = []
    if current_token.type != "RBRACE"
      loop do
        member_type_str = parse_type_name
        member_key_token = consume("IDENTIFIER")
        consume("ASSIGN", "<<")
        member_value_expr = parse_expression
        members << VarDeclNode.new(member_key_token.value, member_type_str, member_value_expr)

        break unless current_token.type == "SEMI"
        consume("SEMI")
        break if current_token.type == "RBRACE"
      end
    end
    consume("RBRACE")
    ObjectLiteralNode.new(members)
  end
end
