// gcc linked.c -o runme ; ./runme

// TODO
// given list of numbers:
// - create linked list
// - show linked list
// - insert element to list
// - delete element
// - destroy linked list
#include <stdio.h>
#include <stdlib.h>

//#define NULL 0

struct Node {
    int val;
    struct Node *next; // single list
};

struct Node *createNode(int value) {
    struct Node *node = malloc(sizeof(struct Node));
    node->val = value;
    node->next = NULL;
    return node;
}

struct Node *deleteNode(struct Node *node) {
    struct Node *next = node->next;
    free(node);
    return next;
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

void deleteList(struct Node **linked) {
    struct Node *p, *last;

    p = *linked;
    while (p) {
        printf("delete %d\n", p->val);
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

void insertVal(struct Node **linked, int value) {
    struct Node *p, *temp;
    p = *linked;

    // test empty linked
    if (!linked || !*linked) {
        *linked = createNode(value);
        return;
    }

    temp = createNode(value);

    // test if before first node
    if (value < (*linked)->val) {
        temp->next = (*linked);
        *linked = temp;
    }
    else {
        // find node before (p) and node after (next)
        p = *linked;
        while (p) {
            if (value >= p->val) {
                if (!p->next) {
                    // after last node, drop out
                    p->next = temp;
                    break;
                }
                if (value < p->next->val) {
                    // found slot
                    temp->next = p->next;
                    p->next = temp;
                    break;
                }
            }
            p = p->next;
        }
    }

}

void removeVal(struct Node **linked, int value) {
    struct Node *p, *prev;

    // is value the first
    if ((*linked)->val == value) {
        p = (*linked);
        (*linked) = (*linked)->next;
        deleteNode(p);
        return;
    }

    prev = *linked;
    p = prev->next;
    while (p) {
        if (p && p->val == value) {
            prev->next = p->next;
            deleteNode(p);
            break;
        }
        p = p->next;
    }
}

int main(void) {
    int list[] = { 2, 4, 6, 7, 8, 9 };
    struct Node *linked = NULL;

    printf("linked.c:\n");

    // - create linked list
    linked = createList(6, list);
    // - show linked list
    printf("createList\n");
    showList(linked);
    // - insert element to list
    printf("insertVal\n");
    insertVal(&linked, 5);
    showList(linked);
    // - delete element
    printf("removeVal\n");
    removeVal(&linked, 2);
    showList(linked);
    // - destroy linked list
    printf("deleteList\n");
    deleteList(&linked);
    showList(linked);

}

/*
How will you check if Bit5 of a memory mapped register is on or not?  
0xE000E034

volatile int *addr = (int *)0xE000E034;

if ((*addr) & 0x00000020) {
    // is privaledege
}


Merge two given sorted linked lists into one:
Input:
1 --> 4 --> 5 --> NULL 
2 --> 6 --> 8 --> NULL 
Output:
1 --> 2 --> 4 --> 5 --> 6 --> 8 --> NULL

struct Node {
    int val;
    struct Node *next;
}

struct Node *base = 0;
struct Node *next = 0;

void add_to_result_list( struct Node* node) {
    if (!base) {
        base = node;
        next = base;
    } else {
        next->next = node;
        next = node;
    }
}

void merge(struct Node *one, struct Node *two) {
    struct Node *both, *bPtr;
    struct Node *p1, *p2;
    
    p1 = one;
    p2 = two;
    
    while (p1 && p2) {
        if (p1->val < p2->val) {
            add_to_result(p1);
            p1 = p1->next;
        }
        else {
            add_to_result(p2);
            p2 = p2->next;
        }
    }
    
    if (!p1 & p2) {
            add_to_result(p2);
    }
    
    if (p1 & !p2) {
            add_to_result(p1);
    }

    
}
*/