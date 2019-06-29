// gcc linked2.c -o runme ; ./runme

#include <stdio.h>
#include <stdlib.h>

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

void showList(struct Node *list) {
    int i;
    struct Node *p;

    i = 1;
    p = list;
    while (p) {
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

struct Node *base;
struct Node *next;

void add_to_result_list( struct Node* node) {
    if (!base) {
        base = node;
        next = base;
    } else {
        next->next = node;
        next = node;
    }
}

struct Node *mergeList(struct Node *one, struct Node *two) {
    struct Node *both, *bPtr;
    struct Node *p1, *p2;
    
    base = NULL;
    next = NULL;
    p1 = one;
    p2 = two;
    
    while (p1 && p2) {
        if (p1->val < p2->val) {
            add_to_result_list(p1);
            p1 = p1->next;
        }
        else {
            add_to_result_list(p2);
            p2 = p2->next;
        }
    }
    
    if (p2)
        add_to_result_list(p2);
    
    if (p1)
        add_to_result_list(p1);

    return base;
}

int main(void) {
    struct Node *one = NULL;
    struct Node *two = NULL;
    struct Node *both = NULL;

    printf("linked2.c:\n");

    {
        int oneList[] = { 1, 4, 5 };
        int twoList[] = { 2, 6, 8 };
        int validList[] = { 1, 2, 4, 5, 6, 8 };
        one = createList(3, oneList);
        two = createList(3, twoList);

        printf(">>> case 1:\n");
        both = mergeList(one, two);
        if (!validateList(6, validList, both)) {
            printf("FAILED: both:\n");
            showList(both);
        }
        deleteList(&both);
        printf("\n");
    }

    {
        int oneList[] = { 3, 7, 8 };
        int twoList[] = { 2, 6, 9 };
        int validList[] = { 2, 3, 6, 7, 8, 9 };
        one = createList(3, oneList);
        two = createList(3, twoList);

        printf(">>> case 2:\n");
        both = mergeList(one, two);
        if (!validateList(6, validList, both)) {
            printf("FAILED: both:\n");
            showList(both);
        }
        deleteList(&both);
        printf("\n");
    }

    {
        int twoList[] = { 2, 6, 9 };
        int validList[] = { 2, 6, 9 };
        two = createList(3, twoList);

        printf(">>> case 3:\n");
        both = mergeList(NULL, two);
        if (!validateList(3, validList, both)) {
            printf("FAILED: both:\n");
            showList(both);
        }
        deleteList(&both);
        printf("\n");
    }

    {
        int oneList[] = { 3, 7, 8 };
        int validList[] = { 3, 7, 8 };
        one = createList(3, oneList);

        printf(">>> case 4:\n");
        both = mergeList(one, NULL);
        if (!validateList(3, validList, both)) {
            printf("FAILED: both:\n");
            showList(both);
        }
        deleteList(&both);
        printf("\n");
    }
}

