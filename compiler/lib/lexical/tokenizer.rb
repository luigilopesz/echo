require_relative "token"

class Tokenizer
  # Echo Language Operators & Delimiters
  OPERATORS = "+-*/<>!" # Single character operators
  MULTI_CHAR_OPERATORS = {
    "<<" => "ASSIGN",    # Assignment
    "++" => "CONCAT",    # Concatenation
    "==" => "EQ",        # Equality
    "!=" => "NEQ",       # Not Equal
    "<=" => "LTE",       # Less than or Equal
    ">=" => "GTE",       # Greater than or Equal
    "&&" => "AND",       # Logical AND
    "\\\\" => "OR",      # Logical OR (escaped backslash for Ruby string)
    ">>" => "RETURN_OP"  # Return operator
  }
  DELIMITERS = "(){}[];:.," # Dot is a separate operator for member access

  KEYWORDS = {
    "echo"   => "ECHO_KEYWORD",
    "show"   => "SHOW_KEYWORD",
    "get"    => "GET_KEYWORD", # 'get' is a keyword that resolves to an expression
    "if"     => "IF_KEYWORD",
    "otif"   => "OTIF_KEYWORD",
    "other"  => "OTHER_KEYWORD",
    "loop"   => "LOOP_KEYWORD",
    "times"  => "TIMES_KEYWORD",
    "bubble" => "BUBBLE_KEYWORD",
    "try"    => "TRY_KEYWORD",
    "oops"   => "OOPS_KEYWORD",
    "txt"    => "TYPE_TXT",
    "num"    => "TYPE_NUM",
    "bool"   => "TYPE_BOOL",
    "obj"    => "TYPE_OBJ",
    "list"   => "TYPE_LIST",
    "silent" => "TYPE_SILENT",
    "true"   => "BOOL_LITERAL",
    "false"  => "BOOL_LITERAL"
  }

  # Separate token types for single characters that can also be part of multi-char ops
  SINGLE_CHAR_TOKEN_TYPES = {
    '+' => "PLUS",
    '-' => "MINUS",
    '*' => "MUL",
    '/' => "DIV",
    '<' => "LT",
    '>' => "GT",
    '!' => "NOT", # Logical NOT, different from NEQ
    '.' => "DOT", # Member access
    '(' => "LPAREN",
    ')' => "RPAREN",
    '{' => "LBRACE",
    '}' => "RBRACE",
    '[' => "LBRACKET",
    ']' => "RBRACKET",
    ';' => "SEMI",
    ':' => "COLON",
    ',' => "COMMA"
  }


  attr_accessor :code, :pos

  def initialize(code)
    @code = code
    @pos = 0
    @tokens = []
  end

  def peek(offset = 0)
    return nil if (@pos + offset) >= @code.size
    @code[@pos + offset]
  end

  def current_char
    peek(0)
  end

  def advance(count = 1)
    @pos += count
  end

  def eof?
    @pos >= @code.size
  end

  def wspace?(char)
    char =~ /\s/
  end

  def number_start?(char)
    char =~ /[0-9]/
  end

  def identifier_start?(char)
    char =~ /[a-zA-Z_]/
  end

  def identifier_char?(char)
    char =~ /[a-zA-Z0-9_]/
  end

  def tokenize_number
    number_str = ""
    is_float = false
    while !eof? && (number_start?(current_char) || (current_char == '.' && !is_float && number_start?(peek(1))) || (current_char =~ /[eE]/ && (peek(1) == '-' || peek(1) == '+' || number_start?(peek(1)))))
      char_to_add = current_char
      if char_to_add == '.'
        is_float = true
      elsif char_to_add =~ /[eE]/
        is_float = true # Scientific notation implies float
        number_str << char_to_add
        advance
        if !eof? && (current_char == '-' || current_char == '+')
          number_str << current_char
          advance
        end
        next # Continue to grab digits after e/E+/-
      end
      number_str << char_to_add
      advance
    end
    @tokens << Token.new(is_float ? "NUM_LITERAL" : "NUM_LITERAL", is_float ? number_str.to_f : number_str.to_i)
  end

  def tokenize_identifier_or_keyword
    ident_str = ""
    while !eof? && identifier_char?(current_char)
      ident_str << current_char
      advance
    end

    if KEYWORDS.key?(ident_str)
      token_type = KEYWORDS[ident_str]
      if ident_str == "true"
        @tokens << Token.new(token_type, true)
      elsif ident_str == "false"
        @tokens << Token.new(token_type, false)
      else
        @tokens << Token.new(token_type, ident_str)
      end
    else
      @tokens << Token.new("IDENTIFIER", ident_str)
    end
  end

  def tokenize_string
    string_value = ""
    advance # Consume the opening quote "

    while !eof? && current_char != '"'
      if current_char == '\\' # Handle escape sequences
        advance
        case current_char
        when 'n' then string_value << "\n"
        when 't' then string_value << "\t"
        when '\\' then string_value << "\\"
        when '"' then string_value << "\""
        else # Unknown escape sequence, treat as literal backslash and char
          string_value << "\\"
          string_value << current_char
        end
      else
        string_value << current_char
      end
      advance
    end

    if eof? || current_char != '"'
      raise "Unterminated string literal"
    end
    advance # Consume the closing quote "
    @tokens << Token.new("TXT_LITERAL", string_value)
  end

  def tokenize
    while !eof?
      char = current_char

      if wspace?(char)
        advance
        next
      end

      # Try matching multi-character operators first
      matched_multi = false
      MULTI_CHAR_OPERATORS.keys.sort_by(&:length).reverse.each do |op_key|
        op_len = op_key.length
        if @code[@pos, op_len] == op_key
          @tokens << Token.new(MULTI_CHAR_OPERATORS[op_key], op_key)
          advance(op_len)
          matched_multi = true
          break
        end
      end
      next if matched_multi

      # Single character operators and delimiters
      if SINGLE_CHAR_TOKEN_TYPES.key?(char)
        @tokens << Token.new(SINGLE_CHAR_TOKEN_TYPES[char], char)
        advance
        next
      end

      if char == '"'
        tokenize_string
        next
      end

      if number_start?(char)
        tokenize_number
        next
      end

      if identifier_start?(char)
        tokenize_identifier_or_keyword
        next
      end

      raise "Lexical Error: Invalid character '#{char}' at position #{@pos}"
    end

    @tokens << Token.new("EOF", "")
    @tokens
  end
end