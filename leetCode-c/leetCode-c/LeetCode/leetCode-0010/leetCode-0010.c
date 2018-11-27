//
//  leetCode-0010.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/11/22.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0010.h"

#include <stdbool.h>

bool isMatch(char* s, char* p) {
    
    if (*p == '\0') {
        return *s == '\0';
    }
    
    if (*(p + 1) == '\0') {
        return (*(s + 1) == '\0' && (*s == *p || *p == '.'));
    }
    
    if (*(p + 1) != '*') {
        if (*s == '\0') {
            return false;
        }
        return (*s == *p || p[0] == '.') && isMatch(s + 1, p + 1);
    }
    
    while (*s != '\0' && (*s == *p || *p == '.')) {
        if (isMatch(s, p + 2)) {
            return true;
        }
        s = s + 1;
    }
    
    return isMatch(s, p + 2);
}

void test_0010(void) {
    char *s[5] = { "aa", "aa", "ab", "aab", "mississippi" };
    char *p[5] = { "a", "a*", ".*", "c*a*b", "mis*is*p*." };
    for (int i = 0; i < 5; i++) {
        int len = isMatch(s[i],p[i]);
        printf("len = %d\n",len);
    }
}
