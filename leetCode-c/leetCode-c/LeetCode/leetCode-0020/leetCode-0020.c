//
//  leetCode-0020.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/1.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0020.h"

#include <stdlib.h>
#include <stdbool.h>

#include "LYCLinkStack.h"

bool isValid(char* s) {
    LinkStack *stack = linkStackCreate();
    
    while (*s != '\0') {
        if (*s == '(' || *s == '[' || *s == '{') {
            linkStackPush(stack, *s);
        }
        else {
            if (linkStackIsEmpty(stack)) {
                return false;
            }
            
            char c;
            linkStackTop(stack, &c);
            
            if (*s == ')' && c != '(') {
                return false;
            }
            
            if (*s == ']' && c != '[') {
                return false;
            }
            
            if (*s == '}' && c != '{') {
                return false;
            }
            
            linkStackPop(stack, &c);
        }
        s++;
    }
    
    return linkStackIsEmpty(stack);
}

void test_0020(void) {
    char *arr[5] = { "()", "()[]{}", "(]", "([)]", "{[]}" };
    for (int i = 0; i < 5; i++) {
        char *s = arr[i];
        bool ret = isValid(s);
        printf("ret = %d\n",ret);
    }
}
