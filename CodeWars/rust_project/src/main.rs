use std::collections::HashMap;
// Create a function taking a positive integer between 1 and 3999 (both included) as its parameter and returning a string containing the Roman Numeral representation of that integer.

// Modern Roman numerals are written by expressing each digit separately starting with the leftmost digit and skipping any digit with a value of zero. There cannot be more than 3 identical symbols in a row.

// In Roman numerals:

// 1990 is rendered: 1000=M + 900=CM + 90=XC; resulting in MCMXC.
// 2008 is written as 2000=MM, 8=VIII; or MMVIII.
// 1666 uses each Roman symbol in descending order: MDCLXVI.
// Example:

// 1 -->       "I"
// 1000 -->       "M"
// 1666 --> "MDCLXVI"

fn roman_numerals(num: i32) -> String {
    let mut result: &str;
    const roman_table: HashMap<i32, &str> = HashMap::new(
        1000: "M",
        900: "CM",
        500: "D",
        400: "CD",
        100: "C",
        90: "XC"
        50: "L",
        40: "XL",
        10: "X",
        9: "IX",
        5: "V",
        4: "IV",
        1: "I"
    );

    for (n, s) in &roman_table {
        if n > num {
            let mut c: i32 = floor(num / n);
            result.push(s.repeat(2));
            num -= (c * n);
        }
    }
    return result;
}



fn main() {
    println!("Hello, world!");
    roman_numerals(1116);
}
