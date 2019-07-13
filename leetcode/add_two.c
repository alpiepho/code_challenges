#include <stdio.h>
#include <stdlib.h>

// gcc add_two.c -o runme ; ./runme

// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example:

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.


//////////////////////////////////////////////////////
// Support Functions
//////////////////////////////////////////////////////

struct ListNode {
    int val;
    struct ListNode *next;
};

void show(char *label, struct ListNode *list) {
    struct ListNode *p = list;
    printf("%s: ", label);
    while (p) {
        printf("%d ", p->val);
        if (p->next) printf("-> ");
        p = p->next;
    }
    printf("\n");

}

struct ListNode * build(int *nums, int numsSize) {
    int i;
    struct ListNode *list, *p, *q;

    list = 0;
    q = 0;
    for (i=0; i<numsSize; i++) {
        p = (struct ListNode *) malloc(sizeof(struct ListNode));
        p->val = nums[i];
        p->next = 0;
        if (list == 0) list = p;
        if (q) q->next = p;
        q = p;
    }
    return list;
}

void destroy(struct ListNode **list) {
    struct ListNode *p, *q;

    p = *list;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    *list = 0;
}


//////////////////////////////////////////////////////
// Question Functions
//////////////////////////////////////////////////////

static struct ListNode* accum = 0;
static struct ListNode* last = 0;

void accum_init(void) {
    accum = 0;
    last = 0;
}

struct ListNode* accum_add(struct ListNode* p) {
    struct ListNode* pNext = p->next;
    if (accum) {
        last->next = p;
    }
    else {
        accum = p;
    }
    last = p;
    return pNext;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int digit, carry = 0;
    static struct ListNode *p1, *p2, *pdigit;

    accum_init();
    p1 = l1;
    p2 = l2;
    while (p1 || p2 || carry) {
        pdigit = (struct ListNode *)malloc(sizeof(struct ListNode));
        pdigit->val = 0;
        pdigit->next = 0;

        if (p1 && p2) digit = p1->val + p2->val + carry;
        else if (p1)  digit = p1->val  + carry;
        else if (p2)  digit = p2->val  + carry;
        else          digit = carry;
        carry = digit / 10;
        digit = digit % 10;
        pdigit->val = digit;
        accum_add(pdigit);
        if (p1) p1 = p1->next;
        if (p2) p2 = p2->next;
    }
    return accum;
}



//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int result;

    printf("add_two.c:\n");
    if (1) {
        int oneArray[] = { 2,4,3 };
        int twoArray[] = { 5,6,4 };
        struct ListNode *one = build(oneArray, 3);
        struct ListNode *two = build(twoArray, 3);
        struct ListNode *result;
        show("one", one);
        show("two", two);
        result = addTwoNumbers(one, two);
        show("result", result);
        destroy(&result);
    }

    if (1) {
        int oneArray[] = { 5 };
        int twoArray[] = { 5 };
        struct ListNode *one = build(oneArray, 1);
        struct ListNode *two = build(twoArray, 1);
        struct ListNode *result;
        show("one", one);
        show("two", two);
        result = addTwoNumbers(one, two);
        show("result", result);
        destroy(&result);
    }

    return 0;
}



