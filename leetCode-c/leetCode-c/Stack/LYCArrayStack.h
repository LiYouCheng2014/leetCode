//
//  LYCArrayStack.h
//  leetCode-c
//
//  Created by liyoucheng on 2018/11/29.
//  Copyright © 2018年 Giga. All rights reserved.
//

#ifndef LYCArrayStack_h
#define LYCArrayStack_h

#include <stdio.h>

typedef int ArrayStackData;

typedef struct array_stack
{
    int size;//栈大小
    int top;//栈顶元素下标
    ArrayStackData *array;//数据存储区
}ArrayStack;

void arrayStackTest(void);

#endif /* LYCArrayStack_h */
