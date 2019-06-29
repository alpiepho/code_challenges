// gcc doublestack.c -o runme ; ./runme

// TODO
// define simple stack
// 
// init
// add 
// remove
// interview qeustion ask to track times, provide last, and provide smallest
// solution is a stack for times, with a second stack can be peeked to see if 
// new time is less OR EQUAL.  if time is popped and popped time is EQUAL
// to top stack of second stack.
// TODO: have implemented the basic stack, should finish this interview problem

#include <stdio.h>
#include <stdlib.h>

//#define NULL 0

struct Buffer {
    char *stack;
    int length;
    int total;
    int tail;
};

int init(int length, struct Buffer **buffer) {
    *buffer = (struct Buffer *)malloc(sizeof(struct Buffer));
    if (buffer == NULL) return -1;
    (*buffer)->stack = (char *)malloc(sizeof(char) * length);
    if ((*buffer)->stack == NULL) {
        free(buffer);
        *buffer = NULL;
        return -2;
    }
    (*buffer)->length = length;
    (*buffer)->total = 0;
    (*buffer)->tail = -1;

    return 0;
}

void deinit(struct Buffer **buffer) {
    if (*buffer == NULL) return; // already cleared
    if ((*buffer)->stack) free((*buffer)->stack);
    free(*buffer);
    *buffer = NULL;
}

int push(struct Buffer *buffer, char c) {
    if (buffer->total == buffer->length) return -1;
    if (buffer->total == 0) { 
        buffer->tail = 0;
    }
    buffer->stack[buffer->tail] = c;
    buffer->total += 1;
    buffer->tail += 1;
    if (buffer->tail >= buffer->length) buffer->tail = 0;
    return 0;
}

int pop(struct Buffer *buffer, char *c) {
    if (buffer->total == 0) return -1;
    buffer->total -= 1;
    buffer->tail -= 1;
    *c = buffer->stack[buffer->tail];
    if (buffer->total == 0) {
        buffer->tail = -1;
    }
    return 0;
}

void dump(struct Buffer *buffer) {
    printf("buffer:\n");
    printf("  length: %d\n", buffer->length);
    printf("  total:  %d\n", buffer->total);
    printf("  tail:   %d\n", buffer->tail);
    printf("  stack:  ");
    for (int i = 0; i < buffer->length; i++) {
        printf("%c, ", buffer->stack[i]);
    }
    printf("\n");
}

int main(void) {
    int test = 1;
    printf("doublestack.c:\n");
    {
        struct Buffer *buffer;
        init(5, &buffer);
        printf(">>> case %d:\n", test++);
        //dump(buffer);
        deinit(&buffer);
    }
    {
        int result;
        char c;
        struct Buffer *buffer;
        init(5, &buffer);
        printf(">>> case %d:\n", test++);
        push(buffer, '1');
        //dump(buffer);
        result = pop(buffer, &c);
        //dump(buffer);
        if (c != '1')
            printf("FAILED\n");
        result = pop(buffer, &c);
        //dump(buffer);
        if (result >= 0)
            printf("FAILED\n");
        deinit(&buffer);
    }
    {
        int result;
        char c;
        struct Buffer *buffer;
        init(5, &buffer);
        printf(">>> case %d:\n", test++);
        push(buffer, '1');
        push(buffer, '2');
        push(buffer, '3');
        push(buffer, '4');
        push(buffer, '5');
        dump(buffer);
        result = push(buffer, '6');
        if (result >= 0)
            printf("FAILED\n");
        deinit(&buffer);
    }
    {
        int result;
        char c;
        struct Buffer *buffer;
        init(5, &buffer);
        printf(">>> case %d:\n", test++);
        push(buffer, '1');
        push(buffer, '2');
        push(buffer, '3');
        push(buffer, '4');
        push(buffer, '5');
        pop(buffer, &c);
        push(buffer, '6');
        dump(buffer);
        deinit(&buffer);
    }
}

