#include <stdio.h>
#include <stdlib.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 void inorderHelp(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }
    inorderHelp(root->left, result, index);
    result[(*index)++] = root->val;
    inorderHelp(root->right, result, index);
}

int count(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + count(root->left) + count(root->right);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = count(root);
    int *result = (int*)malloc(sizeof(int) * (*returnSize));
    int index = 0;
    inorderHelp(root, result, &index);
    return result;  
}