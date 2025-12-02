#include <stdio.h>
#include <iostream>
#include <array>
#include <map>
#include <string>
using namespace std;

// Combinations
// Create a function that takes a variable number of arguments,
// each argument representing the number of items in a group.The function should return the number of permutations(combinations)
// of choices you would have if you selected one item from each group.

// Examples
// combinations([ 2, 3 ]) ➞ 6
// combinations([ 3, 7, 4 ]) ➞ 84
// combinations([ 2, 3, 4, 5 ]) ➞ 120

// function declarations & definitions
int combinations(int arr[5])
{
    int combResult = 1;
    for (int i = 0; i < static_cast<int>(sizeof(arr)); i++)
    {
        if (arr[i] != 0)
        {
            combResult *= arr[i];
        }
    }

    return combResult;

    // int arrays[5] = {2, 3, 3, 5, 3};
    // for (int item : arrays)
    // {
    //     return result *= item;
    // }
}

array<int, 2> trackRobot(int n = 0, int e = 0, int s = 0, int w = 0)
{
    int l = 0;
    int r = 0;

    s *= -1;
    w *= -1;

    l = n + s;
    r = e + w;
    // cout << "\n" + l;
    // cout << "\n" + r;
    // cout << "\n" + n;
    // cout << "\n" + s;
    // cout << "\n" + e;
    // cout << "\n" + w;
    array<int, 2> robotResult;
    robotResult[0] = l;
    robotResult[1] = r;

    // cout << typeid(robotResult).name();
    return robotResult;
}

void pyramids(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "#";
        for (int k = 0; k < n; k++)
        {
            cout << "\n";
        }
    }
}

// The Fiscal Code
// Each person in Italy has an unique identifying ID code issued by the national tax office after the birth registration:
// the Fiscal Code (Codice Fiscale). Check the Resources tab for more info on this.

// Given an object containing the personal data of a person (name, surname, gender and date of birth) return the 11 code
// characters as a string following these steps:

// Generate 3 capital letters from the surname, if it has:
// At least 3 consonants then the first three consonants are used. (Newman -> NWM).
// Less than 3 consonants then vowels will replace missing characters in the same order they appear
// (Fox -> FXO | Hope -> HPO).
// Less than three letters then "X" will take the third slot after the consonant and the vowel (Yu -> YUX).

// Generate 3 capital letters from the name, if it has:
// Exactly 3 consonants then consonants are used in the order they appear (Matt -> MTT).
// More than 3 consonants then first, third and fourth consonant are used (Samantha -> SNT | Thomas -> TMS).
// Less than 3 consonants then vowels will replace missing characters in the same order they appear
// (Bob -> BBO | Paula -> PLA).
// Less than three letters then "X" will take the the third slot after the consonant and the vowel (Al -> LAX).

// Generate 2 numbers, 1 letter and 2 numbers from date of birth and gender:
// Take the last two digits of the year of birth (1985 -> 85).
// Generate a letter corresponding to the month of birth (January -> A | December -> T) using the table for conversion
// included in the code.
// For males take the day of birth adding one zero at the start if is less than 10 (any 9th day -> 09 | any 20th day -> 20).
// For females take the day of birth and sum 40 to it (any 9th day -> 49 | any 20th day -> 60).

// fiscalCode({
//     name : "Matt",
//     surname : "Edabit",
//     gender : "M",
//     dob : "1/1/1900"
// }) ➞ "DBTMTT00A01"

//     fiscalCode({
//         name : "Helen",
//         surname : "Yu",
//         gender : "F",
//         dob : "1/12/1950"
//     }) ➞ "YUXHLN50T41"

//     fiscalCode({
//         name : "Mickey",
//         surname : "Mouse",
//         gender : "M",
//         dob : "16/1/1928"
//     }) ➞ "MSOMKY28A16"

