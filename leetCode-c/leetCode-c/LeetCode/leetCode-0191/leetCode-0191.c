//
//  leetCode-0191.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/22.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0191.h"

int hammingWeight(uint32_t n) {
    int count = 0;
    for (int i = 0; i < 32; i++) {
        if (((n >> i) & 1) == 1) {
            count += 1;
        }
    }
    
    return count;
}

void test_0191(void) {
    uint32_t t = 00000000000000000000000000001011;
    
    int count = hammingWeight(t);
    printf("count = %d\n", count);
}
