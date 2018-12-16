//
//  leetCode-0013.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/16.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0013.h"

int roman_to_integer(char c)
{
    switch(c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int romanToInt (char *s)
{
    int result = roman_to_integer(s[0]);
    for (int i = 1; s[i] != '\0'; i++) {
        int prev = roman_to_integer(s[i-1]);
        int curr = roman_to_integer(s[i]);
        if (prev < curr) {
            result = result - prev + (curr - prev);
        }
        else {
            result = result + curr;
        }
    }
    
    return result;
}

void test_0013(void) {
    
}
