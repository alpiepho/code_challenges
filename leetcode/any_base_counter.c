#include <stdio.h>
#include <stdlib.h>

// gcc any_base_counter.c -o runme ; ./runme

// Given integers representing the max value for each digit, run a counter with for those digits.

// Example: [1,1]
// digits of place 0: 0, 1
// digits of place 1: 0, 1
// count up:
// 00
// 01
// 10
// 11

// Example: [9,9]
// digits of place 0: 0-9
// digits of place 1: 0-9
// count up:
// 00
// 01
// ...
// 99

// Example: [1,2]
// digits of place 0: 0, 1, 2
// digits of place 1: 0, 1
// count up:
// 00
// 01
// 02
// 10
// 11
// 12

// Why?  Image a problem where you want the permutations of the leters of a phone.  Some have 3 letters,
// others have 4 letters possible.  With some simple mapping of numbers to letters, we can use this
// counter to get the permutations.  Besides, its kind of fun.

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

void dump(int **returnArrays, int returnSize, int* returnColumnSizes, int show_as_hex){
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
            if (show_as_hex)
                printf("%x", returnArrays[j][i]);
            else
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

void counter_increment(int* nums, int numsSize, int* accum){
    int place = numsSize-1;

    accum[place] += 1;
    // work backwards, add 1 to buffer[col][n] and carry if needed to n-1
    while (accum[place] > nums[place]) {
        accum[place] = 0; // reset place
        if (place == 0)
            break;         // have we maxed out
        if (place > 0) accum[place-1] += 1; // carry to next plae
        place -= 1;
    }
}

int** counter(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i, j, n, col = 0;
    int total = 1;
    int *array;
    int **buffer;
    int *accum;

    for (i = 0; i < numsSize; i++) {
        total *= (nums[i]+1);     
    } 
    *returnSize = total;

    // all columns are same size, n
    array = (int *)malloc(sizeof(int) * total);
    for (i=0; i < total; i++) array[i] = numsSize;
    *returnColumnSizes = array;

    buffer = (int **)malloc(sizeof(int *) * total);
    for (j=0; j < total; j++) {
        n = array[j];
        buffer[j] = (int *)malloc(sizeof(int) * n);
    }

    accum = (int *)malloc(sizeof(int) * total);
    for (i=0; i<total; i++) {
        accum[i] = 0;
    }

    // run counter
    // copy accum
    n = array[0];
    for (i=0; i<n; i++) {
        buffer[0][i] = accum[i];
    }
    for (col=1; col<total; col++) {
        counter_increment(nums, numsSize, accum); 
        // copy accum
        n = array[col];
        for (i=0; i<n; i++) {
            buffer[col][i] = accum[i];
        }
    }

    free(accum);
    return buffer;
}


//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int returnSize;
    int **returnArrays;
    int *returnColumnSizes;

    printf("any_base_counter.c:\n");
    {
        int show_as_hex = 0;
        int nums[] = { 1,1 };
        int numsSize = sizeof(nums)/sizeof(int);
        show("given: ", nums, numsSize);
        returnArrays = counter(nums, numsSize, &returnSize, &returnColumnSizes);
        dump(returnArrays, returnSize, returnColumnSizes, show_as_hex);
        cleanup(returnArrays, returnSize, returnColumnSizes);
    }
    {
        int show_as_hex = 0;
        int nums[] = { 9 };
        int numsSize = sizeof(nums)/sizeof(int);
        show("given: ", nums, numsSize);
        returnArrays = counter(nums, numsSize, &returnSize, &returnColumnSizes);
        dump(returnArrays, returnSize, returnColumnSizes, show_as_hex);
        cleanup(returnArrays, returnSize, returnColumnSizes);
    }
    {
        int show_as_hex = 1;
        int nums[] = { 15 };
        int numsSize = sizeof(nums)/sizeof(int);
        show("given: ", nums, numsSize);
        returnArrays = counter(nums, numsSize, &returnSize, &returnColumnSizes);
        dump(returnArrays, returnSize, returnColumnSizes, show_as_hex);
        cleanup(returnArrays, returnSize, returnColumnSizes);
    }
    {
        int show_as_hex = 0;
        int nums[] = { 3,2,1 };
        int numsSize = sizeof(nums)/sizeof(int);
        show("given: ", nums, numsSize);
        returnArrays = counter(nums, numsSize, &returnSize, &returnColumnSizes);
        dump(returnArrays, returnSize, returnColumnSizes, show_as_hex);
        cleanup(returnArrays, returnSize, returnColumnSizes);
    }
    {
        int show_as_hex = 0;
        int nums[] = { 2,2 };
        int numsSize = sizeof(nums)/sizeof(int);
        show("given: ", nums, numsSize);
        returnArrays = counter(nums, numsSize, &returnSize, &returnColumnSizes);
        dump(returnArrays, returnSize, returnColumnSizes, show_as_hex);
        cleanup(returnArrays, returnSize, returnColumnSizes);
    }

    return 0;
}

