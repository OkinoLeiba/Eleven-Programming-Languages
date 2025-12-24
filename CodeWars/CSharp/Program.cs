// See https://aka.ms/new-console-template for more information
using System;
using System.Collections;
using System.IO;
using System.Text;


namespace CSharp
{
    class Program
    {

        public static void file_paths()
        {
            // Current working directory
            string cwd = Directory.GetCurrentDirectory();

            // Current file path (this executable)
            string filePath = System.Reflection.Assembly.GetExecutingAssembly().Location;

            // Directory of the current file
            string fileDirname = Path.GetDirectoryName(filePath);

            // Basename (filename only)
            string fileBasename = Path.GetFileName(filePath);

            // Dirname basename (last folder name of the file’s directory)
            string fileDirnameBasename = Path.GetFileName(fileDirname);

            // Relative path from cwd
            string relativeFile = Path.GetRelativePath(cwd, filePath);
            string relativeFileDirname = Path.GetRelativePath(cwd, fileDirname);

            Console.WriteLine("CWD: " + cwd);
            Console.WriteLine("FILE: " + filePath);
            Console.WriteLine("FILE_DIRNAME: " + fileDirname);
            Console.WriteLine("FILE_BASENAME: " + fileBasename);
            Console.WriteLine("FILE_DIRNAME_BASENAME: " + fileDirnameBasename);
            Console.WriteLine("RELATIVE_FILE: " + relativeFile);
            Console.WriteLine("RELATIVE_FILE_DIRNAME: " + relativeFileDirname);

        }

        // Create  function taking  positive integer between 1 and 3999 (both included) as its parameter
        // and returning  string containing the Roman Numeral representation of that integer.

        // Modern Roman numerals are written by expressing each digit separately starting with the leftmost digit
        // and skipping any digit with  value of zero. There cannot be more than 3 identical symbols in  row.

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

        public static string roman_numerals(int num)
        {
            SortedList<int, string> roman_table = new SortedList<int, string>();
            StringBuilder result = new StringBuilder();
            roman_table.Add(1000, "M");
            roman_table.Add(900, "CM");
            roman_table.Add(500, "D");
            roman_table.Add(400, "CD");
            roman_table.Add(100, "C");
            roman_table.Add(90, "XC");
            roman_table.Add(50, "L");
            roman_table.Add(40, "XL");
            roman_table.Add(10, "X");
            roman_table.Add(9, "IX");
            roman_table.Add(5, "V");
            roman_table.Add(4, "IV");
            roman_table.Add(1, "I");

            var reverse_table = roman_table.Reverse();

            // roman_table.ToDictionary<int, string>().Select((x,y) => y.ToUpper());
            foreach (var entry in reverse_table)
            {
                if ((int)entry.Key <= num)
                {
                    int count = num / (int)entry.Key;
                    result.Append(entry.Value.ToString().PadRight(count, Convert.ToChar(entry.Value)));
                    num -= count * (int)entry.Key;
                }
            }
            return result.ToString();
        }


        // Complete the solution so that it splits the string into pairs of two characters.
        // If the string contains an odd number of characters then it should replace the missing
        // second character of the final pair with an underscore ('_').
        //
        // Examples:
        //
        // * 'abc' =>  ['ab', 'c_']
        // * 'abcdef' => ['ab', 'cd', 'ef']

        public static string[] split_strings(string str)
        {
            string[] result = { };
            // StringBuilder a = new StringBuilder();
            // foreach (char c in str.ToCharArray())
            // {
            // a.Append(c);
            // if (a.Length % 2 == 0)
            // {
            // result.Append(a.ToString().PadRight(2, '_'));
            // a.Clear();
            // }

            // }
            // char[] test = str.ToCharArray(0, 2);
            for (int i = 0; i < str.Length; i += 2)
            {
                string a = string.Empty;
                if (a.Length % 2 == 0)
                {
                    // a = str.Substring(i, 2).PadRight(2, '_');
                    result.Append(a);
                }
                else
                {
                    a = str.Substring(i, 2).PadRight(2, '_');
                    result.Append(a + '_');
                }

            }

            Console.WriteLine(result);


            return result;

            //char[] charArr = str.ToCharArray();
            // string[] result = new string[] { };
            //var result = new List<string>();
            //string[] result = default(string[]);
            // int indx = 0;
            // for (int i = 0; i <= str.Length; i += 2)
            // {
            // if (str.Substring(i,2).Length > 1)
            // {
            // result[indx] = str.Substring(i, 2);
            // result.Add(str.Substring(i, 2));
            // result.Append(str.Substring(i, 2));
            // str = str.Replace(str.Substring(i, 2), string.Empty);
            // indx++;
            // }
            // else
            // {
            // result[indx] = str.Substring(0, 1) + "_";
            // result.Add(str.Substring(0, 1) + "_");
            // result.Append(str.Substring(0, 1) + "_");
            // break;
            // }

            // }

            // return result;
            //CodeWars/CSharp/bin/Debug/net9.0/CSharp.dll
            ///Users/om/Documents/source/eleven_programming_languages/CodeWars/CSharp/bin/Debug/net9.0/CSharp.dll
        }

        /*************** Main Method ***************/
        public static void Main(string[] args)
        {
            file_paths();
            // Console.WriteLine("Hello, World!");
            Console.WriteLine(split_strings("abc"));
            roman_numerals(2666);

        }
    }
}

