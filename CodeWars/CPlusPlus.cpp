#include <string>
#include <map>
#include <vector>
#include <algorithm>

// Create  function taking  positive integer between 1 and 3999 (both included) as its parameter
// and returning  string containing the Roman Numeral representation of that integer.

// Modern Roman numerals are written by expressing each digit separately starting with the leftmost digit
// and skipping any digit with  value of zero. There cannot be more than 3 identical symbols in  row.

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
    // Base Case: no base case
    // Largest roman value is 3,999 (MMMCMXCIX) in the system
    // larger numbers like  millions are represented by
    // bar (vinculum) over  numeral to multiply by 1000

    // The constraints are limited to that range
    // convert the number to  roman numeral
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

    // Time: O(n ^ 2): Quadratic Time
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
    // Base Case: string of length one or two
    // Edge Case?: Empty string of length or size zero
    // Approach One: determine length which determines algorithm
    // Approach Two: create substrs eliminating two first strings then
    // use substr length to determine last step

    if (s.size() == 0)
        return std::vector<std::string>(); // edge case

    std::vector<std::string> result;
    // for (int i = 0; i < s.size(); i += 2)
    // {
    // std::string  = s.substr(i, 2);
    // if ([1] == '\0')
    // {
    // .append("_");
    // }
    // result.push_back();
    // }
    s.size() % 2 == 0 ? s : s + '_';
    std::string pb;
    // Time: O ^ 1 - Linear Time
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

// Create  function that returns the sum of the two lowest positive
// numbers given an array of minimum 4 positive integers.
// No floats or non - positive integers will be passed.

// For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.

// [10, 343445353, 3453445, 3453545353453] should return 3453455.

long sumTwoSmallestNumbers(std::vector<int> numbers)
{
    // Base Case: all values are zero or the largest possible positive value that can
    // Edge Case?: only two element in the vector
    // be represented by an integer data type; the algo should function the same way
    // consideration is all the values are the same or a number of same values
    // Approach: sort array and slice array to read first two values
    // Approach: iterate and find lowest value twice prevent same value from returning
    // Approach: iterate and bubble up first two lowest values
    if (numbers.size() < 2)
        return 0; // edge case

    for (const auto &num : numbers)
    {
        printf("%i", num);
    }

    // Libray Implementation: Sort
    // std::sort(numbers.begin(), numbers.end());

    // Selection Sort Algorithm
    // for (std::vector<int>::iterator i = numbers.begin(); i != numbers.end(); ++i)
    // {
    // std::vector<int>::iterator indx = i;
    // for (std::vector<int>::iterator j = i + 1; j != numbers.end(); ++j)
    // {
    // if (*j < *indx)
    // indx = j;
    // }
    // std::swap(*i, *indx);
    // }
    // long result = static_cast<long>(numbers[0]) + static_cast<long>(numbers[1]);

    // long result = 0;
    // for (int j = 0; j < 2; ++j)
    // {
    // int min_value = numbers[0];
    // for (int i = 0; i < numbers.size(); ++i)
    // {
    // min_value = std::min(min_value, numbers[i]);
    // }
    // std::vector<int>::iterator iter = std::find(numbers.begin(), numbers.end(), min_value);
    // size_t index = std::distance(numbers.begin(), iter);
    // to "remove" or "invalidate" a number, will assign a sentinel value
    // INT_MAX (from <climits>) other option is something something outside your expected range:
    // numbers[index] = INT_MAX;
    // result += min_value;
    // }

    int min1 = INT_MAX, min2 = INT_MAX;

    for (int num : numbers)
    {
        if (num < min1)
        {
            min2 = min1;
            min1 = num;
        }
        else if (num < min2)
        {
            min2 = num;
        }
    }

    long result = static_cast<long>(min1) + static_cast<long>(min2);

    return result;
}
/********************* Main ******************/
int main(void)
{
    // roman_numerals(1000);
    // split_strings("abcde");
    std::vector<int> numbers = {19, 5, 42, 2, 77};
    sumTwoSmallestNumbers(numbers);
}