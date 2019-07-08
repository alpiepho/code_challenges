#include <stdio.h>
#include <stdlib.h>

// gcc merge_two.c -o runme ; ./runme

//#define PRINT_GIVEN

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

void validate(struct ListNode *list) {
    struct ListNode *p, *q;
    int val;

    p = list;
    if (p) val = p->val;
    while (p) {
        if (val > p->val) printf("ERROR %d > %d\n", val, p->val);
        val = p->val;
        p = p->next;
    }
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

static struct ListNode* merged = 0;
static struct ListNode* last = 0;

void merge_init(void) {
    merged = 0;
    last = 0;
}

struct ListNode* merge_add(struct ListNode* p) {
    struct ListNode* pNext = p->next;
    if (merged) {
        last->next = p;
    }
    else {
        merged = p;
    }
    last = p;
    return pNext;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    static struct ListNode *p1, *p2;

    merge_init();
    p1 = l1;
    p2 = l2;
    while (p1 && p2) {
        if (p1->val < p2->val)
            p1 = merge_add(p1);
        else
            p2 = merge_add(p2);

// show("merged", merged);
// show("p1", p1);
// show("p2", p2);
    }
    if (p1) merge_add(p1);
    if (p2) merge_add(p2);
    return merged;
}

//////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////
int main(void) {
    int result;

    printf("merge_two.c:\n");
    if (1) {
        int oneArray[] = { 1,3,4 };
        int twoArray[] = { 1,2,5 };
        struct ListNode *one = build(oneArray, 3);
        struct ListNode *two = build(twoArray, 3);
        struct ListNode *result;
        show("one", one);
        show("two", two);
        result = mergeTwoLists(one, two);
        show("result", result);
        validate(result);
        destroy(&result);
    }
    if (1) {
        int oneArray[] = { 1,2,4 };
        int twoArray[] = { 1,3,4 };
        struct ListNode *one = build(oneArray, 3);
        struct ListNode *two = build(twoArray, 3);
        struct ListNode *result;
        show("one", one);
        show("two", two);
        result = mergeTwoLists(one, two);
        show("result", result);
        validate(result);
        destroy(&result);
    }
    if (1) {
        int oneArray[] = { -9,3 };
        int twoArray[] = { 5,7 };
        struct ListNode *one = build(oneArray, 2);
        struct ListNode *two = build(twoArray, 2);
        struct ListNode *result;
        show("one", one);
        show("two", two);
        result = mergeTwoLists(one, two);
        show("result", result);
        validate(result);
        destroy(&result);
    }


    return 0;
}

