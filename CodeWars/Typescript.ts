// Create a function taking a positive integer between 1 and 3999 (both included) 
// and returning a string containing the Roman Numeral representation of that inte

// Modern Roman numerals are written by expressing each digit separately starting 
// and skipping any digit with a value of zero. There cannot be more than 3 identi

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
function roman_numeralsTS(num: number): string {
    var roman_key: {} = {
        1000: 'M',
        900: 'CM',
        500: 'D',
        400: 'CD',
        100: 'C',
        90: 'XC',
        50: 'L',
        40: 'XL',
        10: 'X',
        9: 'IX',
        5: 'V',
        4: 'IV',
        1: 'I'
    }
    var result: string = '';
    Object.entries(roman_key).reverse().forEach((a) => {
        var k: number = Number(a[0]), v: string = String(a[1]);
        if (num > k) {
            var count: number = Math.trunc(num / k);
            result += v.repeat(count);
            // result.concat(v).repeat(Math.trunc(num / k));
            // result.padEnd(result.length + v.length, v).repeat(Math.trunc(num / k));
            // result + v.substring(0).repeat(Math.trunc(num / k))
            num -= (k * count);
        }
    })
    return result;
}

// roman_numerals(2666);


// Complete the solution so that it splits the string into pairs of two characters.
// If the string contains an odd number of characters then it should replace the missing
// second character of the final pair with an underscore ('_').
//
// Examples:
//
//  'abc' =>  ['ab', 'c_']
//  'abcdef' => ['ab', 'cd', 'ef']

function split_stringsTS(s: string): string[] {
    // Simple loop with slice
    var result: string[] = [];
    // var sub: string = '';
    // for (var i = 0; i < s.length; i += 2) {
    // sub: string = s.substring(i, i + 2);
    // sub: string = sub.length == 2 ? sub : sub + '_';
    // result.push(sub);
    // }
    // return result;

    // One-Liner Map Concat
    // var a: string = '';
    // return s.split().map((v, i) => { a: string = a.concat(a) if (i % 2 == 0) {return result.push(a)}})

    // Padding + Split
    // s = s.length % 2 == 0 ? s : s.concat('_')
    // s.split('').forEach((v, i) => { if (i % 2 === 0) { result.push(s.substring(i, i + 2)) } });
    // return result;

    // Array String + Padding(one-liner)
    // Array.from(s).forEach((v, i) => { if (i % 2 === 0) { var a: string = s.substring(i, i + 2); result.push(a.padEnd(2, '_')) } })
    // return result;

    // Array String
    Array.from(s).forEach((v, i) => { if (i % 2 === 0) result.push(s.substring(i, 1 + 1).padEnd(2, '_')) })
    return result;

    //REGEX
    if (s.length % 2 !== 0) s += '_';
    return s.match(/.{1,2}/g) ?? [];

    // Generator
    function* gen(s: string) {
        s = s.length % 2 === 0 ? s : s += '_';
        for (var i = 0; i < s.length; i += 2) {
            yield s.substring(i, i + 2);
        }
    }
    return [...gen(s)];
}

split_stringsTS('abcde');



// split_strings('abcde');

// Create  function that returns the sum of the two lowest positive
// numbers given an array of minimum 4 positive integers.
// No floats or non - positive integers will be passed.
// For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.
// [10, 343445353, 3453445, 3453545353453] should return 3453455.

function sumTwoSmallestNumbersTS(numbers: number[]): number {
    return numbers.sort((a, b) => a - b).slice(0, 2).reduce((p: number, c: number) => p + c, 0);
}
