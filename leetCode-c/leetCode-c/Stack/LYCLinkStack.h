//
//  LYCLinkStack.h
//  leetCode-c
//
//  Created by liyoucheng on 2018/11/29.
//  Copyright © 2018年 Giga. All rights reserved.
//

#ifndef LYCLinkStack_h
#define LYCLinkStack_h

#include <stdio.h>
#include <stdbool.h>

typedef char LinkStackData;

//节点
typedef struct link_stack_node {
    LinkStackData data;
    struct link_stack_node *next;
}LinkStackNode;

typedef struct link_stack {
    LinkStackNode *top;//栈顶
    int count;//栈大小
}LinkStack;

LinkStack *linkStackCreate(void);
bool linkStackIsEmpty(LinkStack *stack);
int linkStackPush(LinkStack *stack, LinkStackData data);
int linkStackPop(LinkStack *stack, LinkStackData *data);
int linkStackTop(LinkStack *stack, LinkStackData *data);
void linkStackDestory(LinkStack *stack);

void linkStackTest(void);

#endif /* LYCLinkStack_h */
