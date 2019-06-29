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

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////
// Support Functions
//////////////////////////////////////////////////////
struct Node {
    int val;
    struct Node *next;
};

struct Node *createNode(int value) {
    struct Node *node = malloc(sizeof(struct Node));
    node->val = value;
    node->next = NULL;
    return node;
}

struct Node *createList(int size, int *list) {
    int i;
    struct Node *linked, *next, *end;
    linked = NULL;

    for (i = 0; i < size; i++) {
        next = createNode(list[i]);
        if (linked == NULL) {
            linked = next;
            end = next; // keep track of end
        }
        else {
            end->next = next;
            end = next;
        }
    }
    return linked;
}

struct Node *deleteNode(struct Node *node) {
    struct Node *next = node->next;
    free(node);
    return next;
}

void deleteList(struct Node **linked) {
    struct Node *p, *last;

    if (*linked == NULL)
        return;

    p = *linked;
    while (p) {
        p = deleteNode(p);
    }
    *linked = NULL;
}

void showList(int size, struct Node *list) {
    int i;
    struct Node *p;

    i = 1;
    p = list;
    while (p && i <= size) {
        printf("%d: %d\n", i, p->val);
        i++;
        p = p->next;
    }
}

int validateList(int size, int *list, struct Node *linked) {
    int i;
    struct Node *next;

    next = linked;
    for (i = 0; i < size; i++) {
        if (next == NULL || next->val != list[i])
            return 0;
        next = next->next;
    }
    if (next)
        return 0;
    return 1;
}


//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////
struct Node *sortList(struct Node *given) {
    struct Node *odd_head = NULL;
    struct Node *odd_tail = NULL;
    struct Node *even_head = NULL;
    struct Node *even_tail = NULL;
    struct Node *work, *workNext;

    // move work thru the given linked list,
    // if odd, add to odd_tail
    // if even, add to even even_tail
    // when work is null, add even_head to odd_tail

    work = given;
    while (work) {
        workNext = work->next;
        if ((work->val & 1) == 1) {
            if (odd_head == NULL) {
                odd_head = work;   // init
            }
            else {
                odd_tail->next = work; // add to end
            }
            odd_tail = work;   // move tail
            work->next = NULL; // 'cut' off work since at the end of list now
        }
        if ((work->val & 1) == 0) {
            if (even_head == NULL) {
                even_head = work;   // init
            }
            else {
                even_tail->next = work; // add to end
            }            
            even_tail = work;   // move tail
            work->next = NULL; // 'cut' off work since at the end of list now
        }
        work = workNext;
    }
    if (odd_tail == NULL) odd_head = even_head; // no odd found
    else if (odd_tail) odd_tail->next = even_head;
    
    return odd_head;
}

void run_case(int test, int length, int *list, int *validList) {
    struct Node *given = createList(length, list);
    struct Node *sorted;

    printf(">>> case %d:\n", test);
    sorted = sortList(given);
    showList(length, sorted);
    if (!validateList(length, validList, sorted)) {
        printf("FAILED\n");
    }
    deleteList(&sorted);
    printf("\n");
}

//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int test = 1;
    printf("oddeven.c:\n");
    {
        int list[] = { 1, 2, 3, 4, 5, 6 };
        int validList[] = { 1, 3, 5, 2, 4, 6 };
        run_case(test++, 6, list, validList);
    }
    {
        int list[] = { 1, 3, 5, 7 };
        int validList[] = { 1, 3, 5, 7 };
        run_case(test++, 4, list, validList);
    }
    {
        int list[] = { 2, 4, 6, 8 };
        int validList[] = { 2, 4, 6, 8 };
        run_case(test++, 4, list, validList);
    }
    {
        int list[] = { 2, 2, 4, 4, 6, 5 };
        int validList[] = { 5, 2, 2, 4, 4, 6 };
        run_case(test++, 6, list, validList);
    }
}

