#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc fibanochi.c -o runme ; ./runme

// return nth in sequence:
// index:  0 1 2 3 4 5 6 7  8  9  10
// result: 0 1 1 2 3 5 8 13 21 34 55 ...

//////////////////////////////////////////////////////
// Support Functions
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////


int fib(int N){
    int result = 1;
    int nextLast, last = 0;

    if (N == 0) return 0;

    for(int i=1; i<N; i++) {
        nextLast = result;
        result += last;
        last = nextLast;
    }


    return result;
}

//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {

    printf("fibanochi.c:\n");

    printf("fib(0) : %d\n", fib(0));
    printf("fib(1) : %d\n", fib(1));
    printf("fib(2) : %d\n", fib(2));
    printf("fib(3) : %d\n", fib(3));
    printf("fib(4) : %d\n", fib(4));
    printf("fib(5) : %d\n", fib(5));
    printf("fib(6) : %d\n", fib(6));
    printf("fib(7) : %d\n", fib(7));
    printf("fib(8) : %d\n", fib(8));
    printf("fib(9) : %d\n", fib(9));
    printf("fib(10): %d\n", fib(10));

    return 0;
}

