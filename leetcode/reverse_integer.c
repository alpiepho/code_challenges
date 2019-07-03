#include <stdio.h>
#include <stdlib.h>

// gcc reverse_integer.c -o runme ; ./runme

// Given a 32-bit signed integer, reverse digits of an integer.

// Example 1:

// Input: 123
// Output: 321
// Example 2:

// Input: -123
// Output: -321
// Example 3:

// Input: 120
// Output: 21
// Note:
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.


//////////////////////////////////////////////////////
// Support Functions
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////
int reverse(int x){
    int negate = (x < 0 ? -1 : 1);
    int result = 0;

    if (x == 0x80000000)
        return 0;
    x = abs(x);
    while(x) {
        if (result > (0x80000000/10))
            return 0;      // assume overflow
        result *= 10;      // shift digits
        result += x % 10;  // add digit
        x /= 10;           // shift x
    }

    return (result * negate);
}

//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int size;
    int *array;

    printf("reverse_integer.c:\n");
    printf("result: %d\n", reverse(123));
    printf("result: %d\n", reverse(-123));
    printf("result: %d\n", reverse(120));
    printf("result: %d\n", reverse(1534236469)); 
    printf("result: %d\n", reverse(-2147483648)); 
    printf("result: %d\n", reverse(214748365));     
}

