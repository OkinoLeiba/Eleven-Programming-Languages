//go:build cgo
// +build cgo

package main

/*
#include <stdint.h>
*/
import "C"

import (
	"fmt"
	"sort"
	"strings"
)

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

func roman_numerals(num int) string {
	var result strings.Builder
	var roman_table = map[string]int{
		// 1000: "M",
		// 900:  "CM",
		// 500:  "D",
		// 400:  "CD",
		// 100:  "C",
		// 90:   "XC",
		// 50:   "L",
		// 40:   "XL",
		// 10:   "X",
		// 9:    "IX",
		// 5:    "V",
		// 4:    "IV",
		// 1:    "I",
		"M":  1000,
		"CM": 900,
		"D":  500,
		"CD": 400,
		"C":  100,
		"XC": 90,
		"L":  50,
		"XL": 40,
		"X":  10,
		"IX": 9,
		"V":  5,
		"IV": 4,
		"I":  1,
	}

	// create sorted keys used to sort map
	keys := make([]string, 0, len(roman_table))
	for k := range roman_table {
		keys = append(keys, k)
	}
	sort.Slice(keys, func(i, j int) bool { return roman_table[keys[i]] >= roman_table[keys[j]] })

	// for _, k := range keys {
	// fmt.Print(roman_table[k])
	// }

	// for _, k := range keys {
	// if roman_table[k] < num {
	// var n int = num / roman_table[k]
	// for i := 0; i < n; i++ {
	// result.WriteString(k)
	// }
	// num -= (n * roman_table[k])
	// }
	// }

	// Go maps are intentionally unordered — iteration order is unspecified and
	// randomized by the runtime. Your map-based loop therefore processes symbols
	// in a nondeterministic order, producing inconsistent outputs.
	var table = []struct {
		sym string
		val int
	}{
		{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
		{"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
		{"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1},
	}
	for _, p := range table {
		for num >= p.val {
			result.WriteString(p.sym)
			num -= p.val
		}
	}
	return result.String()
}

// Complete the solution so that it splits the string into pairs of two characters.
// If the string contains an odd number of characters then it should replace the missing
// second character of the final pair with an underscore ('_').
//
// Examples:
//
//  'abc' =>  ['ab', 'c_']
//  'abcdef' => ['ab', 'cd', 'ef']

func split_strings(s string) []string {
	result := []string{}

	// preallocate slice capacity
	// result := make([]string, 0, (len(s)+1/2))

	// rune safe
	//result := []rune(s)

	// if len(s)%2 != 0 {
	// s = s + "_"
	// }

	// Unlike some languages, Go doesn’t encourage catching any panic with recover()
	// except in very rare cases.
	// The idiomatic way to handle index out of range is defensive programming:
	// Always validate indices.
	// Use slices carefully when cutting or appending.
	// Handle edge cases explicitly.

	// for i, _ := range s {
	// defensive programming
	// the slice operator for string
	// does not need it
	//	if i == len(s) {
	//		break
	//	}
	//	result = append(result, s[i:i+2])
	//}

	// Simple loop
	// for i := 0; i < len(s); i += 2 {
	// if i+1 < len(s) {
	// result = append(result, s[i:i+2])
	// } else {
	// result = append(result, s[i:i+1]+"_")
	// }
	// }

	// Loop + StringBuilder
	for i := 0; i < len(s); i += 2 {
		var b strings.Builder
		b.WriteString(string(s[i]))
		if i+1 < len(s) {
			b.WriteString(string(s[i+1]))
		} else {
			b.WriteString("_")
		}
		result = append(result, b.String())
	}
	return result
}

// Create  function that returns the sum of the two lowest positive
// numbers given an array of minimum 4 positive integers.
// No floats or non - positive integers will be passed.

// For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.

// [10, 343445353, 3453445, 3453545353453] should return 3453455.

func sumTwoSmallestNumbers(numbers []int) int {
	// sort.Slice(numbers, func(i, j int) bool {
	//	return numbers[i] < numbers[j]
	// })
	// return numbers[0] + numbers[1]

	// Bubble Sort Algorithm
	for i := 0; i < len(numbers)-1; i++ {
		for j := 0; j < len(numbers)-i-1; j++ {
			if numbers[j] > numbers[j+1] {
				numbers[j], numbers[j+1] = numbers[j+1], numbers[j]
			}
		}
	}
	return numbers[0] + numbers[1]
}

/********************* Main ******************/
func main() {
	// fmt.Print(roman_numerals(2116))
	// fmt.Print(split_strings("abcde"))
	numbers := []int{19, 5, 42, 2, 77}
	fmt.Print(sumTwoSmallestNumbers(numbers))

}
