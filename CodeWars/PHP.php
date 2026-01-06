<?php
echo "Hello World\n";


function info(): null {
    // phpinfo();
    return null;
}



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

function roman_numerals($num): string {
    $roman_table = array(
        "M"=> 1000,
        "CM"=> 900,
        "D"=>  500,
        "CD"=> 400,
        "C"=>  100,
        "XC"=> 90,
        "L"=>  50,
        "XL"=> 40,
        "X"=>  10,
        "IX"=> 9,
        "V"=>  5,
        "IV"=> 4,
        "I"=>  1,
    );
    $result = "";

    foreach($roman_table as $key => $value) {
        if ($value < $num) {
            $c = floor($num / $value);
            $result .= str_repeat($key, $c);
            $num -= ($c * $value);
            // Different approach to append to string

            // implode("", array($str1, $str2));
            // sprintf('%s%s', $str1, $str2);
            // "$str1, $str2!";
            // $str1 .= $str2;
            // $str1 . $str2

            // $mergedArray = array_merge([$str1], [$str2]);
            // Convert the array back to a string
            // implode('', $mergedArray);
        }
    }

    return $result;
}

// Complete the solution so that it splits the string into pairs of two characters.
// If the string contains an odd number of characters then it should replace the missing
// second character of the final pair with an underscore ('_').
//
// Examples:
//
//  'abc' =>  ['ab', 'c_']
//  'abcdef' => ['ab', 'cd', 'ef']

function split_strings($s): array {
    $result = array();

    // $s = strlen($s) % 2 == 0 ? $s : $s . "_";

    // for ($i = 0; $i < strlen($s); $i += 2) {
        // $a = substr($s, $i, 2);
        // array_push($result, $a);
    // }

    // foreach(str_split($s) as $key => $value) {
        // array_push($result, str_pad(substr($s, $key, 2), 2, "_", STR_PAD_RIGHT));
    // }

    // $i = 0;
    // while($i < strlen($s)){
        // array_push($result, str_pad(implode("", array_slice(str_split($s), $i, 2, false)), 2, "_", STR_PAD_RIGHT));
        // $i++;
    // }    

    // foreach(str_split($s) as $value) {
        // $a = strlen($a) != 2 ? implode("", array($a, $value)) : $value . "_";
        // array_push($result, $a);
    // }
    $a = "";
    foreach(str_split($s) as $value) {
        $a = $a . $value;
        if (strlen($a) == 2) {
            array_push($result, $a);
            $a = "";
        }
        if (strpos($s, $value, 0) == strlen($s)-1 && strlen($a) == 1) {
            array_push($result, $a . "_");
        }
    }

    return $result;
}

// Create  function that returns the sum of the two lowest positive
// numbers given an array of minimum 4 positive integers.
// No floats or non - positive integers will be passed.

// For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.

// [10, 343445353, 3453445, 3453545353453] should return 3453455.

function sumTwoSmallestNumbers($numbers): int {
    // Count Sort Algorithm
    // Find Max Value
    $max_value = max($numbers);
    $max_val = $numbers[0];

    // Create Array
    $countArray = array();
    foreach($numbers as $value) {
        if ($value > $max_val) {
            $max_val = $value;
        }
        // Count Frequency of Each Value
       
       
        $countArray[$value]++;
    }

    // Create Prefix Sum
    // determines the ordered position of the [original] value in the 
    // result_sort array or the array to store that value
    // the frequency is necessary to determine if the same values
    // placed next to each other as the frequency decrements

    // [sum of the] counts are the position and/or frequency is how many times the count or values is seen
    for ($i = 1; $i <= $max_value; $i++) {
        $countArray[$i] += $countArray[$i - 1];
    }

    // Output 
    $result_sort = array();
     for ($i = count($numbers)-1; $i >= 0; $i--) {
         $value = $numbers[$i];
         $result_sort[$countArray[$value] - 1] = $value;
         $countArray[$i]--;
     }


    
    // sort($numbers);
    $result = $result_sort[0] + $result_sort[1];
    return $numbers[0] + $numbers[1];
}


// roman_numerals(2666);
// split_strings("abc");
sumTwoSmallestNumbers([19, 5, 42, 2, 77]);