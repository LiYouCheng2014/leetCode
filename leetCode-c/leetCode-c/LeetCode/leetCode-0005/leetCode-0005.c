//
//  leetCode-0005.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/11/21.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0005.h"

#include <stdlib.h>
#include <string.h>

#include "comman.h"

//最长子串的长度是半径减1，起始位置是中间位置减去半径再除以2。
//p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
int manacher(char *s, char output[])
{
    int i, j;
    char t[3000] = { '\0' };
    
    // 填充$和#
    t[0] = '$';
    for (i = 0; s[i] != '\0'; i++) {
        t[(i<<1)+1] = '#';
        t[(i<<1)+2] = s[i];
    }
    t[(i<<1)+1] = '#';
    int len = (i<<1)+2;
    t[len] = '\0';
    
    int p[3000] = { 0 }; // 以t中某一点为中心的回文半径
    int id = 0; // 回文的中心点
    int mx = 0; // 最长回文的右边界点
    int resLen = 0; // 最大回文长度
    int resCenter = 0; // 最长回文的中心点
    for (i = 1; i < len; i++) {
        if (i < mx) {
            p[i] = min(p[2*id-i], mx-i);
        } else {
            p[i] = 1;
        }
        
        while (t[i+p[i]] == t[i-p[i]]) {
            p[i]++;
        }
        
        if (i+p[i] > mx) {
            mx = i+p[i];
            id = i;
        }
        
        if (resLen < p[i]-1) {
            resLen = p[i]-1;
            resCenter = i;
        }
    }
    
    for (j = 0, i = resCenter - resLen; i <= resCenter + resLen; i++) {
        if (t[i] != '#') {
            output[j++] = t[i];
        }
    }
    return resLen;
}

char *longestPalindrome(char *s)
{
    if (s == NULL) {
        return NULL;
    }
    
    int len = (int)strlen(s);
    if (len <= 1) {
        return s;
    }
    
    char *palindrome = malloc(2000);
    memset(palindrome, 0, sizeof(malloc(2000)));
    
    int size = manacher(s, palindrome);
    palindrome[size] = '\0';
    return palindrome;
}

void test_0005() {
    char *s = "babad";
    char *ret = longestPalindrome(s);
    printf("%s\n",ret);
}