void fiscalCode(map<string, string> fiscal_map)
{
    char c, month_char;
    int lowercase_vowel, uppercase_vowel;

    std::basic_string<char> surname, name, store_vowel;
    // std::basic_string<char> name;
    string fiscal_result;

    // string manipulation surname;
    for (char fiscal_char : fiscal_map["surname"])
    {

        // c = fiscal_map["name"][i];
        c = fiscal_char;
        bool lowercase_vowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        bool uppercase_vowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

        if (lowercase_vowel || uppercase_vowel)
        {
            store_vowel.push_back((char)toupper(fiscal_char));
        }
        else
        {
            surname.push_back((char)toupper(c));
        }
    }
    if (surname.size() == 1)
    {
        surname.append(store_vowel + "X");
    }
    else if (surname.size() < 3)
    {
        surname.append(store_vowel.substr(0, 1));
    }
    else
    {
        surname = surname.substr(0, 2);
    }

    // name string manipulation
    for (char fiscal_char : fiscal_map["name"])
    {

        // c = fiscal_map["name"][i];
        c = fiscal_char;
        bool lowercase_vowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        bool uppercase_vowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

        store_vowel.erase();
        if (lowercase_vowel || uppercase_vowel)
        {
            store_vowel.push_back((char)toupper(fiscal_char));
        }
        else
        {
            name.push_back((char)toupper(c));
        }
    }
    if (name.size() < 1)
    {
        name.append(store_vowel + "X");
    }
    else if (name.size() <= 2)
    {
        name.push_back(store_vowel[0]);
    }
    else if (name.size() > 3)
    {
        name.assign(name.substr(0, 1) + name.substr(2, 1) + name.substr(3, 1));
    }
    else
    {
        name.substr(0, 2);
    }

    // string manipulation to find year from date of birth
    string year = fiscal_map["dob"].substr(fiscal_map["dob"].size() - 1, 2);

    string test = fiscal_map["dob"].substr(fiscal_map["dob"].find('/'), fiscal_map["dob"].find_last_of('/') - (fiscal_map["dob"].find_first_of('/') + 2));
    int test1 = fiscal_map["dob"].find('/');
    int test2 = fiscal_map["dob"].find_last_of('/') - (fiscal_map["dob"].find_first_of('/') + 2);

    // string manipulation letter based on month
    int month = std::stoi(fiscal_map["dob"].substr(fiscal_map["dob"].find('/'), fiscal_map["dob"].find_last_of('/') - (fiscal_map["dob"].find_first_of('/') + 2)));
    switch (month)
    {
    case 1:
        month_char = 'A';
        break;
    case 2:
        month_char = 'B';
        break;
    case 3:
        month_char = 'C';
        break;
    case 4:
        month_char = 'D';
        break;
    case 5:
        month_char = 'E';
        break;
    case 6:
        month_char = 'F';
        break;
    case 7:
        month_char = 'G';
        break;
    case 8:
        month_char = 'H';
        break;
    case 10:
        month_char = 'I';
        break;
    case 11:
        month_char = 'J';
        break;
    case 12:
        month_char = 'K';
        break;
    }

    // string manipulation number based on gender
    int day = std::stoi(fiscal_map["dob"].substr(0, fiscal_map["dob"].find_first_of('/')));
    string day_string;
    if (fiscal_map["gender"] == "M")
    {
        if (day < 10)
        {
            day_string = "0" + std::to_string(day);
        }
        else
        {
            day_string = std::to_string(day);
        }
    }
    else
    {
        day_string = std::to_string(day + 40);
    }

    // final result with the entire string
    // all values need to be converted to string
    fiscal_result.append(surname + name + year + month_char + day_string);
}

int main(void)
{

    printf("Hello World!\n");
    int combinArr[5] = {2, 3, 3, 5, 3};
    printf("Combination: %i\n", combinations(combinArr));

    // trackRobot(-10, 20, 10);
    // printf("%s\n", typeid(trackRobot(-10, 20, 10)).name());
    printf("Robot Tracker: ", trackRobot(-10, 20, 10));

    map<string, string> fiscal_map = {
        {"name", "Mickey"},
        {"surname", "Mouse"},
        {"gender", "M"},
        {"dob", "16/1/1928"}};

    fiscalCode(fiscal_map);

    return 0;
}
