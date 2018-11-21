//
//  leetCode-0004.swift
//  leetCode-swift
//
//  Created by kaisa-ios-001 on 2018/11/21.
//  Copyright © 2018年 Giga. All rights reserved.
//

import Foundation

func findMedianSortedArrays(_ nums1: [Int], _ nums2: [Int]) -> Double {
    let m = nums1.count
    let n = nums2.count
    let left = (m + n + 1) / 2
    let right = (m + n + 2) / 2
    
    return Double((findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right))) / 2.0
}

func findKth(_ nums1: [Int],_ i: Int, _ nums2: [Int], _ j: Int, _ k: Int) -> Int {
    if i >= nums1.count {
        return nums2[j + k - 1]
    }
    
    if j >= nums2.count {
        return nums1[i + k - 1]
    }
    
    if k == 1 {
        return min(nums1[i], nums2[j])
    }
    
    let midVal1 = (i + k / 2 - 1 < nums1.count) ? nums1[i + k / 2 - 1] : Int.max
    let midVal2 = (j + k / 2 - 1 < nums2.count) ? nums2[j + k / 2 - 1] : Int.max
    
    if midVal1 < midVal2 {
        return findKth(nums1, i + k / 2, nums2, j, k - k / 2)
    }
    else {
        return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
    }
}

func test_0004() {
    let nums1 = [1, 3, 4]
    let nums2 = [2]
    let ret = findMedianSortedArrays(nums1, nums2)
    print(ret)
}


