#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(char data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

typedef struct Stack {
    struct Node *head;
} Stack;


Stack* StackCreate() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

void push(Stack* obj, char data) {
    Node *new_node = createNode(data);
    new_node->next = obj->head; 
    obj->head = new_node; //top move to new_node
}

char pop(Stack* obj) {
    if (obj->head != NULL) {
        char result = obj->head->data;
        Node *temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
        return result;
    }
    else {
        return '\0';
    }
}

bool isEmtpy(Stack* obj) {
    return obj->head == NULL;
}

bool isValid(char* s) {
    int i = 0;
    Stack *stack = StackCreate();

    while (s[i]) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(stack, s[i]);
        } else {
            if (isEmtpy(stack)) {
                return false;
            }
            char top = pop(stack);
            if (s[i] == ')' && top != '(') {
                return false;
            }
            if (s[i] == ']' && top != '[') {
                return false;
            }
            if (s[i] == '}' && top != '{') {
                return false;
            }
        }
        i++;
    }
    return isEmtpy(stack);
    
}