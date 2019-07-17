#include <stdio.h>
#include <stdlib.h>

// gcc longest_substr.c -o runme ; ./runme

// Given a string, find the length of the longest substring without repeating characters.

// Example 1:

// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
// Example 2:

// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


//////////////////////////////////////////////////////
// Support Functions
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////


int checkDups(char *p, char *q) {
    // check if *q is in [p, q-1)
    char *r = p;
    while (r < q) {
        if (*r == *q) return 1;
        r++;
    }
    return 0;
}

int lengthOfLongestSubstring(char * s){
    char *p, *q;
    char *pMax;
    int maxLength;

    if (s == 0) return 0;
    if (*s == 0) return 0;
    if (s[1] == 0) return 1;

    p = s;
    pMax = p;
    maxLength = 0;
    while (*p) {
        //printf("p: %c\n", *p);
        // from point p, find non-repeat sub string [p, q)
        q = p;
        while (*q) {
            //printf("q: %d (%c)\n", (int)(q-p), *q);
            if (checkDups(p, q)) break;
            q++;
        }
        // is this substring longer?
        if ((q-p) > maxLength) {
            pMax = q;
            maxLength = (q-p);
        }
        p++;
    }
    return maxLength;
}



//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int result;

    printf("longest_substr.c:\n");
    result = lengthOfLongestSubstring("abcabcbb");
    printf("result: %d\n", result);
    result = lengthOfLongestSubstring("bbbbb");
    printf("result: %d\n", result);

    return 0;
}

