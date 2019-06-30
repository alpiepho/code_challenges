#include <stdio.h>
#include <stdlib.h>

//#define USE_INT_ACCUM
#define USE_ARRAY_ACCUM
#define USE_STRING

// gcc binary_counter.c -o runme ; ./runme

// generate all the N length binary code/strings given N.
// for example:
// counter(3) will produce:
//   0 0 0
//   0 0 1
//   0 1 1
//   1 0 0
//   1 0 1
//   1 1 0
//   1 1 1

//////////////////////////////////////////////////////
// Support Functions
//////////////////////////////////////////////////////

static int size;

#ifdef USE_INT_ACCUM
unsigned int accum;

void printSize(void) {
    printf("\nSize: %d\n", size);
}

void printAccum(void) {
    printf("%04x\n", accum);
}

void clearAccum(void) {
    accum = 0;
}

int incAccum(void) {
    accum += 1;
    if (accum & (1<<size))
        return 1;
    return 0;
}

void initAccum(void) {
}

void freeAccum(void) {
}

#endif // USE_INT_ACCUM

#ifdef USE_ARRAY_ACCUM
static int *accum;
static char *accumStr;

void printSize(void) {
    printf("\nSize: %d\n", size);
}

void printAccum(void) {
    int i;

#ifdef USE_STRING
    // 30% faster to build string first
    // print MSB -> LSB
    for (i=size-1; i>=0; i--) {
        accumStr[i] = ('0' + accum[(size-1)-i]);
    }
    accumStr[size] = 0;
    printf("%s\n", accumStr);
#else
    // print MSB -> LSB
    for (i=size-1; i>=0; i--) {
        printf("%d", accum[i]);
    }
    printf("\n");
#endif
}

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
    accumStr = (char *)malloc(size+1);
    accum = (int *)malloc(sizeof(int) * size);
    clearAccum();

}

void freeAccum(void) {
    size = 0;
    if (accum) free(accum);
    accum = 0;
    if (accumStr) free(accumStr);
    accumStr = 0;
}
#endif // USE_ARRAY_ACCUM

//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////

// assume accum initialized to all zero
void generate(int given) 
{ 
    int rollOver = 0;

    size = given;
    initAccum();
    printSize();

    while (!rollOver) {
        printAccum();
        rollOver = incAccum();
    }

    initAccum();
} 

//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    printf("binary_counter.c:\n");
    generate(3);
    //generate(20);
}

