#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *array;
    int top;
    int capacity;
} Stack;

Stack *StackCreate(int capacity) {
    Stack *head = (Stack*)malloc(sizeof(Stack));
    head->array = (int*)malloc(capacity * sizeof(int));
    head->capacity = capacity;
    head->top = -1;
    return head;
}
void push(Stack *obj, int x) {
    if (obj->top >= obj->capacity - 1) {
        return;
    }
    obj->top++;
    obj->array[obj->top] = x;
}

int pop(Stack *obj){
    if (obj->top == -1) {
        return -1;
    }
    int x = obj->array[obj->top];
    obj->top--;
    return x;
}

bool isEmpty(Stack *obj){
    return (obj->top == -1);
}
typedef struct {
    Stack *S;
    Stack *T;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->S = StackCreate(1000);
    queue->T = StackCreate(1000);
    return queue;    
}

void myQueuePush(MyQueue* obj, int x) {
    push(obj->S, x);
}

int myQueuePop(MyQueue* obj) {
    if (isEmpty(obj->T)) {
        if (isEmpty(obj->S)) {
            return -1;
        } else {
            while (!isEmpty(obj->S)) {
                int temp = pop(obj->S);
                push(obj->T, temp);
            }
        }
    }
    return pop(obj->T);
}

int myQueuePeek(MyQueue* obj) {
    if (isEmpty(obj->T)) {
        if (isEmpty(obj->S)) {
            return -1;
        } else {
            while (!isEmpty(obj->S)) {
                int temp = pop(obj->S);
                push(obj->T, temp);
            }
        }
    }
    return (obj->T->array[obj->T->top]);
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj->S) && isEmpty(obj->T);
}

void myQueueFree(MyQueue* obj) {
    free(obj->S->array);
    free(obj->S);
    free(obj->T->array);
    free(obj->T);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/