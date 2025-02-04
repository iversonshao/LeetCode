#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int *inc;
    int maxSize;
    int top;
} CustomStack;

CustomStack* customStackCreate(int maxSize) {
    CustomStack *stack = (CustomStack*)malloc(sizeof(CustomStack));
    stack->array = (int*)malloc(maxSize * sizeof(int));
    stack->inc = (int*)calloc(maxSize, sizeof(int));
    stack->maxSize = maxSize;
    stack->top = -1;
    return stack;    
}

void customStackPush(CustomStack* obj, int x) {
    if (obj->top + 1 >= obj->maxSize) {
        printf("error");
        return;
    }
    obj->top++;
    obj->array[obj->top] = x;
}

int customStackPop(CustomStack* obj) {
    if (obj->top == -1) {
        return -1;
    }
    int value = obj->array[obj->top] + obj->inc[obj->top];

    if (obj->top > 0) {
        obj->inc[obj->top - 1] += obj->inc[obj->top];
    }
    obj->inc[obj->top] = 0;
    obj->top--;
    return value;
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    int count = k > obj->top + 1 ? obj->top + 1 : k;
    if (count > 0) {
        obj->inc[count - 1] += val;
    }
}

void customStackFree(CustomStack* obj) {
    free(obj->array);
    free(obj->inc);
    free(obj);
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);
 
 * int param_2 = customStackPop(obj);
 
 * customStackIncrement(obj, k, val);
 
 * customStackFree(obj);
*/