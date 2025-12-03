
package LeetCode;

import java.util.ArrayList;
import java.util.Arrays;

import javax.lang.model.type.NullType;

public class Java {

    // 27. Remove Element

    // Given an integer array nums and an integer val,
    // remove all occurrences of val in nums in - place.The order of the elements
    // may be changed.Then return the number of elements in nums which are not equal
    // to val.

    // Consider the number of elements in nums which are not equal to val be k,
    // to get accepted, you need to do the following things :

    // Change the array nums such that the first k elements of nums contain the
    // elements which are not equal to val.The remaining elements of nums are not
    // important as well as the size of nums.Return k.

    // Custom Judge :

    // The judge will test your solution with the following code :

    // int[] nums = [...]; // Input array
    // int val = ...; // Value to remove
    // int[] expectedNums = [...]; // The expected answer with correct length.
    // // It is sorted with no values equaling val.

    // int k = removeElement(nums, val); // Calls your implementation

    // assert k == expectedNums.length;
    // sort(nums, 0, k); // Sort the first k elements of nums
    // for (int i = 0; i < actualLength; i++)
    // {
    // assert nums[i] == expectedNums[i];
    // }

    // If all assertions pass, then your solution will be accepted.

    // Example 1 :

    // Input : nums = [ 3, 2, 2, 3 ],
    // val = 3 Output : 2, nums = [ 2, 2, _, _ ] Explanation : Your function should
    // return k = 2, with the first two elements of nums being 2. It does not matter
    // what you leave beyond the returned k(hence they are underscores).

    // Example 2 :

    // Input : nums = [ 0, 1, 2, 2, 3, 0, 4, 2 ],
    // val = 2 Output : 5, nums = [ 0, 1, 4, 0, 3, _, _, _ ] Explanation : Your
    // function should return k = 5, with the first five elements of nums containing
    // 0, 0, 1, 3, and 4. Note that the five elements can be returned in any
    // order.It does not matter what you leave beyond the returned k(hence they are
    // underscores).

    // Constraints :
    // 0 <= nums.length <= 100
    // 0 <= nums[i] <= 50
    // 0 <= val <= 100

    public static int removeElement(int[] nums, int val) {
        int op_count = 0;
        // two pointer approach
        for (int i = 0, j = nums.length - 1; i < j; i++) {
            if (nums[i] == val) {
                int temp = 0;
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;

                // op_count += 1;
            }
        }

        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] != val) {
                op_count += 1;
            }
        }
        return op_count;

        // for (int i = 0; i < nums.length; i++) {
        // if (nums[i] == val) {
        // nums[i] = null;
        // the fill method does not accept variables
        // Arrays.fill(nums, i, i, 0);
        // }
        // }
        // return nums.length;
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
    // Explanation: From left to right, it reads -121. From right to left, it
    // becomes 121-. Therefore it is not a palindrome.
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

    public static boolean isPalindrome(int x) {

        if (x < 0)
            return false;

        String s = String.valueOf(x);
        int n = s.length();

        for (int i = 0; i < n / 2; i++) {
            if (s.charAt(i) != s.charAt(n - 1 - i))
                return false;
        }
        // return true;

        // String.valueOf(x).split("") yields a leading empty string (e.g.
        // "121".split("") -> ["","1","2","1"]), so str_arr[0] is "" not the first
        // digit.
        String[] str_arr = String.valueOf(x).split("");
        for (String str : str_arr) {
            System.out.println(str);
            System.out.println(str_arr.length);
        }

        return str_arr[0].toString() == str_arr[str_arr.length - 1].toString();
    }

    // Write a function to find the longest common prefix string amongst an array of
    // strings.
    //
    // If there is no common prefix,return an empty string"".
    //
    // Example 1:
    //
    // Input:strs=["flower","flow","flight"]Output:"fl"
    //
    // Example 2:
    //
    // Input:strs=["dog","racecar","car"]Output:""Explanation:There is no common
    // prefix among the input strings.
    //
    // Constraints:
    //
    // 1<=strs.length<=200
    // 0<=strs[i].length<=200 strs[i]
    // consists of only lowercase English letters if it is non-empty.

    public static String longestCommonPrefix(String[] strs) {
        ArrayList<String> prefix = new ArrayList<String>();
        StringBuilder str_prefix = new StringBuilder();
        Arrays.sort(strs, (s1, s2) -> s1.length() - s2.length());
        int max_arr = strs.length - 1;

        while (max_arr > 0) {
            int min_str = 0;
            if (strs[0].charAt(min_str) == strs[max_arr].charAt(min_str)) {
                str_prefix.append(strs[0].charAt(min_str));
                min_str++;
            }
            prefix.add(str_prefix.toString());
            max_arr--;
        }
        // for (int j = 0; j < strs.length - 1; j++) {
        // StringBuilder str_prefix = new StringBuilder();
        // for (int i = 0; i < Math.min(strs[j].length(), strs[j + 1].length()) - 1;
        // i++) {
        // if (strs[j].charAt(i) != '\0') {
        // if (strs[j].charAt(i) == strs[j + 1].charAt(i)) {
        // str_prefix.append(String.valueOf(strs[j].charAt(i)));
        // }
        // }
        // }
        // prefix.add(str_prefix.toString());
        // }

        return prefix.removeLast();
    }

    /*************** Main Method ***************/
    public static void main(String[] args) {
        int nums[] = { 3, 2, 2, 3, 2, 0 };
        // System.out.println(removeElement(nums, 3));

        System.out.println(isPalindrome(121));

        String[] strs = { "flower", "flow", "flight" };
        // System.out.println(longestCommonPrefix(strs));
    }
};
