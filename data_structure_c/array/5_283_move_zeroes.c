void moveZeroes(int* nums, int numsSize) {
    // Initial approach: remove non-zero numbers first, then fill the rest with zeros.
    // Issue: This approach may fail to clear all zeros in certain edge cases.
    /*
    int nonZeroPos = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[nonZeroPos] = nums[i];
            nonZeroPos++;
        }
    }
    for (int j = nonZeroPos; j < numsSize; j++) {
        nums[j] = 0;
    }
    */

    // Revised approach: Shift non-zero numbers in-place and replace the remaining elements with zeros.
    int nonZeroPos = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            // Only move elements if the current index differs from the non-zero position
            if (i != nonZeroPos) {
                nums[nonZeroPos] = nums[i];
                nums[i] = 0;
            }
            nonZeroPos++;
        }
    }
}
