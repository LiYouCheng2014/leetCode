//
//  leetCode-0001.swift
//  leetCode-swift
//
//  Created by liyoucheng on 2018/11/21.
//  Copyright © 2018年 Giga. All rights reserved.
//

import Foundation

func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
    var dict = [Int: Int]()
    
    for (i, num) in nums.enumerated() {
        if let lastIndex = dict[target - num] {
            return [lastIndex, i]
        }
        else {
            dict[num] = i;
        }
    }
    
    return []
}

func test_0001() {
    let nums = [ 2, 7, 11, 15 ]
    let target = 9
    let ret = twoSum(nums, target)
    print(ret)
}
