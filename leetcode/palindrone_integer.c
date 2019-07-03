#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// gcc palindrone_integer.c -o runme ; ./runme

// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

// Example 1:

// Input: 121
// Output: true
// Example 2:

// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome

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

bool isPalindrome(int x){
    if (x >= 0) {
        if (x == reverse(x))
            return true;
    }
    return false;
}

//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int size;
    int *array;

    printf("palindrone_integer.c:\n");
    printf("result: %d\n", isPalindrome(123));
    printf("result: %d\n", isPalindrome(-123));
    printf("result: %d\n", isPalindrome(121));
    printf("result: %d\n", isPalindrome(1534236469)); 
    printf("result: %d\n", isPalindrome(-2147483648)); 
    printf("result: %d\n", isPalindrome(214748365));     
}

