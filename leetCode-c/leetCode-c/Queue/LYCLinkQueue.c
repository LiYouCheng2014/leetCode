//
//  LYCLinkQueue.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/1.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "LYCLinkQueue.h"

#include <stdlib.h>

LinkQueue *linkQueueCreate() {
    LinkQueue *queue = NULL;
    
    queue = (LinkQueue *)malloc(sizeof(LinkQueue));
    if (queue == NULL) {
        return NULL;
    }
    
    queue->head = NULL;
    queue->tail = NULL;
    queue->count = 0;
    
    return queue;
}

bool linkQueueIsEmpty(LinkQueue *queue) {
    return queue->count == 0;
}

int linkQueueEnqueue(LinkQueue *queue, LinkQueueData data) {
    if (queue == NULL) {
        return -1;
    }
    
    LinkQueueNode *p = NULL;
    
    p = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (p == NULL) {
        return -1;
    }
    
    p->data = data;
    p->next = NULL;
    if (queue->head == NULL) {
        queue->head = p;
    }
    else {
        queue->tail->next = p;
    }
    queue->tail = p;
    queue->count++;
    
    return 0;
}

int linkQueueDequeue(LinkQueue *queue, LinkQueueData *data) {
    if (queue == NULL || linkQueueIsEmpty(queue)) {
        return -1;
    }
    
    *data = queue->head->data;
    
    LinkQueueNode *p = queue->head;
    p = queue->head;
    queue->head = queue->head->next;
    queue->count--;
    
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    
    free(p);
    
    return 0;
}

void linkQueueDestory(LinkQueue *queue) {
    
    if (queue != NULL && !linkQueueIsEmpty(queue)) {
        
        LinkQueueData data;
        while (!linkQueueIsEmpty(queue)) {
            int ret = linkQueueDequeue(queue, &data);
            if (ret != 0) {
                printf("delete failure\n");
            }
        }
        
        free(queue);
    }
    
}

void linkQueueDump(LinkQueue *queue) {
    
    if (queue != NULL) {
        LinkQueueNode *p = queue->head;
        printf("queue: size => %d\n",queue->count);
        while (p != NULL) {
            printf("%d\n",p->data);
            p = p->next;
        }
    }
}

void linkQueueTest(void) {
    LinkQueue *queue = NULL;
    
    queue = linkQueueCreate();
    if (queue == NULL) {
        return;
    }
    
    for (int i = 0; i < 5; i++) {
        int ret = linkQueueEnqueue(queue, i);
        if (ret != 0) {
            printf("insert failure => %d\n",i);
        }
        else {
            printf("insert success => %d\n",i);
        }
    }
    
    linkQueueDump(queue);
    
    LinkQueueData data;
    int ret = linkQueueDequeue(queue, &data);
    if (ret != 0) {
        printf("delete failure\n");
        return;
    }
    
    linkQueueDump(queue);
    
    linkQueueDestory(queue);
}
