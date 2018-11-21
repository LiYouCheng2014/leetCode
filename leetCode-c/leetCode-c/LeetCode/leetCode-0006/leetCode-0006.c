//
//  leetCode-0006.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/11/21.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0006.h"

#include <stdlib.h>
#include <string.h>

//http://www.cnblogs.com/springfor/p/3889414.html

char* convert(char* s, int numRows) {
    if (numRows <= 1) {
        return s;
    }
    
    int len = (int)strlen(s);
    char *new_str = malloc(len + 1);
    char *p = new_str;
    
    for (int row = 0; row < numRows; row++) {
        int interval1 = numRows + (numRows - 2) - row * 2;
        int interval2 = 2 * row;
        
        int i = row;
        int flag = 0;
        while (i < len) {
            *p++ = s[i];
            int delta = 0;
            do {
                delta = flag == 0 ? interval1 : interval2;
                flag = !flag;
            } while (delta == 0);
            i += delta;
        }
    }
    
    new_str[len] = '\0';
    return new_str;
}

void test_0006() {
    char *s = "PAYPALISHIRING";
    char *ret = convert(s, 3);
    printf("%s\n",ret);
}
