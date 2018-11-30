//
//  LYCLinkStack.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/11/29.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "LYCLinkStack.h"

#include <stdlib.h>
#include <stdbool.h>

int linkStackSize(LinkStack *stack) {
    return stack->count;
}

bool linkStackIsEmpty(LinkStack *stack) {
    return stack->count == 0;
}

LinkStack *linkStackCreate() {
    LinkStack *stack = NULL;
    
    stack = (LinkStack *)malloc(sizeof(LinkStack));
    if (stack == NULL) {
        return NULL;
    }
    
    stack->top = NULL;
    stack->count = 0;
    
    return stack;
}

void linkStackDestory(LinkStack *stack) {
    LinkStackNode *p = NULL;
    
    while (stack->top) {
        p = stack->top;
        stack->top = p->next;
        stack->count--;
        free(p);
    }
    
    free(stack);
}

int linkStackPush(LinkStack *stack, LinkStackData data) {
    LinkStackNode *p = NULL;
    
    p = (LinkStackNode *)malloc(sizeof(LinkStackNode));
    if (p == NULL) {
        return -1;
    }
    
    p->data = data;
    p->next = stack->top;
    stack->top = p;
    stack->count++;
    
    return 0;
}

int linkStackPop(LinkStack *stack, LinkStackData *data) {
    if (linkStackIsEmpty(stack)) {
        return -1;
    }
    
    LinkStackNode *p = stack->top;
    *data = p->data;
    stack->top = p->next;
    stack->count--;
    
    free(p);
    
    return 0;
}

void linkStackDump(LinkStack *stack) {
     LinkStackNode *p = stack->top;
    printf("stack: size => %d\n",stack->count);
    while (p) {
        printf("%d\n",p->data);
        p = p->next;
    }
}

void linkStackTest(void) {
    LinkStack *stack = NULL;
    
    stack = linkStackCreate();
    if (stack == NULL) {
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        int ret = linkStackPush(stack, i);
        if (ret != 0) {
            printf("insert failure => %d\n",i);
        }
        else {
            printf("insert success => %d\n",i);
        }
    }
    
    linkStackDump(stack);
    
    LinkStackData data;
    for (int i = 0; i < 5; i++) {
        int ret = linkStackPop(stack, &data);
        if (ret != 0) {
            printf("delete failure => %d\n",i);
            return;
        }
        else {
            printf("delete success => %d\n",data);
        }
    }

    linkStackDestory(stack);
}

