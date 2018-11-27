//
//  leetCode-0009.swift
//  leetCode-swift
//
//  Created by liyoucheng on 2018/11/22.
//  Copyright © 2018年 Giga. All rights reserved.
//

import Foundation

func isPalindrome(_ x: Int) -> Bool {
    var y = x
    if (y < 0 || (y % 10 == 0 && y != 0)) {
        return false;
    }
    
    var revertedNumer = 0;
    while (y > revertedNumer) {
        revertedNumer = revertedNumer * 10 + y % 10;
        y /= 10;
    }
    
    return y == revertedNumer || y == revertedNumer / 10;
}

func test_0009() {
    let arr = [ 121, -121, 10 ]
    for num in arr {
        print(isPalindrome(num))
    }
}

