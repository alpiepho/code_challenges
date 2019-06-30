#include <stdio.h>
#include <stdlib.h>

// gcc any_sum.c -o runme ; ./runme

// Expand 'Two Sum' to look for any number values from nums that sum to the value 'target'.  Each num is used once.  Size of solution array can be 1 to n.

// Given nums = [2,4,6,1], target = 9,
// Because nums[0] + nums[2] + nums[3] = 2 + 6 + 1 = 9
// Return [0, 2, 3]


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

// Build int array as accumlator so we can use the bits
// as a mask of indexes that will be used to test sum(num[index set]) == target
static int size;
static int *accum;

void clearAccum(void) {
    int i;
    for (i=0; i<size; i++) accum[i] = 0;
}
int incAccum(void) {
    int i = 0;

    while (i < size) {
        accum[i] += 1;
        if (accum[i] <= 1)
            return 0;
        else {
            accum[i] = 0;
            i += 1;      
        }
    }
    return 1;
}
void initAccum(void) {
    accum = (int *)malloc(sizeof(int) * size);
    clearAccum();
}
void freeAccum(void) {
    size = 0;
    if (accum) free(accum);
    accum = 0;
}


int *anySum(int * nums, int numSize, int target, int *returnSize) {
    int i, j;
    int rollOver = 0;
    int *array = 0;
    *returnSize = 0;

    size = numSize;
    initAccum();

    while (!rollOver) {
        printAccum();
        if (sumFromAccum() == target) {
            // get number bits set
            // build array
            // set index from bits, ie index == position
            // set resturnSize
            // return

        }
        rollOver = incAccum();
    }
    freeAccum();
    return 0;
}

//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int size;
    int *array;

    printf("any_sum.c:\n");
    {
        int nums[] = { 2,4,6,1};
        array = anySum(nums, sizeof(nums)/sizeof(int), 9, &size);
        printGiven(nums, sizeof(nums)/sizeof(int));
        printResult(array, size);
        if (array) { free(array); array = 0; }
    }
}

