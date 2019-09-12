#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc struct_macro.c -o runme ; ./runme

// create macro to return byte offset of field in a struct

//////////////////////////////////////////////////////
// Support Functions
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////

typedef struct my_new_struct {
    char A;
    char B;
    char C;
    char D;
    char a;
    int aa;
    long int b;
    char c;
} new_struct;

// assumes s is an instance of the struct and f is s.f, a field of the struct
// NOTE: I'm not certain, but I think interviewer was looking for solution 
// that took struct itself...not sure if pre-processor macro cound do that
#define STRUCT_OFFSET(s, f) ((int)&f - (int)&s)

//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    new_struct test;

    printf("struct_macro.c:\n");

    printf("STRUCT_OFFSET(test, test.b) : %d\n", STRUCT_OFFSET(test, test.b));

    return 0;
}

