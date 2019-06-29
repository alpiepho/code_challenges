// gcc count.c -o runme ; ./runme

#include <stdio.h>

// find index of FIRST x in sorted list
int find1(int *data, int start, int end, int x) {
    int mid = start + (end - start)/2;

    //printf("start: %d  end: %d   mid %d   data[mid]: %d\n", start, end, mid, data[mid]);
    if (start >= end)   return -1;
    if (x == data[mid]) {
        if (start < mid  && x == data[mid-1]) return find1(data, start, mid, x);
        else return mid;
    }
    if (x < data[mid]) return find1(data, start, mid-1, x);
    if (x > data[mid]) return find1(data, mid+1,   end, x);
    return -1;
}

// find index of LAST x in sorted list
int find2(int *data, int start, int end, int x) {
    int mid = start + (end - start)/2;

    //printf("start: %d  end: %d   mid %d   data[mid]: %d\n", start, end, mid, data[mid]);
    if (start >= end)   return -1;
    if (x == data[mid]) {
        if (mid < end  && x == data[mid+1]) return find2(data, mid,  end, x);
        else return mid;
    }
    if (x < data[mid]) return find2(data, start,  mid-1, x);
    if (x > data[mid]) return find2(data, mid+1,    end, x);
    return -1;
}

// count number of x occurances
int count(int *data, int start, int end, int x) {
    int first;
    int last;
    first = find1(data, start, end, x);
    last  = find2(data, start, end, x);
    if (first != -1 && last != -1 && last >= first)
        return (last-first+1);
    return 0;
}

#define MAX_LISTS 6
#define MAX_LIST_LENGTH 10+2
#define INDEX_START  0
#define INDEX_END    1
#define INDEX_COUNT  2
#define INDEX_LIST   4

int main(void) {
    int x;
    int start;
    int end;
    int expected;
    int *data;
    int result;
    int all[MAX_LISTS][MAX_LIST_LENGTH] =
    {   // start, end,   count    list...
        //               for 2
        {      0,   6,       3,   1, 1, 2, 2, 2, 3 },
        {      0,   5,       3,   1, 1, 2, 2, 2 },
        {      0,   2,       0,   1, 1, 3 },
        {      0,   5,       2,   1, 1, 2, 2, 5 },
        {      0,   5,       3,   0, 1, 2, 2, 2 },
        {      0,   8,       6,   1, 1, 2, 2, 2, 2, 2, 2, 9 }
    };

    printf("count.c:\n");

    x = 2;
    for (int i=0; i < MAX_LISTS; i++) {
        start    = all[i][INDEX_START];
        end      = all[i][INDEX_END];
        expected = all[i][INDEX_COUNT];
        data     = &all[i][INDEX_LIST];
        result   = count(data, start, end, x);
        //printf("CASE: expected %d != actual %d (list# %d)\n", expected, result, i);
        if (result != expected) {
            printf("FAILED: expected %d != actual %d (list# %d)\n", expected, result, i);
        }
    }
    return 0;
}
