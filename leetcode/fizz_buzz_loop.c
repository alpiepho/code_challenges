#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc fizz_buzz_loop.c -o runme ; ./runme

// Write a program that outputs the string representation of numbers from 1 to n.

// But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

// Example:

// n = 15,

// Return:
// [
//     "1",
//     "2",
//     "Fizz",
//     "4",
//     "Buzz",
//     "Fizz",
//     "7",
//     "8",
//     "Fizz",
//     "Buzz",
//     "11",
//     "Fizz",
//     "13",
//     "14",
//     "FizzBuzz"
// ]

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

#define FIZZBUZZ_NUM 15
#define BUZZ_NUM 5
#define FIZZ_NUM 3
#define FIZZBUZZ_LEN 9
#define BUZZ_LEN 5
#define FIZZ_LEN 5

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    int i, index;
    char **returnStrs;

    returnStrs = (char **)malloc(sizeof(char *) * n);
    *returnSize = n;
    for (index = 0, i=1; i<=n; index++, i++) {
        if (i==0) continue;

        if ((i%FIZZBUZZ_NUM) == 0) {
            returnStrs[index] = (char *)malloc(sizeof(char *) * FIZZBUZZ_LEN);
            sprintf(returnStrs[index], "FizzBuzz");
        }
        else if ((i%BUZZ_NUM) == 0) {
            returnStrs[index] = (char *)malloc(sizeof(char *) * BUZZ_LEN);
            sprintf(returnStrs[index], "Buzz");
        }
        else if ((i%FIZZ_NUM) == 0) {
            returnStrs[index] = (char *)malloc(sizeof(char *) * FIZZ_LEN);
            sprintf(returnStrs[index], "Fizz");
        }
        else {
            returnStrs[index] = (char *)malloc(sizeof(char *) * FIZZ_LEN);
            sprintf(returnStrs[index], "%d", i);
        }
    }

    return returnStrs;
}


//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int returnSize;
    char **returnStrs;

    printf("fizz_buzz_loop.c:\n");
    {
        printf("given: 15\n");
        returnStrs = fizzBuzz(15, &returnSize);
        dump(returnStrs, returnSize);
        cleanup(returnStrs, returnSize);
    }

    return 0;
}

