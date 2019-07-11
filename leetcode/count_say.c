#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc count_say.c -o runme ; ./runme

// The count-and-say sequence is the sequence of integers with the first five terms as following:

// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.

// Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

// Note: Each term of the sequence of integers will be represented as a string.

 

// Example 1:

// Input: 1
// Output: "1"
// Example 2:

// Input: 4
// Output: "1211"


//////////////////////////////////////////////////////
// Support Functions
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////


char * countAndSay(int n){
    int seqN, i, j, k;
    char *buffer1, *buffer2;

    buffer1 = (char *)malloc(10240);
    buffer2 = (char *)malloc(10240);

    if (n==0) return "";
    buffer2[0] = '1';
    buffer2[1] = 0;

    for (seqN = 1; seqN<n; seqN++) {
        memcpy(buffer1, buffer2, 10240);
        i = j = k = 0;
        // all digits
        while (buffer1[i]) {
            // count number of this digit
            j = i+1;
            // move past duplicates
            while (buffer1[j] == buffer1[i]) j++;

            // set this round:  count = j-i and val = buffer[i]
            buffer2[k++] = (j-i) + '0';
            buffer2[k++] = buffer1[i];
            buffer2[k] = 0;
            i = j;
        }
    }

    free(buffer1);
    printf("%ld\n", strlen(buffer2));
    return buffer2;
}

//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {

    printf("count_say.c:\n");

    printf("result: %s\n", countAndSay(1));
    printf("result: %s\n", countAndSay(4));
    //printf("result: %s\n", countAndSay(30));

    return 0;
}

