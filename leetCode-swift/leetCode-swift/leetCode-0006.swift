//
//  leetCode-0006.swift
//  leetCode-swift
//
//  Created by liyoucheng on 2018/11/21.
//  Copyright © 2018年 Giga. All rights reserved.
//

import Foundation



func convert(_ s: String, _ numRows: Int) -> String {
    if numRows <= 1 {
        return s
    }
    
    var res: [Character] = []
    let size = 2 * numRows - 2
    for i in 0..<numRows {
        for j in stride(from: i, to: s.count, by: size) {

            res.append(s[s.index(s.startIndex, offsetBy: j)])

            let temp = j + size - 2 * i
            if (i != 0 && i != numRows - 1 && temp < s.count) {
                
                res.append(s[s.index(s.startIndex, offsetBy: temp)])
            }
        }
    }
    
    return String(res)
}


func test_0006() {
    let s = convert("PAYPALISHIRING", 3)
    print(s)
}
