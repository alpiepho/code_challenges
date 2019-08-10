#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc first_missing_positive.c -o runme ; ./runme

// Given an unsorted integer array, find the smallest missing positive integer.

// Example 1:

// Input: [1,2,0]
// Output: 3
// Example 2:

// Input: [3,4,-1,1]
// Output: 2
// Example 3:

// Input: [7,8,9,11,12]
// Output: 1
// Note:

// Your algorithm should run in O(n) time and uses constant extra space.

//////////////////////////////////////////////////////
// Support Functions
//////////////////////////////////////////////////////

void show(char *label, int *returnArray, int returnSize) {
    int i;

    printf("%s[ ", label);
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

int firstMissingPositive(int* nums, int numsSize){
    int i;
    int result = 1;

    for (i=0; i<numsSize; i++) {
        if (nums[i] > 0) {
            if (nums[i] >= result) 
                result = nums[i] + 1;
        }
    }

    return result;
}



//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int result;
    char **returnStrs;

    printf("first_missing_positive.c:\n");
    {
        int nums[] = { 1,2,0 };
        int numsSize = sizeof(nums)/sizeof(int);
        show("given: ", nums, numsSize);
        result = firstMissingPositive(nums, numsSize);
        printf("result: %d\n", result);
    }
    {
        int nums[] = { 3,4,-1,1 };
        int numsSize = sizeof(nums)/sizeof(int);
        show("given: ", nums, numsSize);
        result = firstMissingPositive(nums, numsSize);
        printf("result: %d\n", result);
    }
    {
        int nums[] = { 7,8,9,11,12 };
        int numsSize = sizeof(nums)/sizeof(int);
        show("given: ", nums, numsSize);
        result = firstMissingPositive(nums, numsSize);
        printf("result: %d\n", result);
    }
    {
        int nums[] = { 2,1 };
        int numsSize = sizeof(nums)/sizeof(int);
        show("given: ", nums, numsSize);
        result = firstMissingPositive(nums, numsSize);
        printf("result: %d\n", result);
    }

    return 0;
}

