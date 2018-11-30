//
//  LYCLinkList.h
//  leetCode-c
//
//  Created by liyoucheng on 2018/11/29.
//  Copyright © 2018年 Giga. All rights reserved.
//

#ifndef LYCLinkList_h
#define LYCLinkList_h

#include <stdio.h>

//链式
struct ListNode
{
    int val;
    struct ListNode *next;
};

//头插
struct ListNode *linkListCreateHead(int *arr, int size);

//尾插
struct ListNode *linkListCreateTail(int *arr, int size);

void printNode(struct ListNode *p);

#endif /* LYCLinkList_h */
