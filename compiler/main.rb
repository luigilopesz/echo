require "debug"
require_relative "lib/prepross/prepross"
require_relative "lib/lexical/tokenizer"
require_relative "lib/syntactic/parser"


require_relative "lib/syntactic/AST/ast_nodes"


module Main
  class << self
    def compile(file_path)
      begin
        code = prepross(file_path)
        
        tokens = tokenizing(code)

        ast_root_node = parsing(tokens)

        interpreting(ast_root_node)


      rescue StandardError, NameError, ZeroDivisionError => e
        puts "\n!! COMPILER ERROR !!"
        puts "Error Type: #{e.class}"
        puts "Message: #{e.message}"
        puts "Backtrace:\n#{e.backtrace.join("\n  ")}"
        exit 1 # Exit with an error code
      end
    end

    def prepross(file_path)

      preprocessor = PrePross.new(file_path, "//")
      preprocessor.remove_comments
    end

    def tokenizing(code)
      tokenizer = Tokenizer.new(code) # Uses the updated Echo Tokenizer
      tokenizer.tokenize
    end

    def parsing(tokens)
      parser = Parser.new(tokens) # Uses the updated Echo Parser
      parser.parse_program # Returns the root AST node (likely a BinOp('BLOCK', ...))
    end

    def interpreting(node)

      Assignment.symbol_table = SymbolTable.new # Global root scope




      node.evaluate # Evaluate the entire program AST



    end
  end
end

if __FILE__ == $0
  if ARGV.empty?
    puts "Echo Language Compiler"
    puts "Usage: ruby echo/compiler/main.rb <file_path.echo>"
    exit
  end

  file_path = ARGV.join(" ") # Allows file paths with spaces if quoted

  Main.compile(file_path)
end