//
//  leetCode-0009.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/11/22.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0009.h"

#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }
    
    int revertedNumer = 0;
    while (x > revertedNumer) {
        revertedNumer = revertedNumer * 10 + x % 10;
        x /= 10;
    }
    
    return x == revertedNumer || x == revertedNumer / 10;
}

void test_0009(void)
{
    int num[3] = { 121, -121, 10 };
    for (int i = 0; i < 3; i++) {
        bool ret = isPalindrome(num[i]);
        printf("ret = %d\n",ret);
    }
}
