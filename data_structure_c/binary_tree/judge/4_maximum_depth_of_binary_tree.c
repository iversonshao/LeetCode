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
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftdepth = maxDepth(root->left);
    int rightdepth = maxDepth(root->right);

    return max(leftdepth, rightdepth) + 1;
}