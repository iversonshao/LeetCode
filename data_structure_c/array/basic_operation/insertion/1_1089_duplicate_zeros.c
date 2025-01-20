void duplicateZeros(int* arr, int arrSize) {
    // case1:n^2 35ms
    // for (int i = 0; i < arrSize; i++) {
    //     if (arr[i] == 0) {
    //         for(int j = arrSize-1; j > i; j--) {
    //             arr[j] = arr[j-1];
    //         }
    //         if(i+1 < arrSize) {
    //             arr[i+1] = 0;
    //             i++;
    //         }
    //     }
    // }
    // case2:O(n)
    int zeros = 0;
    int last = arrSize - 1;

    for (int i = 0; i <= last - zeros; i++) {
        if (arr[i] == 0) {
            //in edge
            if (i == last - zeros) {
                arr[last] = 0;
                last = last - 1;
                break;
            }
            zeros++;
        }
    }
    int last_element = last - zeros;
    for (int i = last_element; i >= 0; i--) {
        if (arr[i] == 0) {
            arr[i+zeros] = 0;
            zeros--;
            arr[i+zeros] = 0;
        } else {
            arr[i+zeros] = arr[i];
        }
    }
}