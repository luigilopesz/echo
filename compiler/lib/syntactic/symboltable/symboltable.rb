class SymbolTable
  attr_reader :parent

  def initialize(parent = nil)
    @table = {}
    @parent = parent # Reference to the parent scope (for lexical scoping)
  end

  # Sets information for an identifier in the current scope.
  # For Echo, 'value_info' is expected to be a hash, e.g.:
  # {
  #   value: actual_runtime_value, (e.g., 10, "hello", true, a Ruby array for lists, a Ruby hash for objects)
  #   type: type_string,           (e.g., "num", "txt", "bool", "list", "obj", "silent", or function return type)
  #   is_func: boolean,            (true if it's a function declaration, false for variables)
  #   params: array_of_param_nodes (for functions, [{type: "num", name: "x"}, ...]) (optional, only for functions)
  #   # Potentially other metadata if needed
  # }
  def set(name, value_info)
    @table[name.to_sym] = value_info
  end

  # Gets information for an identifier.
  # Traverses up the scope chain if not found locally.
  def get(name)
    key = name.to_sym
    if @table.key?(key)
      return @table[key]
    elsif @parent
      return @parent.get(name) # Pass the original name (string or symbol)
    else
      raise NameError, "Identifier '#{name}' not declared in any accessible scope."
    end
  end

  # Updates information for an already declared identifier.
  # Traverses up the scope chain to find the identifier.
  def update(name, new_value_info)
    key = name.to_sym
    if @table.key?(key)
      # It's good practice to ensure the type doesn't change on simple updates,
      # or that the update is compatible with the existing declaration.
      # This check might happen before calling update, or here.
      # For now, it just updates. The type consistency will be handled by AST evaluate methods.
      @table[key] = new_value_info
    elsif @parent
      @parent.update(name, new_value_info) # Pass the original name
    else
      raise NameError, "Identifier '#{name}' not declared for update in any accessible scope."
    end
  end

  # Checks if an identifier is declared in the *current* (local) scope.
  def is_declared_locally?(name)
    @table.key?(name.to_sym)
  end

  # Utility to create a new child scope (e.g., for blocks, functions)
  def create_child_scope(isolated: false)
    if isolated # For 'bubble' scopes that don't inherit from parent
      SymbolTable.new(nil)
    else
      SymbolTable.new(self)
    end
  end

end