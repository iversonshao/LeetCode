#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    struct TreeNode **array;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* Create(int k) {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->array = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * (k+1));
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    queue->capacity = k+1;
    return queue;
}
bool IsEmpty(Queue* obj) {
    return obj->front == obj->rear;
}

bool IsFull(Queue* obj) {
    return ((obj->rear+1) % obj->capacity) == obj->front;
}
bool EnQueue(Queue* obj, struct TreeNode* node) {
    if (IsFull(obj)) {
        return false;
    }
    obj->array[obj->rear] = node;
    obj->rear = (obj->rear + 1) % obj->capacity;
    return true;
}

bool DeQueue(Queue* obj) {
    if (IsEmpty(obj)) {
        return false;
    }
    obj->front = (obj->front + 1) % obj->capacity;
    return true;    
}

struct TreeNode* QueueFront(Queue* obj) {
    if (IsEmpty(obj)) {
        return NULL;
    }
    return obj->array[obj->front];
}

struct TreeNode* QueueRear(Queue* obj) {
    if (IsEmpty(obj)) {
        return NULL;
    }
    int rearIndex = ((obj->rear - 1) + obj->capacity) % obj->capacity;
    return obj->array[rearIndex];
}

void QueueFree(Queue* obj) {
    free(obj->array);
    free(obj);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int **result = (int**)malloc(sizeof(int*) * 2000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);
    *returnSize = 0;

    Queue *queue = Create(10000);
    EnQueue(queue, root);

    while (!IsEmpty(queue)) {
        int size = (queue->rear - queue->front + queue->capacity) % queue->capacity;
        result[*returnSize] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[*returnSize] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode *node = QueueFront(queue);
            DeQueue(queue);
            result[*returnSize][i] = node->val;
            if (node->left) {
                EnQueue(queue, node->left);
            }
            if (node->right) {
                EnQueue(queue, node->right);
            }
        }
        (*returnSize)++;
    }
    QueueFree(queue);
    return result;
}
