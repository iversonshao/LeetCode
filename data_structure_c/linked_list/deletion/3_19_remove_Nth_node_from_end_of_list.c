#include <stdio.h>
// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof (struct ListNode));
    dummy->next = head;
    struct ListNode *fast = dummy;
    struct ListNode *slow = dummy;
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }
    struct ListNode *temp = slow->next;
    slow->next = slow->next->next;
    free(temp);
    
    head = dummy->next;
    free(dummy);
    return head;

}