void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}
void rotate(int* nums, int numsSize, int k) {
    //case1: dynamic malloc 4ms
    k = k % numsSize; //if k > numsSize
    // int *temp = (int*) malloc(sizeof(int) *numsSize);
    // for (int i = 0; i < numsSize; i++) {
    //     temp[(i+k) % numsSize] = nums[i];
    // }
    // for (int j = 0; j < numsSize; j++) {
    //     nums[j] = temp[j];
    // }
    // free(temp);
    //case2 :r r r
    reverse(nums, 0, numsSize-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, numsSize-1);
}