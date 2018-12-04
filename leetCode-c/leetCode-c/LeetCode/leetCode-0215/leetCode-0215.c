//
//  leetCode-0215.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/2.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0215.h"

#include <stdbool.h>

void swap1(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition1(int *arr, int p, int r) {
    int i = p;
    int j = p;
    
    for (; j < r; j++) {
        if (arr[j] > arr[r]) {
            if (i != j) {
                swap1(arr + i, arr + j);
            }
            i++;
        }
    }
    
    swap1(arr + i, arr + r);
    
    return i;
}

int findKthLargest(int* nums, int numsSize, int k) {
    
    int left = 0;
    int right = numsSize - 1;
    
    while (true) {
        int pos = partition1(nums, left, right);
        if (pos == k - 1) {
            return nums[pos];
        }
        else if (pos > k - 1) {
            right = pos - 1;
        }
        else {
            left = pos + 1;
        }
    }
}

void test_0215(void) {
    int arr1[6] = { 3, 2, 1, 5, 6, 4};
    int k1 = 2;
    int max1 = findKthLargest(arr1, 6, k1);
    printf("第%d大元素是%d\n",k1,max1);
    
    int arr[9] = { 3,2,3,1,2,4,5,5,6 };
    int k = 4;
    
    int max = findKthLargest(arr, 9, k);
    printf("第%d大元素是%d\n",k,max);
}
