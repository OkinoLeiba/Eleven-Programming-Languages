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
// {'I', 1}

function roman_numerals(num) {
  var roman_key = {
    1000: "M",
    900: "CM",
    500: "D",
    400: "CD",
    100: "C",
    90: "XC",
    50: "L",
    40: "XL",
    10: "X",
    9: "IX",
    5: "V",
    4: "IV",
    1: "I",
  };
  const result = [];
  Object.entries(roman_key)
    .reverse()
    .forEach((a) => {
      var k = Number(a[0]),
        v = String(a[1]);
      while (num >= k) {
        var count = Math.floor(num / k);
        result.push(v.repeat(count));
        num -= k * count;
      }
    });
  str_result = result.join("");
  return str_result;
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

function split_strings(s) {
  // Simple loop with slice
  var result = [];
  // var sub = '';
  // for (var i = 0; i < s.length; i += 2) {
  // sub = s.substring(i, i + 2);
  // sub = sub.length === 2 ? sub : sub + '_';
  // result.push(sub);
  // }
  // return result;

  // One-Liner forEach
  // var a = '';
  // s.split('').forEach((v, i) => {
  // a = a.concat(a)
  // if (i % 2 === 0) {result.push(a)}
  // })

  // One-Liner Map
  // s.split('').map((v, i) => { if (i % 2 == 0) return s.slice(i, i + 2) }).filter(Boolean);
  // return s.split('').map((v, i) => { i % 2 === 0 ? s.slice(i, i + 2) : null }).filter(Boolean);

  // Padding + Split
  // s = s.length % 2 === 0 ? s : s.concat('_');
  // if (s.length % 2 !== 0) s += '_';
  // for (var i = 0; i < s.length; i += 2) {
  // result.push(s[i]+s[i+2])
  // }
  // return result.toString();

  // REGEX
  // if (s.length % 2 !== 0) s += '_';
  // return s.match(/.{1,2}/g);

  // Reduce
  // s = s.length % 2 === 0 ? s : s.concat('_');
  // return Array.from(s).reduce((a, c, i) => { if (i % 2 === 0) a.push(c + s[i + 1]); return a; },[])

  // Generator
  function* gen(s) {
    s = s.length % 2 === 0 ? s : (s += "_");
    for (var i = 0; i < s.length; i += 2) {
      yield s.slice(i, i + 2);
    }
  }
  return [...gen(s)];
}

// split_strings('abcde');

// Create  function that returns the sum of the two lowest positive
// numbers given an array of minimum 4 positive integers.
// No floats or non - positive integers will be passed.
// For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.
// [10, 343445353, 3453445, 3453545353453] should return 3453455.

function sumTwoSmallestNumbers(numbers) {
  // The partition works by moving the smallest values
  // relative to the pivot element to the left and 
  // the largest values to the right 

  // The pivot to base the partition on can be 
  // the first, last, median, or a random element
  function lomuto_partition(numbers, low, high) {
    // the last element and pivot
    let p = numbers[high];
    // the second to last element
    let i = low - 1;

    // traverse the arr[low..high] and move all smaller
    // elements to the left side, elements from low to
    // i are smaller after every iteration
    for (let j = low; j <= high - 1; j++) {
      if (numbers[j] < p) {
        i++;
        // swap(numbers, i, j);
        [numbers[i], numbers[j]] = [numbers[j], numbers[i]];
      }
    }
    // move pivot from last element after smaller elements and
    // return its position
    // swap(numbers, i + 1, high);
    [numbers[i + 1], numbers[high]] = [numbers[high], numbers[i + 1]];
    return i + 1;
  }

  function swap(numbers, i, j) {
    let temp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = temp;
  }
  function naive_partition(numbers, low, high) {
    // let last = numbers.length;
    let last = numbers.length;

    let par = numbers[high];
    // let copy_arr = new Array(n);
    let copy_arr = [];
    // let indx = 0;
    let indx = low;

    for (let i = 0; i < last; i++) {
      if (numbers[i] <= par) {
        copy_arr[indx++] = numbers[i];
      }
    }

    for (let i = 0; i < last; i++) {
      if (numbers[i] > par) {
        copy_arr[indx++] = numbers[i];
      }
    }

    for (let i = 0; i < last; i++) {
      numbers[i] = copy_arr[i];
    }
    return high;
  }
  // TODO: debug and learn and review other partitions
  function hoarse_partition(numbers, low, high) {
    let pivot = numbers[0];
    let last = high;
    let i = low - 1,
      j = last;

    while (true) {
      do {
        i++;
      } while (numbers[i] < pivot);

      do {
        j--;
      } while (numbers[j] > pivot);

      if (i > j) break;

      [numbers[i], numbers[j]] = [numbers[j], numbers[i]];
    }
    return high;
  }

  function quick_sort(numbers, low, high) {
    if (low < high) {
      let par = hoarse_parition(numbers, low, high);
      quick_sort(numbers, low, par - 1);
      quick_sort(numbers, par + 1, high);
    }
  }
  // numbers.sort((a, b) => { return a - b })
  quick_sort(numbers, 0, numbers.length - 1);
  // naive_partition(numbers);
  return numbers[0] + numbers[1];
}

sumTwoSmallestNumbers([19, 5, 42, 2, 77]);
