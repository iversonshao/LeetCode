#include <stdio.h>
//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *curr = head;
    struct ListNode *prev = NULL;
    struct ListNode *next;

    //for(int i = 0; curr != NULL; i++)
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

    }
    return prev;
}