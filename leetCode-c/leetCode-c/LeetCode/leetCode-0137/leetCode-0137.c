//
//  leetCode-0137.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/31.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0137.h"

int singleNumber1(int* nums, int numsSize) {
    
    int res = 0;
    for (int i = 0; i < 32; i++) {
        
        int sum = 0;
        for (int j = 0; j < numsSize; j++) {
            sum += (nums[j] >> i) & 1;
        }
        res |= (sum % 3) << i;
    }
    
    return res;
}

void test_0137(void) {
    int arr[4] = { 2,2,3,2 };
    int len = sizeof(arr) / sizeof(arr[0]);
    int ret = singleNumber1(arr, len);
    printf("ret = %d\n", ret);
}
