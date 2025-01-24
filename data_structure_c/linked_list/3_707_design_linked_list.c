#include <stdio.h>
#include <stdlib.h>
//def node
#ifndef LIST_NODE
#define LIST_NODE
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;
#endif

//def list
typedef struct MyLinkedList{
    struct ListNode *head;
    int size;
} MyLinkedList;

//(type*) name = (type*)malloc(sizeof(type))
MyLinkedList* myLinkedListCreate() {
    MyLinkedList *list = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index<0 || index >= obj->size) {
        return -1;
    } else {
        struct ListNode *curr = obj->head;
        for (int i = 0; i < index; i++){
            curr = curr->next;
        }
        return curr->val;
    }
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = obj->head;
    obj->head = newNode;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;

    if (obj->head == NULL) {
        obj->head = newNode;
    } else {
        struct ListNode *curr = obj->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    } else if (index == obj->size) {
        myLinkedListAddAtTail(obj, val);
        return;
    } else if (index<0 || index > obj->size) {
        return;
    } else {
        struct ListNode *curr = obj->head;
        for (int i = 0; i < index-1; i++){
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        obj->size++;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index == 0 && obj->head != NULL) {
        struct ListNode *temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
        obj->size--;
        return;
    } else if (index<0 || index >= obj->size || obj->head == NULL) {
        return;
    } else {
        struct ListNode *curr = obj->head;
        for (int i = 0; i < index - 1; i++){
            curr = curr->next;
        }
        struct ListNode *temp = curr->next;
        curr->next = temp->next;
        free(temp);
        obj->size--;
        return;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    struct ListNode *curr = obj->head;
    while (curr != NULL) {
        struct ListNode *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/