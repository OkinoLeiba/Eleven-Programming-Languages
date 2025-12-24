#!/usr/bin/ruby
require "sorbet-runtime.rb"

class Ruby 
  # Create a function taking a positive integer between 1 and 3999 (both
  # included) as its parameter
  # and returning a string containing the Roman Numeral representation of that
  # integer.

  # Modern Roman numerals are written by expressing each digit separately
  # starting with the leftmost digit
  # and skipping any digit with a value of zero. There cannot be more than 3
  # identical symbols in a row.

  # In Roman numerals:

  # 1990 is rendered: 1000=M + 900=CM + 90=XC; resulting in MCMXC.
  # 2008 is written as 2000=MM, 8=VIII; or MMVIII.
  # 1666 uses each Roman symbol in descending order: MDCLXVI.
  # Example:

  # 1 --> "I"
  # 1000 --> "M"
  # 1666 --> "MDCLXVI"

  # {'M', 1000},
  # {'D', 500},
  # {'C', 100},
  # {'L', 50},
  # {'X', 10},
  # {'V', 5},
  # {'I', 1},

  # sig{params:(num: Integer).return(String)}
  def roman_numerals(num)
    result = String.new
    roman_table = Hash.new(
        1000 => "M",
        900 =>  "CM",
        500 =>  "D",
        400 =>  "CD",
        100 =>  "C",
        90 =>   "XC",
        50 =>   "L",
        40 =>   "XL",
        10 =>   "X",
        9 =>    "IX",
        5 =>    "V",
        4 =>    "IV",
        1 =>    "I",
    )

    roman_table.each do |key, value|
      if key <= num 
        count = num / key
        (0..i).each do |n| 
          result.prepend(value)
        end
        num -= count * key 
      end
    end
    return result
  end

end

ruby = Ruby.new
ruby(1666)