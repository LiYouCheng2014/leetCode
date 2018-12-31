//
//  leetCode-0136.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/22.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0136.h"

int singleNumber(int* nums, int numsSize) {
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        res ^= nums[i];
    }
    return res;
}

void test_0136(void) {
    int arr[5] = { 4,1,2,1,2 };
    int len = sizeof(arr) / sizeof(arr[0]);
    int ret = singleNumber(arr, len);
    printf("ret = %d\n", ret);
}
