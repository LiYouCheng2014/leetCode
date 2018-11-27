//
//  leetCode-0004.c
//  leetCode
//
//  Created by liyoucheng on 2018/11/16.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0004.h"

/*
 我们使用两个变量left和right分别来标记数组nums1和nums2的起始位置。然后来处理一些corner cases，比如当某一个数组的起始位置大于等于其数组长度时，说明其所有数字均已经被淘汰了，相当于一个空数组了，那么实际上就变成了在另一个数组中找数字，直接就可以找出来了。还有就是如果K=1的话，那么我们只要比较nums1和nums2的起始位置i和j上的数字就可以了。对K二分，意思是我们需要分别在nums1和nums2中查找第K/2个元素，注意这里由于两个数组的长度不定，所以有可能某个数组没有第K/2个数字，所以我们需要先check一下，数组中到底存不存在第K/2个数字，如果存在就取出来，否则就赋值上一个整型最大值。如果某个数组没有第K/2个数字，那么我们就淘汰另一个数字的前K/2个数字即可。有没有可能两个数组都不存在第K/2个数字呢，这道题里是不可能的，因为我们的K不是任意给的，而是给的m+n的中间值，所以必定至少会有一个数组是存在第K/2个数字的。比较这两个数组的第K/2小的数字midVal1和midVal2的大小，如果第一个数组的第K/2个数字小的话，那么说明我们要找的数字肯定不在nums1中的前K/2个数字，所以我们可以将其淘汰，将nums1的起始位置向后移动K/2个，并且此时的K也自减去K/2，调用递归。反之，我们淘汰nums2中的前K/2个数字，并将nums2的起始位置向后移动K/2个，并且此时的K也自减去K/2，调用递归即可
 */

#include <limits.h>


double findKth(int *nums1, int numsSize1, int left, int *nums2, int numsSize2, int right, int k) {
    if (left >= numsSize1) {
        return nums2[right + k - 1];
    }
    
    if (right >= numsSize2) {
        return nums1[left + k - 1];
    }
    
    if (k == 1) {
        return nums1[left] > nums2[right] ? nums2[right] : nums1[left];
    }
    
    int midVal1 = (left + k / 2 - 1 < numsSize1) ? nums1[left + k / 2 -1] : INT_MAX;
    int midVal2 = (right + k / 2 - 1 < numsSize2) ? nums2[right + k / 2 -1] : INT_MAX;
    if (midVal1 < midVal2) {
        return findKth(nums1, numsSize1, left + k / 2, nums2, numsSize2, right, k - k / 2);
    }
    else {
        return findKth(nums1, numsSize1, left, nums2, numsSize2, right + k / 2, k - k / 2);
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    int left = (nums1Size + nums2Size + 1) / 2;
    int right = (nums1Size + nums2Size + 2) / 2;

    return (findKth(nums1, nums1Size, 0, nums2, nums2Size, 0, left) + findKth(nums1, nums1Size, 0, nums2, nums2Size, 0, right)) / 2.0;
}

void test_0004() {
//    int nums1[2] = { 1, 2 };
//    int nums2[2] = { 3, 4 };
//    double m = findMedianSortedArrays(nums1, sizeof(nums1) / sizeof(nums1[0]), nums2, sizeof(nums2) / sizeof(nums2[0]));
//    printf("%f\n",m);
    
    int nums1[2] = { 1, 3 };
    int nums2[1] = { 2 };
    double m = findMedianSortedArrays(nums1, sizeof(nums1) / sizeof(nums1[0]), nums2, sizeof(nums2) / sizeof(nums2[0]));
    printf("%f\n",m);
}

/*
 https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/very-concise-ologminmn-iterative-solution-with-detailed-explanation
 */
//double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
//
//    if (nums1Size < nums2Size) {
//        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
//    }
//
//    int left = 0;
//    int right = 2 * nums2Size;
//
//    while (left <= right) {
//        int mid2 = (left + right) / 2;
//        int mid1 = (nums1Size + nums2Size - mid2);
//        double L1 = mid1 == 0 ? INT_MIN : nums1[(mid1 - 1) / 2];
//        double L2 = mid2 == 0 ? INT_MIN : nums2[(mid2 - 1) / 2];
//        double R1 = mid1 == nums1Size * 2 ? INT_MAX : nums1[mid1 / 2];
//        double R2 = mid2 == nums2Size * 2 ? INT_MAX : nums2[mid2 / 2];
//
//        if (L1 > R2) {
//            left = mid2 + 1;
//        }
//        else if (L2 > R1) {
//            right = mid2 - 1;
//        }
//        else {
//            return ((L1 > L2 ? L1 : L2) + (R1 > R2 ? R2 : R1)) / 2;
//        }
//    }
//
//    return -1;
//}


