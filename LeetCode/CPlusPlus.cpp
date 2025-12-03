// 27. Remove Element

// Given an integer array nums and an integer val,
// remove all occurrences of val in nums in - place.The order of the elements may be changed.Then return the number of elements in nums which are not equal to val.

// Consider the number of elements in nums which are not equal to val be k,
// to get accepted, you need to do the following things :

// Change the array nums such that the first k elements of nums contain the elements which are not equal to val.The remaining elements of nums are not important as well as the size of nums.Return k.

// Custom Judge :

// The judge will test your solution with the following code :

// int[] nums = [...];     // Input array
// int val = ...;              // Value to remove
// int[] expectedNums = [...]; // The expected answer with correct length.
//                             // It is sorted with no values equaling val.

// int k = removeElement(nums, val); // Calls your implementation

// assert k == expectedNums.length;
// sort(nums, 0, k); // Sort the first k elements of nums
// for (int i = 0; i < actualLength; i++)
// {
//     assert nums[i] == expectedNums[i];
// }

// If all assertions pass, then your solution will be accepted.

// Example 1 :

// Input : nums = [ 3, 2, 2, 3 ],
// val = 3 Output : 2, nums = [ 2, 2, _, _ ] Explanation : Your function should return k = 2, with the first two elements of nums being 2. It does not matter what you leave beyond the returned k(hence they are underscores).

// Example 2 :

// Input : nums = [ 0, 1, 2, 2, 3, 0, 4, 2 ],
// val = 2 Output : 5, nums = [ 0, 1, 4, 0, 3, _, _, _ ] Explanation : Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4. Note that the five elements can be returned in any order.It does not matter what you leave beyond the returned k(hence they are underscores).

// Constraints :
// 0 <= nums.length <= 100
// 0 <= nums[i] <= 50
// 0 <= val <= 100

#include <vector>
#include <stdio.h>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int count = 0;
    // two pointer approach
    // move val in nums to end of vector
    // for (vector<int>::iterator p1 = nums.begin(); p1 != nums.end(); p1++)
    // {
    // vector<int>::iterator p2 = nums.end();
    // if (*p1 == val)
    // {
    // std::iter_swap(p1, p2);
    // }
    // }

    for (int i = 0, j = nums.size() - 1; i < j; i++)
    {
        if (nums[i] == val)
        {
            cout << nums[i];
            cout << nums[j];
            std::swap(nums[i], nums[j]);
        }
    }

    for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++)
    {
        if (*i == val)
        {
            count += 1;
        }
    }

    for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++)
    {
        if (*i == val)
        {
            // cout << nums[i] << endl;
            // cout << i;
            // nums.erase(i, i);
            // *i = NULL;
            // cout << i << endl;
            cout << *i << endl;
        }
    }
    // cout << nums.size();

    return count;
}

// 9. Palindrome Number

// Given an integer x, return true if x is a, and false otherwise.

// Example 1:
//
// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
//
// Example 2:
//
// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
//
// Example 3:
//
// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
//
// Constraints:
//
// -231 <= x <= 231 - 1
//
//
// Follow up: Could you solve it without converting the integer to a string?

bool isPalindrome(int x)
{
    // In reality a string is an array of characters that can de decoded and encoded
    // while a number or literal is an signal character that can be decoded
    // the only thing a I can thing of is a math trick or formula to decern if
    // the number is a palindrome: subtracting 101 until both ends are zero then
    // checking if 000-90 or the modulus of 101

    // Base Case: first three digit number [100]
    // exclude negative numbers and digits less than 100
    if (x <= 0 or x <= 99)
    {
        return false;
    }

    // convert to string array
    string str_x = to_string(x);
    // two pointer approach: int
    int p1 = 0;
    int p2 = str_x.length() - 1;

    if (str_x[p1] == str_x[p2])
    {
        // return true;
    }
    else
    {
        // return false;
    }

    // two pointer approach: iterator
    string::iterator sp1 = str_x.begin();
    string::reverse_iterator sp2 = str_x.rbegin();

    if (*sp1 == *sp2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(void)
{
    vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
    vector<int> nums = {3, 2, 2, 3};
    // removeElement(nums, 3);

    int x = 121;
    isPalindrome(x);
}
