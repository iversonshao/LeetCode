#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int min;
    struct Node *next;
} Node;

Node *createNode(int new_data, int curr_min) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->min = curr_min;
    new_node->next = NULL;
    return new_node;
}

typedef struct MinStack {
    struct Node *head;
} MinStack;


MinStack* minStackCreate() {
    MinStack *minstack = (MinStack*)malloc(sizeof(MinStack));
    minstack->head = NULL;
    return minstack;
}

void minStackPush(MinStack* obj, int val) {
    int new_min;
    if (obj->head == NULL) {
        new_min = val;
    } else {
        new_min = (val < obj->head->min) ? val : obj->head->min;
    }
    Node *new_node = createNode(val, new_min);
    new_node->next = obj->head; 
    obj->head = new_node; //top move to new_node
}

void minStackPop(MinStack* obj) {
    if (obj->head != NULL) {
        Node *temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    }
}

int minStackTop(MinStack* obj) {
    if (obj->head != NULL) {
        return obj->head->data;
    }
    return -1;
}

int minStackGetMin(MinStack* obj) {
    if (obj->head != NULL) {
        return obj->head->min;
    }
    return 0;
}

void minStackFree(MinStack* obj) {
    Node *curr = obj->head;
    while (curr != NULL) {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/