//
//  kmp.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/30.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "kmp.h"

#include <string.h>
#include <stdlib.h>

void getNext(char *t, int *next) {
    
    int j = 1;
    int k = 0;
    
//    next[j] = 0;
    int len = (int)strlen(t);
    while (j < len + 1) {
        
        if (k == 0 || t[j - 1] == t[k - 1]) { // t[j]表示后缀的单个字符，t[k]表示前缀的单个字符
            
            ++j;
            ++k;
            next[j] = k;
        }
        else {
            
            k = next[k]; // 若字符不相同，则j值回溯
        }
    }
}

void getNextval(char *t, int *next) {
    
    int j = 1;
    int k = 0;
    
//        next[j] = 0;
    int len = (int)strlen(t);
    while (j < len + 1) {
        
        if (k == 0 || t[j - 1] == t[k - 1]) { // t[j]表示后缀的单个字符，t[k]表示前缀的单个字符
            
            ++j;
            ++k;
            if (t[j - 1] != t[k - 1]) {
                next[j] = k;
            }
            else {
                next[j] = next[k];
            }
        }
        else {
            
            k = next[k]; // 若字符不相同，则j值回溯
        }
    }
}

// 当前要匹配的串T的next数组

// 返回子串t在主串s中第pos个字符之后的位置，若不存在，则函数返回返回值0
int indexKMP(char *s, char *t, int pos) {
    
    int i = pos; //i 用于主串s当前位置下标值，若pos不为1，则从pos位置开始
    int j = 1; //j 用于子串T中当前位置下标值
    
    int sLen = (int)strlen(s);
    int tLen = (int)strlen(t);
    int *next = malloc(sizeof(int) * (tLen));
    getNext(t, next); // 对串t做分析，得到next数组
    
    while (i <= sLen && j <= tLen) {
        
        if (j == 0 || s[i - 1] == t[j - 1]) { // 两字母相等则继续
            
            ++i;
            ++j;
        }
        else {
            j = next[j]; // j退回合适的位置，i值不变
        }
    }
    
    if (j > tLen) {
        
        return i - tLen;
    }
    else {
        
        return 0;
    }
}// O(n+m)

void printNext(char *t) {
    int len = (int)strlen(t);
    
    int *next = malloc(sizeof(int) * (len));
    getNextval(t, next);
    
    for (int i = 1; i < len + 1; i++) {
        
        printf("%d ", next[i]);
    }
    printf("\n");
}

void testKMP(void) {
    
    char *s = "abcdefgab";
    char *t = "def";
    
    int index = indexKMP(s, t, 1);
    printf("index = %d\n",index);
//    char *t1 = "abcdex";//011111
//    char *t2 = "abcabx";//011123
//    char *t3 = "ababaaaba";//011234223 010104210
//    char *t4 = "aaaaaaaab";//012345678
//    printNext(t1);
//    printNext(t2);
//    printNext(t3);
//    printNext(t4);
    
    
}
