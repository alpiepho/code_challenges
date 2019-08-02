#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc permutations_str.c -o runme ; ./runme

// string example from 
// https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/


//////////////////////////////////////////////////////
// Support Functions
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////

// Function to swap values at two pointers
void swap(char *x, char *y) 
{ 
	char temp; 
	temp = *x; 
	*x = *y; 
	*y = temp; 
} 

// Function to print permutations of string 
// This function takes three parameters: 
// 1. String 
// 2. Starting index of the string 
// 3. Ending index of the string.
void permute(char *a, int l, int r) 
{ 
    int i; 
    if (l == r) 
        printf("%s\n", a); 
    else
    { 
        for (i = l; i <= r; i++) 
        { 
            swap((a+l), (a+i)); 
            permute(a, l+1, r); 
            swap((a+l), (a+i)); //backtrack 
        } 
    } 
} 


//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int result;

    printf("permutations_str.c:\n");
    {
        char str[] = "ABC"; 
        int n = strlen(str); 
        printf("-----\n");
        permute(str, 0, n-1); 
    }
    {
        char str[] = "1"; 
        int n = strlen(str); 
        printf("-----\n");
        permute(str, 0, n-1); 
    }
    {
        char str[] = "12"; 
        int n = strlen(str); 
        printf("-----\n");
        permute(str, 0, n-1); 
    }
    {
        char str[] = "123"; 
        int n = strlen(str); 
        printf("-----\n");
        permute(str, 0, n-1); 
    }
    {
        char str[] = "1234"; 
        int n = strlen(str); 
        printf("-----\n");
        permute(str, 0, n-1); 
    }

    return 0;
}

