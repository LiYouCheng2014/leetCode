//
//  leetCode-0008.c
//  leetCode-c
//
//  Created by kaisa-ios-001 on 2018/11/22.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0008.h"

#include <string.h>
#include <limits.h>

int myAtoi(char* str) {
    int len = (int)strlen(str);
    if (len <= 0) {
        return 0;
    }
    
    //统计空格
    int i = 0;
    while (i < len && str[i] == ' ') {
        ++i;
    }
    
    //符号
    int sign = 1;
    if (str[i] == '+' || str[i] == '-') {
        sign = (str[i++] == '+') ? 1 : -1;
    }
    
    int base = 0;
    while (i < len && str[i] >= '0' && str[i] <= '9') {
        if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        base = 10 * base + (str[i++] - '0');
    }
    
    return base * sign;
}

void test_0008(void) {
    char *s[5] = { "42", "   -42", "4193 with words", "words and 987", "-91283472332" };
    for (int i = 0; i < 5; i++) {
        int len = myAtoi(s[i]);
        printf("len = %d\n",len);
    }
}
