//
//  leetCode-0008.swift
//  leetCode-swift
//
//  Created by kaisa-ios-001 on 2018/11/22.
//  Copyright © 2018年 Giga. All rights reserved.
//

import Foundation

func myAtoi(_ str: String) -> Int {
    var numStarted = false
    var result = 0
    var sign = 1
    
    for char in str {
        if char == " " && !numStarted {
            
        } else if char == "+" && !numStarted {
            numStarted = true
        } else if char == "-" && !numStarted {
            sign = -1
            numStarted = true
        } else if let digit = Int(String(char)) {
            numStarted = true
            if sign == 1 && (Int(Int32.max) - digit) / 10 < result {
                return Int(Int32.max)
            } else if sign == -1 && (Int(Int32.min) + digit) / 10 > (result * sign) {
                return Int(Int32.min)
            } else {
                result = (result * 10) + digit
            }
        } else {
            return result * sign
        }
    }
    
    return result * sign
}

func test_0008() {
    let arr = [ " ","42", "   -42", "4193 with words", "words and 987", "-91283472332" ]
    for num in arr {
        print(myAtoi(num))
    }
}
