//
//  LYCArrayQueue.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/1.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "LYCArrayQueue.h"

#include <stdlib.h>
#include <stdbool.h>

bool arrayQueueIsEmpty(ArrayQueue *queue) {
    return queue->num == 0;
}

bool arrayQueueIsFull(ArrayQueue *queue) {
    return queue->num == queue->size;
}

ArrayQueue *arrayQueueCreate(int size) {
    ArrayQueue *queue = NULL;
    
    queue = (ArrayQueue *)malloc(sizeof(ArrayQueue));
    if (queue == NULL) {
        return NULL;
    }
    
    queue->array = (ArrayQueueData *)malloc(sizeof(ArrayQueueData) * size);
    if (queue->array == NULL) {
        free(queue);
        return NULL;
    }
    
    queue->size = size;
    queue->num = 0;
    queue->head = 0;
    queue->tail = 0;
    
    return queue;
}

void arrayQueueDestory(ArrayQueue *queue) {
    if (queue == NULL) {
        return;
    }
    
    if (queue->array != NULL) {
        free(queue->array);
    }
    
    free(queue);
}

int arrayQueueEnqueue(ArrayQueue *queue, ArrayQueueData data) {
    if (queue == NULL || arrayQueueIsFull(queue)) {
        return -1;
    }
    
    queue->num++;
    queue->array[queue->tail] = data;
    queue->tail = (queue->tail + 1) % queue->size;
    
    return 0;
}

int arrayQueueDequeue(ArrayQueue *queue, ArrayQueueData *data) {
    if (queue == NULL || arrayQueueIsEmpty(queue)) {
        return -1;
    }
    
    *data = queue->array[queue->head];
    queue->num--;
    queue->head = (queue->head + 1) % queue->size;
    
    return 0;
}

void arrayQueueDump(ArrayQueue *queue) {
    if (queue != NULL && !arrayQueueIsEmpty(queue)) {
        printf("size => %d, num =>%d, head => %d, tail => %d\n", queue->size, queue->num, queue->head, queue->tail);
        
        for (int i = 0; i < queue->num; i++) {
            int pos = (queue->head + i) % queue->size;
            printf("array[%d] = %d\n",pos, queue->array[pos]);
        }
    }
}

void arrayQueueTest(void) {

    ArrayQueue *queue = NULL;
    queue = arrayQueueCreate(4);
    if (queue == NULL) {
        return;
    }

    int data = 0;
    int ret = 0;
    ret = arrayQueueDequeue(queue, &data);
    if (ret != 0) {
        printf("dequeue failed\n");
    }
    
    /*队列大小是4，入队5个，最后一个报错*/
    for (int i = 0; i < 5; i++) {
        ret = arrayQueueEnqueue(queue, i);
        if (ret != 0) {
            printf("enqueue failed %d\n", i);
            
        }
    }
    
    arrayQueueDump(queue);
    
    ret = arrayQueueDequeue(queue, &data);
    if (ret != 0) {
        printf("dequeue failed\n");
    }
    
    arrayQueueDump(queue);
    data = 5;
    
    ret = arrayQueueEnqueue(queue,data);
    if (ret != 0) {
        printf("enqueue failed %d\n",data);
    }
    arrayQueueDump(queue);
    
    arrayQueueDestory(queue);
}
