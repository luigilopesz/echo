class PrePross
  attr_accessor :code

  def initialize(file_path, comment)
    @file_path = file_path
    @comment = comment
  end

  def remove_comments()
    processed_lines = []
    File.foreach(@file_path) do |line|
      cleaned_line = line.split("#{@comment}").first.rstrip
      processed_lines << cleaned_line
    end
    processed_lines.join("\n")
  end
end