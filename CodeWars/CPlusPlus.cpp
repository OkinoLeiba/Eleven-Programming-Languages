#include <string>
#include <map>
#include <vector>

// Create a function taking a positive integer between 1 and 3999 (both included) as its parameter
// and returning a string containing the Roman Numeral representation of that integer.

// Modern Roman numerals are written by expressing each digit separately starting with the leftmost digit
// and skipping any digit with a value of zero. There cannot be more than 3 identical symbols in a row.

// In Roman numerals:

// 1990 is rendered: 1000=M + 900=CM + 90=XC; resulting in MCMXC.
// 2008 is written as 2000=MM, 8=VIII; or MMVIII.
// 1666 uses each Roman symbol in descending order: MDCLXVI.
// Example:

// 1 -->       "I"
// 1000 -->       "M"
// 1666 --> "MDCLXVI"

// {'M', 1000},
// {'D', 500},
// {'C', 100},
// {'L', 50},
// {'X', 10},
// {'V', 5},
// {'I', 1},
std::string roman_numerals(int number)
{
    // convert the number to a roman numeral
    const std::vector<std::pair<int, std::string>> roman_table = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}};

    std::string result;
    for (const auto &entry : roman_table)
    {
        while (number >= entry.first)
        {
            result += entry.second;
            number -= entry.first;
        }
    }
    return result;
}

// Complete the solution so that it splits the string into pairs of two characters.
// If the string contains an odd number of characters then it should replace the missing
// second character of the final pair with an underscore ('_').
//
// Examples:
//
//  'abc' =>  ['ab', 'c_']
//  'abcdef' => ['ab', 'cd', 'ef']

std::vector<std::string> split_strings(const std::string &s)
{
    // Base Case : string of length one or two
    // Approach One : determine length which determines algorithm
    // Approach Two : create substrs eliminating two first strings then
    // use substr length to determine last step
    std::vector<std::string> result;
    // for (int i = 0; i < s.size(); i += 2)
    // {
    // std::string a = s.substr(i, 2);
    // if (a[1] == '\0')
    // {
    // a.append("_");
    // }
    // result.push_back(a);
    // }
    s.size() % 2 == 0 ? s : s + '_';
    std::string pb;
    for (const auto &sub : s)
    {
        pb.push_back(sub);
        if (pb.size() == 2)
        {
            result.push_back(pb);
            pb.erase(0, 2);
        }
    }
    // for (int i = 0; i < s.size(); i += 2)
    // {
    // result.push_back(s.substr(i, 2));
    // }

    return result;
}

/********************* Main ******************/
int main(void)
{
    // roman_numerals(1000);
    split_strings("abcde");
}