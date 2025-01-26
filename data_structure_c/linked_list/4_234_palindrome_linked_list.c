#include <stdio.h>
#include <stdbool.h>
//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next) {
        return true;
    } else if (!head->next->next) {
        return head->val == head->next->val;
    } else {
        struct ListNode *slow = head;
        struct ListNode *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        struct ListNode *second = slow->next;
        struct ListNode *prev = NULL;
        struct ListNode *next;
        while (second) {
            next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }
        struct ListNode *p1 = head;
        struct ListNode *p2 = prev;
        while (p2) {
            if (p1->val != p2->val) {
                return false;
            } else {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return true;
    }
}