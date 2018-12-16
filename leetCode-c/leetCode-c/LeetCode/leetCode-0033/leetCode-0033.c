//
//  leetCode-0033.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/8.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0033.h"

int search1(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < nums[right]) {
            if (nums[mid] < target && nums[right] >= target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        else {
            if (nums[left] <= target && nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
    }
    return -1;
}

void test_0033(void) {
    int arr[7] = { 4,5,6,7,0,1,2 };
    int len = sizeof(arr) / sizeof(arr[0]);
    int target = 0;
    int ret = search1(arr, len, target);
    printf("ret = %d\n", ret);
    
    int target1 = 3;
    int ret1 = search1(arr, len, target1);
    printf("ret = %d\n", ret1);
}
