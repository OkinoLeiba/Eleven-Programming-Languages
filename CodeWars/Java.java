package CodeWars;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.LinkedHashMap;

public class Java {

    // Create a function taking a positive integer between 1 and 3999 (both
    // included) as its parameter
    // and returning a string containing the Roman Numeral representation of that
    // integer.

    // Modern Roman numerals are written by expressing each digit separately
    // starting with the leftmost digit
    // and skipping any digit with a value of zero. There cannot be more than 3
    // identical symbols in a row.

    // In Roman numerals:

    // 1990 is rendered: 1000=M + 900=CM + 90=XC; resulting in MCMXC.
    // 2008 is written as 2000=MM, 8=VIII; or MMVIII.
    // 1666 uses each Roman symbol in descending order: MDCLXVI.
    // Example:

    // 1 --> "I"
    // 1000 --> "M"
    // 1666 --> "MDCLXVI"

    // {'M', 1000},
    // {'D', 500},
    // {'C', 100},
    // {'L', 50},
    // {'X', 10},
    // {'V', 5},
    // {'I', 1},
    public static String roman_numerals(int num) {
        StringBuilder result = new StringBuilder();
        LinkedHashMap<Integer, String> roman_table = new LinkedHashMap<Integer, String>();
        
        roman_table.put(1000, "M");
        roman_table.put(900, "CM");
        roman_table.put(500, "D");
        roman_table.put(400, "CD");
        roman_table.put(100, "C");
        roman_table.put(90, "XC");
        roman_table.put(50, "L");
        roman_table.put(40, "XL");
        roman_table.put(10, "X");
        roman_table.put(9, "IX");
        roman_table.put(5, "V");
        roman_table.put(4, "IV");
        roman_table.put(1, "I");
        
        for (int key : roman_table.keySet()) {
            if (key <= num) {
                int count = Math.floorDiv(num, key);
                int i = 0;
                while (i < count) {result.append(roman_table.get(key)); ++i;}
                num -= (count * key);
            }
        }


        return result.toString();
    }

    // Complete the solution so that it splits the string into pairs of two characters.
    // If the string contains an odd number of characters then it should replace the mi
    // second character of the final pair with an underscore ('_').
    //
    // Examples:
    //
    //  'abc' =>  ['ab', 'c_']
    //  'abcdef' => ['ab', 'cd', 'ef']

    public static String[] split_strings(String s) {
        ArrayList<String> result = new ArrayList<String>();
        // String[] result = new String[s.length()/2];
        for (int i = 0; i < s.length(); i += 2) {
            // int j = 0;
            if (i + 1 < s.length()) {
                result.add(s.substring(i, i + 2));
                // result[j] = s.substring(i, i+2);
                // j++;
            } else {
                result.add(s.substring(i, i + 1) + '_');
            }

        }

        return result.toArray(new String[0]);
    }
    
    // Create  function that returns the sum of the two lowest positive
    // numbers given an array of minimum 4 positive integers.
    // No floats or non - positive integers will be passed.

    // For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.

    // [10, 343445353, 3453445, 3453545353453] should return 3453455.

    public static int sumTwoSmallestNumbers(int[] numbers) {
        // Insertion Algorithm
        for (int i = 1; i < numbers.length; i++) {
            int k = numbers[i];
            int j = i - 1;

            while (j >= 0 && numbers[j] > k) {
                numbers[j + 1] = numbers[j];
                --j;
            }
            numbers[j+1] = k;
        }
        int result = numbers[0] + numbers[1];
        return result;
    }

    /*************** Main Method ***************/
    public static void main(String[] args) {
        // roman_numerals(1666);
        // split_strings("abcdef");
        int[] numbers = {19, 5, 42, 2, 77};
        sumTwoSmallestNumbers(numbers);
    }
}
