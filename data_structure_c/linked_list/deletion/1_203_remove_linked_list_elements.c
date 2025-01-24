#include <stdio.h>
//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    //way1 2ms
    // if (head == NULL) {
    //     return NULL;
    // } else {
    //     while (head && head->val == val) {
    //         struct ListNode *temp = head;
    //         head = head->next;
    //         free(temp);
    //     }
    //     struct ListNode *curr = head;
    //     while (curr != NULL && curr->next != NULL) {
    //         if (curr->next->val == val) {
    //             struct ListNode *temp = curr->next;
    //             curr->next = curr->next->next;
    //             free(temp);
    //         } else {
    //             curr = curr->next;
    //         }
    //     }
    //     return head;
    // }
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof (struct ListNode));
    dummy->next = head;
    struct ListNode *curr = dummy;
    while (curr->next) {
        if (curr->next->val == val) {
            struct ListNode *temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }
    head = dummy->next;
    free(dummy);
    return head;
}