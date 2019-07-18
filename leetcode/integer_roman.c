#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc integer_roman.c -o runme ; ./runme

// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

// Example 1:

// Input: 3
// Output: "III"
// Example 2:

// Input: 4
// Output: "IV"
// Example 3:

// Input: 9
// Output: "IX"
// Example 4:

// Input: 58
// Output: "LVIII"
// Explanation: L = 50, V = 5, III = 3.
// Example 5:

// Input: 1994
// Output: "MCMXCIV"
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

//////////////////////////////////////////////////////
// Support Functions
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////
// int romanToInt(char * s){
//     char * p;
//     int value = 0;

//     // find end of string so we can work backwards
//     p = s;
//     while (*p) p++;
//     p--;

//     while (p >= s) {
//         // I can be placed before V (5) and X (10) to make 4 and 9. 
//         // X can be placed before L (50) and C (100) to make 40 and 90. 
//         // C can be placed before D (500) and M (1000) to make 400 and 900.
//              if (p[0] == 'C' && p[1] == 'D') value -= 100;
//         else if (p[0] == 'C' && p[1] == 'M') value -= 100;
//         else if (p[0] == 'C')                value += 100;
//         else if (p[0] == 'D')                value += 500;
//         else if (p[0] == 'M')                value += 1000;

//         else if (p[0] == 'X' && p[1] == 'L') value -= 10;
//         else if (p[0] == 'X' && p[1] == 'C') value -= 10;
//         else if (p[0] == 'X')                value += 10;
//         else if (p[0] == 'L')                value += 50;
//         else if (p[0] == 'C')                value += 100;

//         else if (p[0] == 'I' && p[1] == 'V') value -= 1;
//         else if (p[0] == 'I' && p[1] == 'X') value -= 1;
//         else if (p[0] == 'I')                value += 1;
//         else if (p[0] == 'V')                value += 5;
//         else if (p[0] == 'X')                value += 10;
//         p--;
//     }
//     return value;
// }

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

char * I[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
char * X[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
char * C[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
char * M[] = { "", "M", "MM", "MMM" };

char * intToRoman(int num){
    char *result;
    int digit;
    int divider = 1000;

    result = (char *) malloc(128);
    result[0] = 0;

    // work backward d=1000, d=100, d=10, d=1
    // get current digit
    // append substring from table 
    while (divider > 0) {
        digit = num / divider;
        if (digit) {
            if (divider == 1000) strcat(result, M[digit]);
            if (divider == 100 ) strcat(result, C[digit]);
            if (divider == 10  ) strcat(result, X[digit]);
            if (divider == 1   ) strcat(result, I[digit]);
        }
        num %= divider;
        divider /= 10;
    }
    return result;
}

//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int size;
    int *array;

    printf("integer_roman.c:\n");
    printf("input: %d   result: %s\n", 3,   intToRoman(3));
    printf("input: %d   result: %s\n", 4,   intToRoman(4));
    printf("input: %d   result: %s\n", 9,   intToRoman(9));
    printf("input: %d   result: %s\n", 58,  intToRoman(58)); 
    printf("input: %d   result: %s\n", 1994, intToRoman(1994));    
    printf("input: %d   result: %s\n", 3994, intToRoman(3994));    
}

