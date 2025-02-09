#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    int *array;
    int front;
    int rear;
    int capacity;
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *deque = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    deque->array = (int*)malloc(sizeof(int) * (k+1));
    deque->front = 0;
    deque->rear = 0;
    deque->capacity = k+1;
    return deque;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->front == obj->rear;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return ((obj->rear + 1) % obj->capacity) == obj->front;
    //rear next is front
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) return false;
    // front is move to front.
    obj->front = (obj->front-1 + obj->capacity) % obj->capacity;
    obj->array[obj->front] = value;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) return false;
    obj->array[obj->rear] = value;
    obj->rear = (obj->rear+1 + obj->capacity) % obj->capacity;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return false;
    obj->front = (obj->front+1 + obj->capacity) % obj->capacity;
    return true;
    
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return false;
    obj->rear = (obj->rear-1 + obj->capacity) % obj->capacity;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return -1;
    return obj->array[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return -1;
    return obj->array[(obj->rear-1 + obj->capacity) % obj->capacity];
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->array);
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/