//
//  LYCArrayQueue.h
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/1.
//  Copyright © 2018年 Giga. All rights reserved.
//

#ifndef LYCArrayQueue_h
#define LYCArrayQueue_h

#include <stdio.h>

typedef int ArrayQueueData;

typedef struct array_queue {
    int size;/*队列的大小*/
    int num; /*当前存储数据的大小*/
    int head;/*队列的头*/
    int tail;/*队列的尾*/
    int *array;/*数据存储区*/
}ArrayQueue;

void arrayQueueTest(void);

#endif /* LYCArrayQueue_h */
