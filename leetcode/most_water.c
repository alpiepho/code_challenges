#include <stdio.h>
#include <stdlib.h>

// gcc most_water.c -o runme ; ./runme

// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container and n is at least 2.

// Example:

// Input: [1,8,6,2,5,4,8,3,7]
// Output: 49

//////////////////////////////////////////////////////
// Support Functions
//////////////////////////////////////////////////////


void show(int *nums, int NumsSize) {
    int i;

    printf("given: [ ");
    for (i=0; i<NumsSize; i++) {
        printf("%d", nums[i]);
        if (i < (NumsSize-1))
            printf(", ");
    }
    printf(" ]\n");
}

//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////

#define MAX(a,b) ( (a) > (b) ? (a) : (b))
#define MIN(a,b) ( (a) < (b) ? (a) : (b))

int maxArea(int* height, int heightSize){
    int i, j;
    int current;
    int best = 0;

    for (i=0; i<heightSize; i++) {
        for (j=i+1; j<heightSize; j++) {
            current = MIN(height[i], height[j]) * (j-i);
            best = MAX(best, current);
        }
    }

    return best;
}



//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int result;

    printf("most_water.c:\n");
    {
        int nums[] = { 1,8,6,2,5,4,8,3,7 };
        int numsSize = sizeof(nums)/sizeof(int);
        show(nums, numsSize);
        result = maxArea(nums, numsSize);
        printf("result: %d\n", result);
    }
    return 0;
}

