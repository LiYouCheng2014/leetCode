//
//  leetCode-0011.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/11/22.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0011.h"

/*
 定义left和right两个指针分别指向数组的左右两端，然后两个指针向中间搜索，每移动一次算一个值和结果比较取较大的，容器装水量的算法是找出左右两个边缘中较小的那个乘以两边缘的距离
 */

int maxArea(int* height, int heightSize) {
    
    int left = 0;
    int right = heightSize - 1;
    
    int max = 0;
    
    while (left < right) {
        int value = (height[left] < height[right] ? height[left] : height[right]);
        int temp = value * (right - left);
        max = (max > temp ? max : temp);
        
        if (height[left] < height[right]) {
            //去重
            while (left++ < right && height[left] == height[left - 1]) {
                
            }
        }
        else {
            //去重
            while (left < right-- && height[right] == height[right + 1]) {
                
            }
        }
    }
    
    return max;
}

void test_0011(void) {
    int nums[9] = { 1,8,6,2,5,4,8,3,7 };
    int len = maxArea(nums, 9);
    printf("len = %d\n",len);
}
