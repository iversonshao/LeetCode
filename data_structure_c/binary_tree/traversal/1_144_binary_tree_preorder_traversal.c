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

void preorderHelp(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }
    result[(*index)++] = root->val;
    preorderHelp(root->left, result, index);
    preorderHelp(root->right, result, index);
}

int count(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + count(root->left) + count(root->right);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = count(root);
    int *result = (int*)malloc(sizeof(int) * (*returnSize));
    int index = 0;
    preorderHelp(root, result, &index);
    return result;
}