#include <stdio.h>
#include <stdbool.h>
// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}