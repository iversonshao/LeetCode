int findNumbers(int* nums, int numsSize) {
    int count = 0;
    // case 1: use char : 2ms
    // for (int i = 0; i < numsSize ; i++){
    //     // max digit is six.
    //     // switch int to string
    //     char str[7];
    //     sprintf(str, "%d", nums[i]);
    //     if (strlen(str) % 2 == 0) { //use strlen to cal. lenght
    //         count++;
    //     }
    // }
    // case 2 :0ms
    // for (int i = 0; i < numsSize; i++){
    //     int digits = 0;
    //     int num = nums[i];
    //     while (num > 0) {
    //         num /= 10;
    //         digits++;
    //     }
    //     if (digits % 2 == 0){
    //         count++;
    //     }
    // }
    // case3:0ms
    for (int i = 0; i < numsSize; i++){
        if (9 < nums[i] && nums[i] < 100){
            count++;
        }
        else if (999 < nums[i] && nums[i] < 10000){
            count++;
        }
        else if (nums[i] == 100000){
            count++;
        }

    }
    return count;
}