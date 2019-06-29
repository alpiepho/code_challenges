// gcc queue.c -o runme ; ./runme

// TODO
// define api for circular queue
// init
// add 
// remove

#include <stdio.h>
#include <stdlib.h>

//#define NULL 0

struct Buffer {
    char *queue;
    int length;
    int total;
    int head;
    int tail;
};

int init(int length, struct Buffer **buffer) {
    *buffer = (struct Buffer *)malloc(sizeof(struct Buffer));
    if (buffer == NULL) return -1;
    (*buffer)->queue = (char *)malloc(sizeof(char) * length);
    if ((*buffer)->queue == NULL) {
        free(buffer);
        *buffer = NULL;
        return -2;
    }
    (*buffer)->length = length;
    (*buffer)->total = 0;
    (*buffer)->head = -1;
    (*buffer)->tail = -1;

    return 0;
}

void deinit(struct Buffer **buffer) {
    if (*buffer == NULL) return; // already cleared
    if ((*buffer)->queue) free((*buffer)->queue);
    free(*buffer);
    *buffer = NULL;
}

int addChar(struct Buffer *buffer, char c) {
    if (buffer->total == buffer->length) return -1;
    if (buffer->total == 0) { 
        buffer->head = 0;
        buffer->tail = 0;
    }
    buffer->queue[buffer->tail] = c;
    buffer->total += 1;
    buffer->tail += 1;
    if (buffer->tail >= buffer->length) buffer->tail = 0;
    return 0;
}

int removeChar(struct Buffer *buffer, char *c) {
    if (buffer->total == 0) return -1;
    *c = buffer->queue[buffer->head];
    buffer->total -= 1;
    buffer->head += 1;
    if (buffer->head >= buffer->length) buffer->head = 0;
    if (buffer->total == 0) {
        buffer->head = -1;
        buffer->tail = -1;
    }
    return 0;
}

void dump(struct Buffer *buffer) {
    printf("buffer:\n");
    printf("  length: %d\n", buffer->length);
    printf("  total:  %d\n", buffer->total);
    printf("  head:   %d\n", buffer->head);
    printf("  tail:   %d\n", buffer->tail);
    printf("  queue:  ");
    for (int i = 0; i < buffer->length; i++) {
        printf("%c, ", buffer->queue[i]);
    }
    printf("\n");
}

int main(void) {
    int test = 1;
    printf("queue.c:\n");
    {
        struct Buffer *buffer;
        init(5, &buffer);
        printf(">>> case %d:\n", test++);
        dump(buffer);
        deinit(&buffer);
    }
    {
        int result;
        char c;
        struct Buffer *buffer;
        init(5, &buffer);
        printf(">>> case %d:\n", test++);
        addChar(buffer, '1');
        //dump(buffer);
        result = removeChar(buffer, &c);
        //dump(buffer);
        if (c != '1')
            printf("FAILED\n");
        result = removeChar(buffer, &c);
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
        addChar(buffer, '1');
        addChar(buffer, '2');
        addChar(buffer, '3');
        addChar(buffer, '4');
        addChar(buffer, '5');
        dump(buffer);
        result = addChar(buffer, '6');
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
        addChar(buffer, '1');
        addChar(buffer, '2');
        addChar(buffer, '3');
        addChar(buffer, '4');
        addChar(buffer, '5');
        removeChar(buffer, &c);
        addChar(buffer, '6');
        //dump(buffer);
        deinit(&buffer);
    }

    // Possible test cases:
    // init/deinit
    // remove from empty
    // fill until full
    // add/remove 1
    // add/remove N<length
    // add/remove N==length

}

