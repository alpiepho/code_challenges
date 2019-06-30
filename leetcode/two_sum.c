#include <stdio.h>
#include <stdlib.h>

// gcc two_sum.c -o runme ; ./runme

// Given an array of integers, return indices of the two numbers such that they add up to a specfic target.  Assume exactly one solution.

// Given nums = [2,7,11,15], target = 9,
// Because nums[0] + nums[1] = 2 + 7 = 9,
// Return [0, 1]

//////////////////////////////////////////////////////
// Support Functions
//////////////////////////////////////////////////////

void printGiven(int *returnArray, int returnSize) {
    int i;

    printf("given: [ ");
    for (i=0; i<returnSize; i++) {
        printf("%d", returnArray[i]);
        if (i < (returnSize-1))
            printf(", ");
    }
    printf(" ]\n");
}

void printResult(int *returnArray, int returnSize) {
    int i;

    printf("result: [ ");
    for (i=0; i<returnSize; i++) {
        printf("%d", returnArray[i]);
        if (i < (returnSize-1))
            printf(", ");
    }
    printf(" ]\n");
}

//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////

// Brute force, O(n^2).  There are faster algorithms using fact that
// there is a single solution, so uses hash table and looks for
// existance of a complement of current value.
int *twoSum(int * nums, int numsSize, int target, int *returnSize) {
    int i, j;
    int *array = 0;
    *returnSize = 0;

    for (i=0; i<numsSize; i++) {
        for (j=0; j<numsSize; j++) {
            if (i != j) {
                if ((nums[i] + nums[j]) == target) {
                    *returnSize = 2;
                    array = (int *)malloc(2*sizeof(int));
                    array[0] = i;
                    array[1] = j;
                    return array;
                }
            }
        }
    }
    return 0;
}

//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int size;
    int *array;

    printf("two_sum.c:\n");
    {
        int nums[] = { 2,7,11,15 };
        array = twoSum(nums, sizeof(nums)/sizeof(int), 9, &size);
        printGiven(nums, sizeof(nums)/sizeof(int));
        printResult(array, size);
        if (array) { free(array); array = 0; }
    }
    {
        int nums[] = { 2,7,11,15,3,4,6 };
        array = twoSum(nums, sizeof(nums)/sizeof(int), 7, &size);
        printGiven(nums, sizeof(nums)/sizeof(int));
        printResult(array, size);
        if (array) { free(array); array = 0; }
    }
}

