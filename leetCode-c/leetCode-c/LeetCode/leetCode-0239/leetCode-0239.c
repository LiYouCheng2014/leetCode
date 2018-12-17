//
//  leetCode-0239.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/16.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0239.h"

#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int head = 0;
    int tail = 0;
    
    int *indexs = malloc(sizeof(int) * numsSize);
    int *results = malloc(sizeof(int) * (numsSize - k + 1));
    
    int count = 0;
    
    for (int i = 0; i < numsSize; i++) {
        while (tail > head && nums[i] >= nums[indexs[tail - 1]]) {
            tail--;
        }
        
        indexs[tail++] = i;
        
        if (indexs[head] <= i - k) {
            head++;
        }
        
        if (i >= k - 1) {
            results[count++] = nums[indexs[head]];
        }
    }
    
    *returnSize = count;
    return results;
}

void test_0239(void)
{
    int nums[8] = { 1,3,-1,-3,5,3,6,7 };
    int k = 3;
    int count = 0;
    int *list = maxSlidingWindow(nums, 8, k, &count);
    for (int i = 0; i < count; i++) {
        printf("%d ",list[i]);
    }
    printf("\n");
}
