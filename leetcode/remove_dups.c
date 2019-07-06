#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// gcc remove_dups.c -o runme ; ./runme

// Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.


//////////////////////////////////////////////////////
// Support Functions
//////////////////////////////////////////////////////
void dump(int* nums, int numsSize){
    int i;

    printf("[ ");
    for (i=0; i< numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("]\n");
}

//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////
int removeDuplicates(int* nums, int numsSize){
    int i,current;

    if (numsSize == 0 || nums == 0) return 0;
    if (numsSize == 1 ) return 1;

    current = 0;
    //dump(nums, numsSize);
    for (i=1; i<numsSize; i++) {
        if (nums[i] != nums[current]) {
            nums[current+1] = nums[i];
            current++;
        }
        //dump(nums, numsSize);
    }

    return current+1;
}


//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    printf("remove_dups.c:\n");
    {
        int nums[] = { 1,1,2 };
        printf("input: 1,1,2  result: %d\n", removeDuplicates(nums, 3));
    }
    {
        int nums[] = { 1,1,1,2 };
        printf("input: 1,1,1,2  result: %d\n", removeDuplicates(nums, 4));
    }
    {
        int nums[] = { 0,0,1,1,1,2,2,3,3,4 };
        printf("input: 0,0,1,1,1,2,2,3,3,4  result: %d\n", removeDuplicates(nums, 10));
    }
    return 1;
}

