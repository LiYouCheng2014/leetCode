//
//  leetCode-0001.c
//  leetCode
//
//  Created by liyoucheng on 2018/11/16.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0001.h"

/*
 原数组排序
 
 我们用两个指针分别指向数组首尾两个数，如果两个数和正好为target，则将这两个数一起存入结果中。然后就是跳过重复数字的步骤了，两个指针都需要检测重复数字。如果两数之和小于target，则我们将左边那个指针i右移一位，使得指向的数字增大一些。同理，如果两数之和大于target，则我们将右边那个指针j左移一位，使得指向的数字减小一些
 */

#include <stdlib.h>
#include <string.h>

struct object {
    int key;
    int value;
};

int compareObject(const void *a, const void *b) {
    return ((struct object*)a)->value - ((struct object*)b)->value;
}

int* twoSum(int* nums, int numsSize, int target) {
    struct object *objs = (struct object*)malloc(sizeof(*objs) * numsSize);
    for(int i = 0; i < numsSize; i++) {
        objs[i].key = i;
        objs[i].value = nums[i];
    }
    
    qsort(objs, numsSize, sizeof(*objs), compareObject);
    
    int left = 0;
    int right = numsSize - 1;
    while (left < right) {
        int diff = target - objs[left].value;
        if (diff < objs[right].value) {
            while (--right > left && objs[right].value == objs[right + 1].value) {
                
            }
        }
        else if (diff > objs[right].value) {
            while (++left < right && objs[left].value == objs[left - 1].value) {
                
            }
        }
        else {
            int *ret = (int *)malloc(sizeof(int) * 2);
            ret[0] = objs[left].key;
            ret[1] = objs[right].key;
            return ret;
        }
    }
    
    return NULL;
}

void test_0001() {
    int nums[5] = { 2, 7, 11, 15 };
    int target = 9;
    int *ret = twoSum(nums, sizeof(nums) / sizeof(nums[0]), target);
    printf("%d->%d\n",ret[0],ret[1]);
}

