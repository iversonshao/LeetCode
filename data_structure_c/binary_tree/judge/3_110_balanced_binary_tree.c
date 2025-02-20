#include <stdbool.h>
#include <stdio.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    int leftheight = height(node->left);
    int rightheight = height(node->right);

    if (leftheight == -1 || rightheight == -1) {
        return -1;
    }

    if (abs(leftheight - rightheight) > 1) {
        return -1;
    }
    return max(leftheight, rightheight) + 1;
}
bool isBalanced(struct TreeNode* root) {
    return height(root) >= 0;
}

