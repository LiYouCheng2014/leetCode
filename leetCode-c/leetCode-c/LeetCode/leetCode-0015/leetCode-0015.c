//
//  leetCode-0015.c
//  leetCode-0015
//
//  Created by liyoucheng on 2018/11/6.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0015.h"

/*
 基于两数之和计算
 如果nums[i] > 0则不需要管后面
 */

#include <stdlib.h>

int compareInt(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void two_sum(int *nums, int left, int right, int target, int **results, int *count) {
    while (left < right) {
        int diff = target - nums[left];
        if (diff < nums[right]) {
            while (--right > left && nums[right] == nums[right + 1]) {
                
            }
        } else if (diff > nums[right]) {
            while (++left < right && nums[left] == nums[left - 1]) {
                
            }
        } else {
            results[*count] = malloc(3 * sizeof(int));
            results[*count][0] = -target;
            results[*count][1] = nums[left];
            results[*count][2] = nums[right];
            (*count)++;
            
            while (++left < right && nums[left] == nums[left - 1]) {}
            while (--right > left && nums[right] == nums[right + 1]) {}
        }
    }
}


int** threeSum(int* nums, int numsSize, int* returnSize) {
    if (numsSize < 3) {
        return NULL;
    }
    
    qsort(nums, numsSize, sizeof(*nums), compareInt);
    
    *returnSize = 0;
    int **results = malloc(sizeof(int *) * (((numsSize * (numsSize - 1) * (numsSize - 2))) / (3 * 2 * 1)));
    for (int i = 0; i < numsSize; i++) {
        if ((i == 0 && nums[i] <= 0) || ((i > 0 && nums[i] != nums[i - 1]) && nums[i] <= 0)) {
            two_sum(nums, i + 1, numsSize - 1, -nums[i], results, returnSize);
        }
    }
    
    return results;
}

void test_0015()
{
    int arr[6] = { -1, 0, 1, 2, -1, -4 };
//    int arr[4] = { 1, 2, -2, -1 };
    int count = 0;
    int **ret = threeSum(arr, 4, &count);
    
    if (ret) {
        for (int i = 0; i < count; i++) {
            int *temp = ret[i];
            printf("%d->%d->%d\n",temp[0],temp[1],temp[2]);
        }
        
    }
}
