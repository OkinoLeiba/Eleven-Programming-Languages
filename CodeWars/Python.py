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
    result: list[str] = []
    for i in range(0, len(s), 2):
        a: str = s[i:i+2]
        if len(a) % 2 == 0:
            result.append(a)
        else:
            result.append(a+'_')
        
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

split_strings('abcde')