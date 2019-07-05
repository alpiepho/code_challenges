#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// gcc longest_prefix.c -o runme ; ./runme

// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
// Note:

// All given inputs are in lowercase letters a-z.

//////////////////////////////////////////////////////
// Support Functions
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////
char * longestCommonPrefix(char ** strs, int strsSize){
    int i, index;
    int good;
    char *result;
    
    if (strsSize == 0 || strs == 0 || *strs == 0) {
        return "";
    }
    
    result = (char*)malloc(strlen(strs[0])+1);
        
    index = 0;
    good = 1;
    while (good) {
        // for each string
        for (i=0; i<strsSize; i++) {
            // test string empty
            if (strs[i] == 0) good = false;
            // test end of string
            else if (strs[i][index] == 0) good = false;
            // test same as others
            else if (strs[i][index] != strs[0][index]) good = false;
        }
        // still good, update
        result[index] = 0;
        if (good) result[index] = strs[0][index];
        index++;
    }
    return result;

}

//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int size;
    int *array;

    printf("longest_prefix.c:\n");
    {
        char * array[] = { "flower", "flow", "flight" };
        printf("input: %s  result: %s\n", "{ flower, flow, flight }", longestCommonPrefix(array, 3));
    }
    {
        char * array[] = { "dog","racecar","car" };
        printf("input: %s  result: %s\n", "{ dog, racecar, car }", longestCommonPrefix(array, 3));
    }
    {
        char * array[] = { };
        printf("input: %s  result: %s\n", "{}", longestCommonPrefix(array, 0));
    }
    return 1;
}

