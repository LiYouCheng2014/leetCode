//
//  leetCode-0242.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/16.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0242.h"

#include <stdbool.h>
#include <string.h>


bool isAnagram(char* s, char* t) {
    int count[26];
    for (int i = 0; i < 26; i++) {
        count[i] = 0;
    }
    
    while (*s != '\0') {
        count[*s - 'a']++;
        s++;
    }
    
    while (*t != '\0') {
        count[*t - 'a']--;
        t++;
    }
    
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    
    return true;
}

//    int sLen = (int)strlen(s);
//    int tLen = (int)strlen(t);
//    if (sLen != tLen) {
//        return false;
//    }
//
//    int m[26] = {0};
//    for (int i = 0; i < sLen; i++) {
//        m[s[i] - 'a'] += 1;
//    }
//
//    for (int i = 0; i < tLen; i++) {
//        m[t[i] - 'a'] -= 1;
//        if (m[t[i] - 'a'] < 0) {
//            return false;
//        }
//    }
//
//    return  true;

void test_0242(void) {
    char *s = "anagram";
    char *t = "nagaram";
    //    char *s = "rat";
    //    char *t = "car";
    
    bool flag = isAnagram(s, t);
    printf("flag = %d\n", flag);
}
