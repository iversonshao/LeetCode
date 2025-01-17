/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *result = (int*) malloc(sizeof(int) *numsSize);

    // case1: brute
    // for (int i = 0; i < numsSize; i++){
    //     result[i] = nums[i] * nums[i];
    // }
    // //using bobo sorted
    // for (int j = 0; j < numsSize; j++){
    //     for (int k = j+1; k < numsSize; k++){
    //         if (result[j] > result[k]){
    //             int temp = result[j];
    //             result[j] = result[k];
    //             result[k] = temp;
    //         }
    //     }
    // }

    // case2: 2 pointer
    // because order of nums is from smaller to bigger.
    // neg. nums to pos. nums.

    int left = 0;
    int right = numsSize - 1;
    int index = numsSize - 1;
    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            result[index] = leftSquare;
            left++;
        } else {
            result[index] = rightSquare;
            right--;
        }
        index--;
    }
    *returnSize = numsSize;
    return result;
}