//
//  leetCode-0225.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/1.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0225.h"

#include "LYCLinkQueue.h"

#include <stdlib.h>

typedef struct {
    LinkQueue *q;
} MyStack;

MyStack* myStackCreate(int maxSize) {
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    stack->q = linkQueueCreate();
    
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    LinkQueue *queue = linkQueueCreate();
    //把obj的元素也逆着顺序存入queue中
    while (!linkQueueIsEmpty(obj->q)) {
        linkQueueEnqueue(queue, obj->q->head->data);
        
        int data = 0;
        linkQueueDequeue(obj->q, &data);
    }
    
    //加入新元素x
    linkQueueEnqueue(obj->q, x);
    
    //把queue中的元素存回来
    while (!linkQueueIsEmpty(queue)) {
        linkQueueEnqueue(obj->q, queue->head->data);
        
        int data = 0;
        linkQueueDequeue(queue, &data);
    }
    
    free(queue);
}

int myStackPop(MyStack* obj) {
    int data;
    linkQueueDequeue(obj->q, &data);
    
    return data;
}

int myStackTop(MyStack* obj) {
    return obj->q->head->data;
}

bool myStackEmpty(MyStack* obj) {
    return linkQueueIsEmpty(obj->q);
}

void myStackFree(MyStack* obj) {
    linkQueueDestory(obj->q);
    
    free(obj);
}

void test_0225(void) {
    MyStack *stack = myStackCreate(5);
    myStackPush(stack, 1);
    myStackPush(stack, 2);
    myStackPush(stack, 3);
    myStackPush(stack, 4);
    
    while (!myStackEmpty(stack)) {
        int data = myStackPop(stack);
        printf("%d\n", data);
    }
}
