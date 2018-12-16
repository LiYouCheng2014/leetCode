//
//  leetCode-0069.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/7.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0069.h"

int mySqrt(int x) {
    if (x <= 1) {
        return x;
    }
    
    int low = 0;
    int high = x;
    while (low < high) {
        int mid = low + ((high - low) >> 1);
        if (x / mid >= mid) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    
    return high - 1;
}

void test_0069(void) {
    int ret = mySqrt(8);
    printf("ret = %d\n", ret);
}
