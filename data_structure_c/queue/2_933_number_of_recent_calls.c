#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *times;
    int capacity;
    int front;
    int rear;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter *counter = (RecentCounter*)malloc(sizeof(RecentCounter));
    counter->capacity = 10001;
    counter->times = (int*)malloc(sizeof(int) * counter->capacity);
    counter->front = 0;
    counter->rear = 0;
    return counter;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->times[obj->rear % obj->capacity] = t;
    obj->rear++;

    // 確保範圍在 [t-3000, t]
    while (obj->front < obj->rear && obj->times[obj->front % obj->capacity] < t - 3000) {
        obj->front++;
    }
    
    return obj->rear - obj->front;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->times);
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/