#!/usr/bin/env bash



# 27. Remove Element

# Given an integer array nums and an integer val,
# remove all occurrences of val in nums in - place.The order of the elements may be changed.Then return the number of elements in nums which are not equal to val.

# Consider the number of elements in nums which are not equal to val be k,
# to get accepted, you need to do the following things :

# Change the array nums such that the first k elements of nums contain the elements which are not equal to val.The remaining elements of nums are not important as well as the size of nums.Return k.

# Custom Judge :

# The judge will test your solution with the following code :

# int[] nums = [...];     # Input array
# int val = ...;              # Value to remove
# int[] expectedNums = [...]; # The expected answer with correct length.
#                             # It is sorted with no values equaling val.

# int k = removeElement(nums, val); # Calls your implementation

# assert k == expectedNums.length;
# sort(nums, 0, k); # Sort the first k elements of nums
# for (int i = 0; i < actualLength; i++)
# {
#     assert nums[i] == expectedNums[i];
# }

# If all assertions pass, then your solution will be accepted.

# Example 1 :

# Input : nums = [ 3, 2, 2, 3 ],
# val = 3 Output : 2, nums = [ 2, 2, _, _ ] Explanation : Your function should return k = 2, with the first two elements of nums being 2. It does not matter what you leave beyond the returned k(hence they are underscores).

# Example 2 :

# Input : nums = [ 0, 1, 2, 2, 3, 0, 4, 2 ],
# val = 2 Output : 5, nums = [ 0, 1, 4, 0, 3, _, _, _ ] Explanation : Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4. Note that the five elements can be returned in any order.It does not matter what you leave beyond the returned k(hence they are underscores).

# Constraints :
# 0 <= nums.length <= 100
# 0 <= nums[i] <= 50
# 0 <= val <= 100 

declare -a nums=(3 2 2 3 2 0);
nums=(3 2 2 3 2 0);
val=3


function removeElement() {
	#  echo $1;
	#  echo $2;
	#  echo $#;
	#  echo ${#nums[*]};
	# echo ${#1[*]};
	# local num=@1;
	# echo ${#num[@]};
	n=$((${#nums[@]}-1));
	count=0;

	# for i in $(eval echo {1..$n}); do
  		# echo "Iteration $i"
	# done

	for i in $(eval echo {0..$n}); do
		if [ ${nums[$i]} -eq $2 ]; then
			nums[$i]=nil;
			echo ${nums[$i]};
			((count++));
		fi
	done
	echo ${#nums[@]};
	echo $((${#nums[*]}-$count));
	return $((${#nums[*]}-$count));
}

# removeElement @nums $val


# 9. Palindrome Number

# Given an integer x, return true if x is a, and false otherwise.

# Example 1:
#
# Input: x = 121
# Output: true
# Explanation: 121 reads as 121 from left to right and from right to left.
#
# Example 2:
#
# Input: x = -121
# Output: false
# Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
#
# Example 3:
#
# Input: x = 10
# Output: false
# Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
#
# Constraints:
#
# -231 <= x <= 231 - 1
#
#
# Follow up: Could you solve it without converting the integer to a string?

function isPalindrome() {
	p1=0;
	p2=$((${#x[@]}-1));

	echo $p2;
	echo ${x};
	echo "$1";

	array=("$x");
	for n in ${array[@]}; do
		echo "$n";
	done

	if [[ ${x[$p1]} -eq ${x[$p2]} ]]; then
		return true;
	fi

	# Fast: half-reverse method (O(log10 x) time, O(1) space)
	if [[ $x -lt 0 || $(($x % 10)) -eq 0 && x -ne 0 ]]; then
		return false;
	fi
}

x=121

isPalindrome $x