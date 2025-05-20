

class Node
  attr_accessor :value, :children

  def initialize(value = nil, children = [])
    @value = value
    @children = children
  end

  def evaluate
    raise NotImplementedError, "Subclasse precisa implementar evaluate"
  end
end
