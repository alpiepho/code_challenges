#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// gcc valid_parens.c -o runme ; ./runme

// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.

// Example 1:

// Input: "()"
// Output: true
// Example 2:

// Input: "()[]{}"
// Output: true
// Example 3:

// Input: "(]"
// Output: false
// Example 4:

// Input: "([)]"
// Output: false
// Example 5:

// Input: "{[]}"
// Output: true

//////////////////////////////////////////////////////
// Support Functions
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////

static char *stack = 0;
int stack_max = 0;
int stack_idx = -1;

void stack_init(int length) {
    stack = (char *)malloc(length);
    stack_max = length;
    stack_idx = -1;
}

void stack_free(void) {
    if (stack) free(stack);
    stack = 0;
    stack_max = 0;
    stack_idx = -1;
}

void stack_push(char c) {
    if (stack_idx < (stack_max-1)) {
        stack_idx += 1;
        stack[stack_idx] = c;
    }
}

char stack_pop(void) {
    if (stack_idx >= 0) {
        stack_idx -= 1;
        return stack[stack_idx+1];
    }
    return 0xff;
}

// char stack_peek(void) {
//     if (stack_idx >= 0) {
//         return stack[stack_idx];
//     }
//     return 0xff;
// }

// void stack_dump(void) {
//     int i;
//     printf("stack_max: %d\n", stack_max);
//     printf("stack_idx: %d\n", stack_idx);
//     printf("stack: \n");
//     for (i=0; i<=stack_idx; i++) printf("%c\n", stack[i]);
//     printf("---\n");
// }

bool isValid(char * s){
    char c;
    if (s == 0) return false;
    stack_init(strlen(s)/2+1);

    while (*s) {
        //stack_dump();
        //printf("s: %s\n", s);
        if (*s == '(' || *s == '[' || *s == '{') stack_push(*s);
        if (*s == ')' || *s == ']' || *s == '}') {
            c = stack_pop();
            if (    ((*s == ')') && (c != '(')) ||
                    ((*s == ']') && (c != '[')) ||
                    ((*s == '}') && (c != '{'))
                ) {
                stack_free();
                return false;
            }
        }
        s++;
    }
    if (stack_idx >= 0) {
        stack_free();
        return false;
    }
    stack_free();
    return true;
}


//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int size;
    int *array;

    printf("valid_parens.c:\n");
    printf("input: ()     result: %d\n", isValid("()"));
    printf("input: ()[]{} result: %d\n", isValid("()[]{}"));
    printf("input: (]     result: %d\n", isValid("(]"));
    printf("input: ([)]   result: %d\n", isValid("([)]")); 
    printf("input: {[]}   result: %d\n", isValid("{[]}")); 
    printf("input: ]      result: %d\n", isValid("]")); 
    printf("input: [      result: %d\n", isValid("[")); 
}

