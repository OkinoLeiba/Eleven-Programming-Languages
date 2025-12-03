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
  # TODO: debug all 
  sig{params:(num: Integer).return(String)}
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



  # roman_numerals(16)

  # Complete the solution so that it splits the string into pairs of two characters.
  # If the string contains an odd number of characters then it should replace the missing
  # second character of the final pair with an underscore ('_').
  #
  # Examples:
  #
  #  'abc' =>  ['ab', 'c_']
  #  'abcdef' => ['ab', 'cd', 'ef']

  sig{params:(str: String).return(Array[String])}
  def split_strings(str) 
    result = Array.new
    for i in 0..str.length
      result.push(str.slice(i,2).ljust(2, "_"))
    end
  end


# Create  function that returns the sum of the two lowest positive
# numbers given an array of minimum 4 positive integers.
# No floats or non - positive integers will be passed.
# For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.
# [10, 343445353, 3453445, 3453545353453] should return 3453455.

sig{params:(numbers: Array[Integer]).return(Integer)}
def sumTwoSmallestNumbers(numbers)
  numbers.sort!
  return numbers[0] + numbers[1]

end

ruby = Ruby.new
ruby(1666)