//
//  leetCode-0005.swift
//  leetCode-swift
//
//  Created by liyoucheng on 2018/11/21.
//  Copyright © 2018年 Giga. All rights reserved.
//

import Foundation

extension String {
    func substring(from: Int?, to: Int?) -> String {
        if let start = from {
            guard start < self.count else {
                return ""
            }
        }
        
        if let end = to {
            guard end >= 0 else {
                return ""
            }
        }
        
        if let start = from, let end = to {
            guard end - start >= 0 else {
                return ""
            }
        }
        
        let startIndex: String.Index
        if let start = from, start >= 0 {
            startIndex = self.index(self.startIndex, offsetBy: start)
        } else {
            startIndex = self.startIndex
        }
        
        let endIndex: String.Index
        if let end = to, end >= 0, end < self.count {
            endIndex = self.index(self.startIndex, offsetBy: end + 1)
        } else {
            endIndex = self.endIndex
        }
        
        return String(self[startIndex ..< endIndex])
    }
    
    func substring(from: Int?, length: Int) -> String {
        guard length > 0 else {
            return ""
        }
        
        let end: Int
        if let start = from, start > 0 {
            end = start + length - 1
        } else {
            end = length - 1
        }
        
        return self.substring(from: from, to: end)
    }
}

func longestPalindrome(_ s: String) -> String {

    var t: [Character] = []
    t.append("$")
    t.append("#")
    for c in s {
        t.append(c)
        t.append("#")
    }
    
    var p = [Int](repeatElement(0, count: t.count))
    var mx = 0
    var id = 0
    var resLen = 0
    var resCenter = 0
    for i in t.indices {
        if mx > i {
            p[i] = min(p[2 * id - i], mx - i)
        }
        else {
            p[i] = 1
        }
        
        
        while ((i >= p[i]) && (i + p[i] < t.count) && (t[i + p[i]] == t[i - p[i]])) {
            p[i] += 1
        }

        if (mx < i + p[i]) {
            mx = i + p[i]
            id = i
        }
        
        if (resLen < p[i]) {
            resLen = p[i]
            resCenter = i
        }
        
    }

    return s.substring(from: (resCenter - resLen) / 2, length: resLen - 1)
}

func test_0005() {
    let s = longestPalindrome("babad")
    print(s)
}
