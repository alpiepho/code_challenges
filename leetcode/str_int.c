#include <stdio.h>
#include <stdlib.h>

// gcc str_int.c -o runme ; ./runme

// Implement atoi which converts a string to an integer.

// The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

// The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

// If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

// If no valid conversion could be performed, a zero value is returned.

// Note:

// Only the space character ' ' is considered as whitespace character.
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
// Example 1:

// Input: "42"
// Output: 42
// Example 2:

// Input: "   -42"
// Output: -42
// Explanation: The first non-whitespace character is '-', which is the minus sign.
//              Then take as many numerical digits as possible, which gets 42.
// Example 3:

// Input: "4193 with words"
// Output: 4193
// Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
// Example 4:

// Input: "words and 987"
// Output: 0
// Explanation: The first non-whitespace character is 'w', which is not a numerical 
//              digit or a +/- sign. Therefore no valid conversion could be performed.
// Example 5:

// Input: "-91283472332"
// Output: -2147483648
// Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
//              Thefore INT_MIN (−231) is returned.


//////////////////////////////////////////////////////
// Support Functions
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////


// int strStr(char * haystack, char * needle){
//     int index = -1;
//     char *p_haystack, *p_needle, *p_sub;

//     if (*haystack == 0 && *needle == 0) return 0;
//     if (*haystack == 0 && *needle) return -1;
//     if (*haystack      && *needle == 0) return 0;

//     // hello
//     // ..ll.
//     //   2
//     p_haystack = haystack;
//     while (*p_haystack && index == -1) {
//         // find start of match
//         if (*p_haystack == needle[0]) {
//             p_needle = needle;
//             p_sub = p_haystack;
//             index = p_haystack - haystack;
//             while (*p_needle && *p_sub) {
//                 if (*p_needle != *p_sub) break;
//                 p_needle++;
//                 p_sub++;
//             }
//             if (*p_needle) {
//                 index = -1;
//             }
//         }
//         p_haystack++;
//     }

//     return index;
// }

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int myAtoi(char * str){
    long int result = 0;
    int given = 0;
    int sign = 1;
    char *p;
    // find find first number, save any + or - in process
    p = str;
    while (*p) {
        if (!given && *p == '-') { sign = -1; given = 1; }
        else if (!given && *p == '+') { sign = 1; given = 1; }
        else if (given && *p == ' ') break;
        else if (*p != ' ') break;
        p++;
    }
    // get abs number
    while (*p >= '0' && *p <= '9') {
        result *= 10;
        result += (*p - '0');
        if (result > INT_MAX) break;
        p++;
    }
    // check range
    if (result > INT_MAX && sign > 0) result = INT_MAX;
    else if (result > INT_MAX && sign < 0) result = INT_MIN;
    else result = sign*result;
    return (int)result;
}


//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int result;

    printf("str_int.c:\n");
    result = myAtoi("42");
    printf("result: %d\n", result);

    result = myAtoi("-42");
    printf("result: %d\n", result);

    result = myAtoi("4193 with words");
    printf("result: %d\n", result);

    result = myAtoi("words and 987");
    printf("result: %d\n", result);

    result = myAtoi("-91283472332");
    printf("result: %d\n", result);

    result = myAtoi("20000000000000000000");
    printf("result: %d\n", result);

    result = myAtoi("+-2");
    printf("result: %d\n", result);

    result = myAtoi("-   234");
    printf("result: %d\n", result);


    return 0;
}

