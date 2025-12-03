# Create a function taking a positive integer between 1 and 3999 (both included) as its parameter and returning a string containing the Roman Numeral representation of that integer.

# Modern Roman numerals are written by expressing each digit separately starting with the leftmost digit and skipping any digit with a value of zero. There cannot be more than 3 identical symbols in a row.

# In Roman numerals:

# 1990 is rendered: 1000=M + 900=CM + 90=XC; resulting in MCMXC.
# 2008 is written as 2000=MM, 8=VIII; or MMVIII.
# 1666 uses each Roman symbol in descending order: MDCLXVI.
# Example:

# 1 -->       "I"
# 1000 -->       "M"
# 1666 --> "MDCLXVI"


def roman_numerals(number: int) -> str:
    roman_table: dict[int, str] = {
        1000: 'M',
        900: 'CM',
        500: 'D',
        400: 'CD',
        100: 'C',
        90: 'XC',
        50: 'L',
        40: 'XL',
        10: 'X',
        9: 'IX',
        5: 'V',
        4: 'IV',
        1: 'I'
    }
    result: str = ''
    while number > 0:
        for k,v in roman_table.items():
            if k <= number:
                count: int = number # k
                number  -= (count * k)
                result = result + v
            
    return result


# roman_numerals(16)

# Complete the solution so that it splits the string into pairs of two characters.
# If the string contains an odd number of characters then it should replace the missing
# second character of the final pair with an underscore ('_').
#
# Examples:
#
#  'abc' =>  ['ab', 'c_']
#  'abcdef' => ['ab', 'cd', 'ef']


def split_strings(s: str) -> list[str]:
    # Simple loop with slice (current approach, works)
    # result: list[str] = []
    # for i in range(0, len(s), 2):
        # a: str = s[i:i+2]
        # if len(a) % 2 == 0:
            # result.append(a)
        # else:
            # result.append(a+'_')
        # 
    #  return result
    
    # List comprehension + conditional
    # return [s[i:i+2] if len(s[i:i+2]) == 2 else s[i:i+2]+'_' for i in range(0, len(s), 2)]

    # List comprehension with ljust (pad right to width 2)
    return [s[i:i+2].ljust(2, '_') for i in range(0, len(s), 2)]

    # Zip pairs + padding
    # padding: str = s if len(s) % 2 == 0 else s + '_'
    # return [''.join(pair) for pair in zip(padding[::2], padding[1::2])]

    # Regex 
    # import re
    # return re.findall('..?', s.ljust(len(s)+len(s) % 2, '_'))


# split_strings('abcde')

# Create  function that returns the sum of the two lowest positive
# numbers given an array of minimum 4 positive integers.
# No floats or non - positive integers will be passed.
# For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.
# [10, 343445353, 3453445, 3453545353453] should return 3453455.

def sumTwoSmallestNumbers(numbers: list[int]) -> int:  
    # TODO: debug and learn
    # Merge Sort Algorithm 
    def merge_sort(merge_list: list[int]):
        if len(merge_list) > 1: 
            mid = len(merge_list)//2
            left_half = merge_list[:mid]
            right_half = merge_list[mid:]

            merge_sort(left_half)
            merge_sort(right_half)

            i = j = k = 0
    
            while i < len(left_half) and j < len(right_half):
                if left_half[i] < right_half[j]:
                    merge_list[k] = left_half[i]                
                    i += 1
                else:
                    merge_list[k] = right_half[j]
                    j += 1
                k += 1

            while i < len(left_half):
                merge_list[k] = left_half[i]
                i += 1
                k += 1
    
            while j < len(right_half):
                merge_list[k] = right_half[j]
                j += 1
                k += 1

    numbers.sort()
    merge_sort(numbers)
    return numbers[0] + numbers[1]

sumTwoSmallestNumbers([35,22,90,4,50,20,30,40,1])
