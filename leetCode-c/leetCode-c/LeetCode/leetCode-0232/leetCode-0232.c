//
//  leetCode-0232.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/1.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0232.h"

#include <stdlib.h>

#include "LYCLinkStack.h"

typedef struct {
    LinkStack *old;
    LinkStack *new;
} MyQueue;

MyQueue* myQueueCreate(int maxSize) {
    MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue));
    queue->old = linkStackCreate();
    queue->new = linkStackCreate();
    
    return queue;
}

void shiftStack(MyQueue *queue) {
    if (!linkStackIsEmpty(queue->old)) {
        return;
    }
    
    while (!linkStackIsEmpty(queue->new)) {
        
        char data;
        linkStackTop(queue->new, &data);
        
        linkStackPush(queue->old, data);
        
        linkStackPop(queue->new, &data);
    }
}

void myQueuePush(MyQueue* obj, int x) {
    linkStackPush(obj->new, x);
}

int myQueuePop(MyQueue* obj) {
    shiftStack(obj);
    
    char data;
    linkStackPop(obj->old, &data);
    
    return data;
}

int myQueuePeek(MyQueue* obj) {
    shiftStack(obj);
    
    char data;
    linkStackTop(obj->old, &data);
    
    return data;
}

bool myQueueEmpty(MyQueue* obj) {
    return linkStackIsEmpty(obj->old) && linkStackIsEmpty(obj->new);
}

void myQueueFree(MyQueue* obj) {
    linkStackDestory(obj->old);
    linkStackDestory(obj->new);
    free(obj);
}

void test_0232(void) {
    MyQueue *queue = myQueueCreate(5);
    myQueuePush(queue, 1);
    myQueuePush(queue, 2);
    myQueuePush(queue, 3);
    myQueuePush(queue, 4);
    
    while (!myQueueEmpty(queue)) {
        int data = myQueuePop(queue);
        printf("%d\n",data);
    }
}
