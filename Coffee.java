import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Coffee {
    // Combinations
    // Create a function that takes a variable number of arguments,
    // each argument representing the number of items in a group.The function should
    // return the number of per mutations(combinations)
    // of choices you would have if you selected one item from each group.

    // Examples
    // combinations([ 2, 3 ]) ➞ 6
    // combinations([ 3, 7, 4 ]) ➞ 84
    // combinations([2, 3, 4, 5 ]) ➞ 120
    public static int combination(int[] combArray) {
        int combResult = 1;
        for (int index = 0; index < combArray.length; index++) {
            if (combArray[index] != 0) {
                combResult *= combArray[index];

            }
        }
        return combResult;
    }

    // This robot roams around a 2D grid. It starts at (0, 0) facing North. After
    // each time it moves,
    // the robot rotates 90 degrees clockwise. Given the amount the robot has moved
    // each time,
    // you have to calculate the robot's final position.

    // To illustrate, if the robot is given the movements 20, 30, 10, 40 then it
    // will move:

    // 20 steps North, now at (0, 20)
    // 30 steps East, now at (30, 20)
    // 10 steps

    // South. now at (30, 10)
    // 40 steps West, now at (-10, 10)
    // ...and will end up
    // at coordinates (-10, 10).

    private int n = 0;
    private int w = 0;
    private int s = 0;
    private int e = 0;

    // public Coffee robotBuilder(int n, int w, int s, int e) {

    // this.n = n;
    // this.w = w;
    // this.s = s;
    // this.e = e;
    // return this;
    // }

    public static void robotTracker(int n, int w, int s, int e) {

        ArrayList<Integer> robotResult = new ArrayList<Integer>();

        int l = n + (s * -1);
        int r = w + (e * -1);

        robotResult.add(l);
        robotResult.add(r);

        System.out.println("Robot Tracker " + robotResult);
    }

    public static int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> numMap = new HashMap<>();
        int n = nums.length;

        // build the hash table
        for (int i = 0; i < n; i++) {
            numMap.put(nums[i], i);
        }

        // find the complement
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            System.out.println(numMap.containsValue(complement));

            if (numMap.containsKey(complement) && numMap.get(complement) != i) {
                return new int[] { i, numMap.get(complement) };
            }
        }
        return new int[] {};
    }

    public static int maxArea(int[] height) {
        int result = 0;
        // find max value
        int maxValue = 0;
        for (int i = 0; i < height.length - 1; i++) {
            maxValue = Math.max(height[i], maxValue);
        }

        // traverse arr from the left and right
        // use max value as pivot point
        // filter out other max value
        // int len = height.length;
        ArrayList<Integer> sub = new ArrayList<Integer>();
        // ArrayList<Integer> subArrList = new ArrayList<Integer>();
        for (int item : height) {
            sub.add(item);
        }

        // int subSize = sub.size();
        // sub.subList(sub.indexOf(maxValue), sub.size() - 1);
        int maxValueLeft = 0;
        for (int i = sub.size() - 1; i > 0; i--) {

            // for (int j = subList.size()-1; j > 0; j--)
            sub = new ArrayList<Integer>(sub.subList(sub.indexOf(maxValue), i + 1));
            // subArrList.addAll(sub.subList(sub.indexOf(maxValue), i + 1));

            result = Math.max(sub.get(sub.size() - 1) * (sub.size() - 1), result);
            // sub.clear();

            // if (subList.size() == 0) {
            // break;
            // }

        }

        return result;
    }

    public static void main(String[] args) {
        System.out.println("Hello World!");
        int[] combArray = { 2, 3 };
        System.out.println("Combination Result " + combination(combArray));
        // robotBuilder(-10, 20, 10);
        robotTracker(-10, 20, 10, 0);
        int[] nums = { 2, 7, 11, 15 };
        twoSum(nums, 9);
        int[] height = { 1, 1 };
        maxArea(height);
    }
}