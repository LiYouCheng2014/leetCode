//
//  leetCode-0003.swift
//  leetCode-swift
//
//  Created by kaisa-ios-001 on 2018/11/21.
//  Copyright © 2018年 Giga. All rights reserved.
//

import Foundation

func lengthOfLongestSubstring(_ s: String) -> Int {
    var offset = [Int](repeating: 0, count: 256)
    var left = 0
    var res = 0
    
    for (i, c) in s.utf8.enumerated() {
        let cInt = Int(c)
        if offset[cInt] == 0 || offset[cInt] < left {
            res = max(res, i - left + 1)
        }
        else {
            left = offset[cInt]
        }
        offset[cInt] = i + 1
    }
    
    return res
}
//    for c in s.utf8 {
//        let cInt = Int(c)
//        if offset[cInt] == 0 || offset[cInt] < left {
//            res = max(res, )
//        }
//    }
//
//    var maxLen = 0
//    var len = 0
//    var index = 0
//
//    for c in s.utf8 {
//        let cInt = Int(c)
//        if offset[cInt] == -1 {
//            len += 1;
//        }
//        else {
//            len = (index - offset[cInt] > len) ? len + 1 : index - offset[cInt]
//        }
//
//        maxLen = max(maxLen, len)
//
//        offset[cInt] = index;
//        index += 1;
//    }
//    return maxLen
func test_0003() {
    //bbbbb
    //pwwkew
    //abcabcbb
    let arr = [ "abcabcbb", "bbbbb", "pwwkew" ]
    for sub in arr {
        let len = lengthOfLongestSubstring(sub)
        print(len)
    }
}
