/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    //using for loop
    //a[0],a[1]+a[0],...,a[i+n-1]+a[i+n]+...+a[1]+a[0]
    int * result = (int *) malloc(sizeof (int) * numsSize);
    result[0] = nums[0];
    for (int i = 1; i < numsSize ; i++) {
        result[i] = nums[i] + result[i-1];
    }
    *returnSize = numsSize;
    return result;
}