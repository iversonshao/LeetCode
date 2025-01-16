int findMaxConsecutiveOnes(int* nums, int numsSize) {
    //if (numsSize == 0) return 0;
    int max = 0;
    int currentCount = 0;
    for (int i = 0; i < numsSize; i++){
        if (nums[i] == 1){
            currentCount++;
            if (currentCount > max){
                max = currentCount;
            }
        } else {
            currentCount = 0;            
        }
    }
    return max;
}