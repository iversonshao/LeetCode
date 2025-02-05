/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int *stack = (int*)malloc(sizeof(int) * asteroidsSize);
    int top = -1;

    for (int i = 0; i < asteroidsSize; i++) {
        int alive = 1;
        while (alive && top >=0 && stack[top] > 0 && asteroids[i] < 0) {
            if (abs(stack[top]) == abs(asteroids[i])) {
                top--; //pop
                alive = 0;
            } else if (stack[top] < abs(asteroids[i])) {
                top--;
            } else {
                alive = 0;
            }
        }
        if (alive) {
            stack[++top] = asteroids[i];
        }

    }
    *returnSize = top + 1;
    return stack;
    
}