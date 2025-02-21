#include <stdio.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize == 0 || inorderSize == 0) {
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    int i = 0;
    while (i < inorderSize && inorder[i] != preorder[0]) {
        i++;
    }
    int leftSize = i;
    root->left = buildTree(preorder+1, leftSize, inorder, leftSize);
    root->right = buildTree(preorder+leftSize+1, inorderSize-leftSize-1, inorder+leftSize+1, inorderSize-leftSize-1);
    return root;
}