#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc letter_combo.c -o runme ; ./runme

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// 2 abc  
// 3 def 
// 4 ghi  
// 5 jkl 
// 6 mno 
// 7 pqrs
// 8 tuv 
// 9 wxyz 

// Example:

// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

//////////////////////////////////////////////////////
// Support Functions
//////////////////////////////////////////////////////


void dump(char **returnStrs, int returnSize){
    int i, j, n;

    printf("returnStrs: [\n");
    for (j=0; j<returnSize; j++) {
         printf("  %d: \"%s\"\n", j, returnStrs[j]);
    }
    printf(" ]\n");

}

// NOTE: does not null base pointers (just couldnt send int ***)
void cleanup(char **returnStrs, int returnSize){
    int i;
    char *p;

    if (returnStrs) {
        for (i=0; i<returnSize; i++) {
            p = returnStrs[i];
            if (p) free(p);
        }

        free(returnStrs);
    }
}

//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////

//                   0   1   2      3      4      5      6      7       8      9
char * numStrs[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

void counter_increment(int* nums, int numsSize, int* accum){
    int place = numsSize-1;

    accum[place] += 1;
    // work backwards, add 1 to buffer[col][n] and carry if needed to n-1
    while (accum[place] > nums[place]) {
        accum[place] = 0; // reset place
        if (place == 0)
            break;        // maxed out
        if (place > 0) accum[place-1] += 1; // carry to next plae
        place -= 1;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    int i, j, total;
    char *p;
    char **returnStrs;
    int numsSize;
    int *nums;
    int *accum;


    // determine size of array
    total = 0;
    p = digits;
    while (*p) {
        i = strlen(numStrs[ (*p - '0') ]);
        if (total == 0) total  = i;
        else            total *= i;
        p++;
    }
    printf("total: %d\n", total);
    *returnSize = total;

    // a little crazy: build a counter with varible digit ranges.  run counter and map
    // digits to letters on phone
    numsSize = strlen(digits);
    nums = (int *)malloc(sizeof(int) * numsSize);
    for (i=0; i<numsSize; i++) {
        nums[i] = strlen( numStrs[ digits[i] - '0'] ) - 1;
    }
    accum = (int *)malloc(sizeof(int) * numsSize);
    for (i=0; i<numsSize; i++) {
        accum[i] = 0;
    }


    returnStrs = (char **)malloc(sizeof(char *) * total);
    for (i=0; i<total; i++) {
        returnStrs[i] = (char *)malloc(sizeof(char *) * strlen(digits));
        returnStrs[i][0] = 0;

        for (j=0; j<numsSize; j++) {
            returnStrs[i][j] = numStrs[digits[j] - '0'][accum[j]];
        }
        returnStrs[i][j] = 0;
        counter_increment(nums, numsSize, accum);
    }

    free(nums);
    free(accum);

    return returnStrs;
}


//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int returnSize;
    char **returnStrs;

    printf("letter_combo.c:\n");
    {
        printf("given: 23\n");
        returnStrs = letterCombinations("23", &returnSize);
        dump(returnStrs, returnSize);
        cleanup(returnStrs, returnSize);
    }
    {
        printf("given: 9\n");
        returnStrs = letterCombinations("9", &returnSize);
        dump(returnStrs, returnSize);
        cleanup(returnStrs, returnSize);
    }

    return 0;
}

