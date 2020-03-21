#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX(a,b) ( (a) > (b) ? (a) : (b))
#define MIN(a,b) ( (a) < (b) ? (a) : (b))

// gcc water.c -o runme ; ./runme

// Paraphrase of the original problem:

// Given an array of "block" heights, determine the total water that can be held

// Exampe 1:
// [1,0,1]  returns 1
//
//  XoX  has a single "block" that can be filled (count the 'o')


// Exampe 1:
// [3,0,1,0,0,2]  returns 7
//
//  X
//  XooooX
//  XoXooX  has 7 "blocks" that can be filled (count the 'o')


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


//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////

static int *stack = 0;
int stack_max = 0;
int stack_idx = -1;

void stack_init(int length) {
    stack = (int *)malloc(sizeof(int) * length);
    stack_max = length;
    stack_idx = -1;
}

void stack_free(void) {
    if (stack) free(stack);
    stack = 0;
    stack_max = 0;
    stack_idx = -1;
}

void stack_push(int v) {
    if (stack_idx < (stack_max-1)) {
        stack_idx += 1;
        stack[stack_idx] = v;
    }
}

int stack_pop(void) {
    if (stack_idx >= 0) {
        stack_idx -= 1;
        return stack[stack_idx+1];
    }
    return -1;
}

int stack_size(void) {
    return (stack_idx+1);
}
// void stack_dump(void) {
//     int i;
//     printf("stack_max: %d\n", stack_max);
//     printf("stack_idx: %d\n", stack_idx);
//     printf("stack: \n");
//     for (i=0; i<=stack_idx; i++) printf("%d\n", stack[i]);
//     printf("---\n");
// }

int water(int * nums, int numsSize) {
    int debug = 0;
    int total = 0;
    int index = 0;
    int left = 0;
    int right = 0;
    int maybe_right = 0;
    int maybe_count = 0;
    int value = -1;

    if (numsSize < 3) {
        return 0;
    }
    stack_init(numsSize);

    // find first left
    for (index=0; index < numsSize; index++) {
        if (nums[index] > 0) {
            left = nums[index];
            break;
        }
    }
    // move index past first left
    index += 1;

    // find next right
    for (; index < numsSize; index++) {
        right = nums[index];
        if (debug) printf("index, left, right= %d, %d, %d\n", index, left, right);
        // Scenerio:
        //       X
        //  XooooX
        //  XoXooX...
        //       ^
        if (right >= left) {
            value = stack_pop();
            while (value != -1) {
                total += MIN(left, right) - value;
                if (debug) printf("mid: pop value: %d\n", value);
                if (debug) printf("add           : %d\n", MIN(left, right) - value);
                if (debug) printf("total         : %d\n", total);
                value = stack_pop();
            }
            left = right;
            maybe_right = 0;
            maybe_count = 0;
        }
        // Scenerio:
        //  X    
        //  XooooX
        //  XoXooX...
        //       ^
        else if (right > 0) {
            if (debug) printf("push : %d\n", right);
            stack_push(right);
            if (debug) printf("maybe: %d\n", right);
            maybe_right = right;
            maybe_count += 1;
        }
        // Scenerio:
        //  X    
        //  Xoooo
        //  XoXoo...
        //      ^
        else {
            if (debug) printf("push : %d\n", right);
            stack_push(right);
        }
    }

    // if still items on stack, then need to add
    if (maybe_right) {
        value = stack_pop();
        while (value != -1) {
            if (debug) printf("end : pop value: %d\n", value);
            if (stack_size() < maybe_count) {
                total += MIN(left, maybe_right) - value;
                if (debug) printf("add            : %d\n", MIN(left, maybe_right) - value);
                if (debug) printf("total          : %d\n", total);
            }
            value = stack_pop();
        }
    }

    stack_free();
    return total;
}

//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {

    printf("water.c:\n");
    {
        int nums[] = { 1,0,1 };
        int numsSize = sizeof(nums)/sizeof(int);
        int amount = water(nums, numsSize);
        printGiven(nums, numsSize);
        printf("Expect: %d\n", 1);
        printf("Result: %d\n\n", amount);
    }
    {
        int nums[] = { 0,0,1,0,1 };
        int numsSize = sizeof(nums)/sizeof(int);
        int amount = water(nums, numsSize);
        printGiven(nums, numsSize);
        printf("Expect: %d\n", 1);
        printf("Result: %d\n\n", amount);
    }
    {
        int nums[] = { 0,0,1,0,1,0 };
        int numsSize = sizeof(nums)/sizeof(int);
        int amount = water(nums, numsSize);
        printGiven(nums, numsSize);
        printf("Expect: %d\n", 1);
        printf("Result: %d\n\n", amount);
    }
    {
        int nums[] = { 3,0,1,0,5,0 };
        int numsSize = sizeof(nums)/sizeof(int);
        int amount = water(nums, numsSize);
        printGiven(nums, numsSize);
        printf("Expect: %d\n", 8);
        printf("Result: %d\n\n", amount);
    }
    {
        int nums[] = { 3,0,1,0,0,0 };
        int numsSize = sizeof(nums)/sizeof(int);
        int amount = water(nums, numsSize);
        printGiven(nums, numsSize);
        printf("Expect: %d\n", 1);
        printf("Result: %d\n\n", amount);
    }
    {
        int nums[] = { 5,0,1,3,0,0 };
        int numsSize = sizeof(nums)/sizeof(int);
        int amount = water(nums, numsSize);
        printGiven(nums, numsSize);
        printf("Expect: %d\n", 5);
        printf("Result: %d\n\n", amount);
    }


    {
        int nums[] = { 1,0,2,1,3,2,4 };
        int numsSize = sizeof(nums)/sizeof(int);
        int amount = water(nums, numsSize);
        printGiven(nums, numsSize);
        printf("Expect: %d\n", 3);
        printf("Result: %d\n\n", amount);
    }

}

