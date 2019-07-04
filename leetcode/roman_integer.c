#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// gcc roman_integer.c -o runme ; ./runme

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
// Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

// Example 1:

// Input: "III"
// Output: 3
// Example 2:

// Input: "IV"
// Output: 4
// Example 3:

// Input: "IX"
// Output: 9
// Example 4:

// Input: "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.
// Example 5:

// Input: "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

//////////////////////////////////////////////////////
// Support Functions
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////
int romanToInt(char * s){
    char * p;
    int value = 0;

    // find end of string so we can work backwards
    p = s;
    while (*p) p++;
    p--;

    while (p >= s) {
        // I can be placed before V (5) and X (10) to make 4 and 9. 
        // X can be placed before L (50) and C (100) to make 40 and 90. 
        // C can be placed before D (500) and M (1000) to make 400 and 900.
             if (p[0] == 'C' && p[1] == 'D') value -= 100;
        else if (p[0] == 'C' && p[1] == 'M') value -= 100;
        else if (p[0] == 'C')                value += 100;
        else if (p[0] == 'D')                value += 500;
        else if (p[0] == 'M')                value += 1000;

        else if (p[0] == 'X' && p[1] == 'L') value -= 10;
        else if (p[0] == 'X' && p[1] == 'C') value -= 10;
        else if (p[0] == 'X')                value += 10;
        else if (p[0] == 'L')                value += 50;
        else if (p[0] == 'C')                value += 100;

        else if (p[0] == 'I' && p[1] == 'V') value -= 1;
        else if (p[0] == 'I' && p[1] == 'X') value -= 1;
        else if (p[0] == 'I')                value += 1;
        else if (p[0] == 'V')                value += 5;
        else if (p[0] == 'X')                value += 10;
        p--;
    }
    return value;
}

//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int size;
    int *array;

    printf("roman_integer.c:\n");
    printf("input: %s   result: %d\n", "III",     romanToInt("III"));
    printf("input: %s   result: %d\n", "IV",      romanToInt("IV"));
    printf("input: %s   result: %d\n", "IX",      romanToInt("IX"));
    printf("input: %s   result: %d\n", "LVIII",   romanToInt("LVIII")); 
    printf("input: %s   result: %d\n", "MCMXCIV", romanToInt("MCMXCIV"));    
}

