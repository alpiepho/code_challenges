#include <stdio.h>
#include <stdlib.h>

// gcc remove_element.c -o runme ; ./runme

// Given an array nums and a value val, remove all instances of that value in-place and return the new length.

// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

// The order of elements can be changed. It doesn't matter what you leave beyond the new length.

// Example 1:

// Given nums = [3,2,2,3], val = 3,

// Your function should return length = 2, with the first two elements of nums being 2.

// It doesn't matter what you leave beyond the returned length.
// Example 2:

// Given nums = [0,1,2,2,3,0,4,2], val = 2,

// Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.

// Note that the order of those five elements can be arbitrary.

// It doesn't matter what values are set beyond the returned length.


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


int removeElement(int* nums, int numsSize, int val){
    int i,current;

    if (numsSize == 0) return 0;
    if (numsSize == 1 && nums[0] == val) return 0;

    current = 0;
    for (i=0; i<numsSize; i++) {
        nums[current] = nums[i];
        if (nums[i] != val) {
            current++;
        }
    }
    return current;
}


//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int result;

    printf("remove_element.c:\n");
    {
        int nums[] = { 3,2,2,3 };
        int numsSize = sizeof(nums)/sizeof(int);
        show(nums, numsSize);
        result = removeElement(nums, numsSize, 3);
        show(nums, result);
        printf("result: %d\n", result);
    }
    {
        int nums[] = { 0,1,2,2,3,0,4,2 };
        int numsSize = sizeof(nums)/sizeof(int);
        show(nums, numsSize);
        result = removeElement(nums, numsSize, 2);
        show(nums, result);
        printf("result: %d\n", result);
    }
    return 0;
}

