//
//  leetCode-0016.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/11/27.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0016.h"

/*
 需要定义一个变量diff用来记录差的绝对值，然后我们还是要先将数组排个序，然后开始遍历数组，思路跟那道三数之和很相似，都是先确定一个数，然后用两个指针left和right来滑动寻找另外两个数，每确定两个数，我们求出此三数之和，然后算和给定值的差的绝对值存在newDiff中，然后和diff比较并更新diff和结果closest即可
 */

#include <stdlib.h>

int compareInt2(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int threeSumClosest(int* nums, int numsSize, int target) {

    qsort(nums, numsSize, sizeof(*nums), compareInt2);

    int closet = nums[0] + nums[1] + nums[2];
    int diff = abs(closet - target);
    
    for (int i = 0; i < numsSize; i++) {
        int left = i + 1;
        int right = numsSize - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            int newDiff = abs(sum - target);
            if (diff > newDiff) {
                diff = newDiff;
                closet = sum;
            }
            
            if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    
    return closet;
}

void test_0016()
{
    int arr[4] = { -1, 2, 1, -4 };
    int target = 1;
    int ret = threeSumClosest(arr, 4, target);
    
    printf("ret = %d\n",ret);
}
