#include <stdio.h>
#include <stdlib.h>

// gcc insert_position.c -o runme ; ./runme

// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You may assume no duplicates in the array.

// Example 1:

// Input: [1,3,5,6], 5
// Output: 2
// Example 2:

// Input: [1,3,5,6], 2
// Output: 1
// Example 3:

// Input: [1,3,5,6], 7
// Output: 4
// Example 4:

// Input: [1,3,5,6], 0
// Output: 0

#define SHOW

//////////////////////////////////////////////////////
// Support Functions
//////////////////////////////////////////////////////


void show(int *returnArray, int returnSize) {
#ifdef SHOW
    int i;

    printf("given: [ ");
    for (i=0; i<returnSize; i++) {
        printf("%d", returnArray[i]);
        if (i < (returnSize-1))
            printf(", ");
    }
    printf(" ]\n");
#endif
}

//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////


int searchInsert(int* nums, int numsSize, int target){
    int i = 0;

    for (i=0; i<numsSize; i++) {
        if (target <= nums[i])
            return i;
    }
    return numsSize;
}


//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int result;

    printf("insert_position.c:\n");
    {
        int nums[] = { 1,3,5,6 };
        int numsSize = sizeof(nums)/sizeof(int);
        show(nums, numsSize);
        result = searchInsert(nums, numsSize, 5);
        show(nums, result);
        printf("result: %d\n", result);
    }
    {
        int nums[] = { 1,3,5,6 };
        int numsSize = sizeof(nums)/sizeof(int);
        show(nums, numsSize);
        result = searchInsert(nums, numsSize, 2);
        show(nums, result);
        printf("result: %d\n", result);
    }
    {
        int nums[] = { 1,3,5,6 };
        int numsSize = sizeof(nums)/sizeof(int);
        show(nums, numsSize);
        result = searchInsert(nums, numsSize, 7);
        show(nums, result);
        printf("result: %d\n", result);
    }
    {
        int nums[] = { 1,3,5,6 };
        int numsSize = sizeof(nums)/sizeof(int);
        show(nums, numsSize);
        result = searchInsert(nums, numsSize, 0);
        show(nums, result);
        printf("result: %d\n", result);
    }
    return 0;
}

