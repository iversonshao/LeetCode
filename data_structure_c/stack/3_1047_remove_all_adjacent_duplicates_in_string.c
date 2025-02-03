char* removeDuplicates(char* s) {
    int n = strlen(s);
    char *stack = (char*)malloc(n + 1);
    int top = -1;
    
    for (int i = 0; i < n; i++) {
        if (top >= 0 && stack[top] == s[i]) {
            top--; // pop
        } else {
            stack[++top] = s[i]; // push
        }
    }
    
    stack[top + 1] = '\0';
    return stack;
}