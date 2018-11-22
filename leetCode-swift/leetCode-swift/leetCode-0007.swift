//
//  leetCode-0007.swift
//  leetCode-swift
//
//  Created by kaisa-ios-001 on 2018/11/22.
//  Copyright © 2018年 Giga. All rights reserved.
//

import Foundation

func reverse(_ x: Int) -> Int {
    var rev = 0;
    var value = x
    while (value != 0) {
        let pop = value % 10;
        value /= 10;
        
        if (rev > Int32.max / 10 || (rev == Int32.max / 10 && pop > 7)) {
            return 0;
        }
        
        if (rev < Int32.min / 10 || (rev == Int32.min / 10 && pop < -8)) {
            return 0;
        }
        
        rev = rev * 10 + pop;
        
    }
    
    return rev;
}

func test_0007() {
    let arr = [ 123, -123, 120, 1534236469 ]
    for num in arr {
        print(reverse(num))
    }
}
