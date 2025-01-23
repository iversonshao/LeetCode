#include <stdio.h>
// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* partition(struct ListNode* head, int x) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *smallHead = NULL;
    struct ListNode *small = NULL;
    struct ListNode *bigHead = NULL;
    struct ListNode *big = NULL;
    struct ListNode *curr = head;
    while (curr != NULL) {
        if (curr->val < x) {
            if (smallHead == NULL) {
                smallHead = curr;
                small = curr;
            } else {
                small->next = curr;
                small = small->next;
            }
        } else {
            if (bigHead == NULL) {
                bigHead = curr;
                big = curr;
            } else {
                big->next = curr;
                big = big->next;
            }
        }
        curr = curr->next;
    }
    if (big != NULL) {
        big->next = NULL;
    }
    if (small == NULL) {
        return bigHead;
    } else {
        small->next = bigHead;
        return smallHead;
    }
}