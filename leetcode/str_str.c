#include <stdio.h>
#include <stdlib.h>

// gcc str_str.c -o runme ; ./runme

// Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2
// Example 2:

// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
// Clarification:

// What should we return when needle is an empty string? This is a great question to ask during an interview.

// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().



//////////////////////////////////////////////////////
// Support Functions
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////


int strStr(char * haystack, char * needle){
    int index = -1;
    char *p_haystack, *p_needle, *p_sub;

    if (*haystack == 0 && *needle == 0) return 0;
    if (*haystack == 0 && *needle) return -1;
    if (*haystack      && *needle == 0) return 0;

    // hello
    // ..ll.
    //   2
    p_haystack = haystack;
    while (*p_haystack && index == -1) {
        // find start of match
        if (*p_haystack == needle[0]) {
            p_needle = needle;
            p_sub = p_haystack;
            index = p_haystack - haystack;
            while (*p_needle && *p_sub) {
                if (*p_needle != *p_sub) break;
                p_needle++;
                p_sub++;
            }
            if (*p_needle) {
                index = -1;
            }
        }
        p_haystack++;
    }

    return index;
}


//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int result;

    printf("str_str.c:\n");
    result = strStr("hello", "ll");
    printf("result: %d\n", result);

    printf("str_str.c:\n");
    result = strStr("aaaaa", "baa");
    printf("result: %d\n", result);

    printf("str_str.c:\n");
    result = strStr("", "a");
    printf("result: %d\n", result);

    printf("str_str.c:\n");
    result = strStr("", "");
    printf("result: %d\n", result);

    return 0;
}

