#include <stdio.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (inorderSize == 0 || postorderSize == 0) {
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize-1];
    int i = 0;
    while (i < inorderSize && inorder[i] != postorder[postorderSize-1]) {
        i++;
    }
    int leftSize = i;
    root->left = buildTree(inorder, leftSize, postorder, leftSize);
    root->right = buildTree(inorder+leftSize+1, inorderSize-leftSize-1, postorder+leftSize, postorderSize-leftSize-1);
    return root;
}