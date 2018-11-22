//
//  leetCode-0007.c
//  leetCode-c
//
//  Created by kaisa-ios-001 on 2018/11/22.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0007.h"

#include <limits.h>

int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) {
            return 0;
        }
        
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) {
            return 0;
        }
        
        rev = rev * 10 + pop;
        
    }
    
    return rev;
}

void test_0007() {
    int a[4] = { 123, -123, 120, 1534236469 };
    for (int i = 0; i < 4; i++) {
        int ret = reverse(a[i]);
        printf("%d\n",ret);
    }
    
    
}
