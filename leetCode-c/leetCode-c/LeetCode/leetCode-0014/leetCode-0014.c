//
//  leetCode-0014.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/16.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0014.h"

#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
    int count = 0;
    char *result = malloc(1000);
    while (1) {
        char c = strs[0][count];
        int i = 0;
        for (i = 0; i < strsSize; i++) {
            if (c != strs[i][count]) {
                break;
            }
        }
        
        if (i == strsSize && c != '\0') {
            result[count++] = c;
        }
        else {
            break;
        }
    }
    result[count++] = '\0';
    return result;
}


void test_0014(void) {
    
}
