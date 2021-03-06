#include <stdio.h>
#include <stdlib.h>

// gcc permutations.c -o runme ; ./runme

// Given a collection of distinct integers, return all possible permutations.

// Example:

// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]


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

void dump(int **returnArrays, int returnSize, int* returnColumnSizes){
    int i, j, n;

    printf("returnColumnSizes: [ ");
    for (i=0; i<returnSize; i++) {
        printf("%d", returnColumnSizes[i]);
        if (i < (returnSize-1))
            printf(", ");
    }
    printf(" ]\n");

    printf("returnArrays: [\n");
    for (j=0; j<returnSize; j++) {
        n = returnColumnSizes[j];
        printf("  %d: [ ", j);
        for (i=0; i<n; i++) {
            printf("%d", returnArrays[j][i]);
            if (i < (n-1))
                printf(", ");
        }
        printf(" ]\n");
    }
    printf(" ]\n");

}

// NOTE: does not null base pointers (just couldnt send int ***)
void cleanup(int **returnArrays, int returnSize, int* returnColumnSizes){
    int i;
    int *p;

    free(returnColumnSizes);

    if (returnArrays) {
        for (i=0; i<returnSize; i++) {
            p = returnArrays[i];
            if (p) free(p);
        }

        free(returnArrays);
    }
}

//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////

void swap(int *x, int *y) {
	int temp; 
	temp = *x; 
	*x = *y; 
	*y = temp; 
} 

void permute_inner(int* nums, int numsSize, int **buffer, int *col, int l, int r) { 
    int i, j; 
    if (l == r) {
        show("", nums, numsSize);
        for (j=0; j<numsSize; j++) buffer[*col][j] = nums[j];
        *col += 1;
    }
    else { 
        for (i = l; i <= r; i++) { 
            swap((nums+l), (nums+i)); 
            permute_inner(nums, numsSize, buffer, col, l+1, r); 
            swap((nums+l), (nums+i)); //backtrack 
        } 
    } 
} 

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i, j, n, col = 0;
    int total;
    int *array;
    int **buffer;

    // number of permutations is factorial 1*2*3...*n when given numSize == n  
    for (total = 1, i = 1; i <= numsSize; i++) total *= i;
    *returnSize = total;

    // all columns are same size, n
    array = (int *)malloc(sizeof(int) * total);
    for (i=0; i < total; i++) array[i] = numsSize;
    *returnColumnSizes = array;

    buffer = (int **)malloc(sizeof(int *) * total);
    for (j=0; j < total; j++) {
        n = array[j];
        buffer[j] = (int *)malloc(sizeof(int) * n);
        // DEBUG
        // for (i=0; i<n; i++) {
        //     buffer[j][i] = i;
        // }
    }

    // recursively generate permutations
    permute_inner(nums, numsSize, buffer, &col, 0, numsSize-1); 

    return buffer;
}


//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int returnSize;
    int **returnArrays;
    int *returnColumnSizes;

    printf("permutations.c:\n");
    {
        int nums[] = { 1,2 };
        int numsSize = sizeof(nums)/sizeof(int);
        show("given: ", nums, numsSize);
        returnArrays = permute(nums, numsSize, &returnSize, &returnColumnSizes);
        dump(returnArrays, returnSize, returnColumnSizes);
        cleanup(returnArrays, returnSize, returnColumnSizes);
    }
    {
        int nums[] = { 1,2,3 };
        int numsSize = sizeof(nums)/sizeof(int);
        show("given: ", nums, numsSize);
        returnArrays = permute(nums, numsSize, &returnSize, &returnColumnSizes);
        dump(returnArrays, returnSize, returnColumnSizes);
        cleanup(returnArrays, returnSize, returnColumnSizes);
    }

    return 0;
}

