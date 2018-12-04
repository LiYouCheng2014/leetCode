//
//  LYCLinkQueue.h
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/1.
//  Copyright © 2018年 Giga. All rights reserved.
//

#ifndef LYCLinkQueue_h
#define LYCLinkQueue_h

#include <stdio.h>

#include <stdbool.h>

typedef int LinkQueueData;

//节点
typedef struct link_queue_node {
    LinkQueueData data;
    struct link_queue_node *next;
}LinkQueueNode;

typedef struct link_queue {
    LinkQueueNode *head;//队头
    LinkQueueNode *tail;//队尾
    int count;//队大小
}LinkQueue;

void linkQueueTest(void);

LinkQueue *linkQueueCreate(void);

bool linkQueueIsEmpty(LinkQueue *queue);

int linkQueueEnqueue(LinkQueue *queue, LinkQueueData data);

int linkQueueDequeue(LinkQueue *queue, LinkQueueData *data);

void linkQueueDestory(LinkQueue *queue);

#endif /* LYCLinkQueue_h */
