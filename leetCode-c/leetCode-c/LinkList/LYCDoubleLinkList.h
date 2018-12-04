//
//  LYCDoubleLinkList.h
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/1.
//  Copyright © 2018年 Giga. All rights reserved.
//

#ifndef LYCDoubleLinkList_h
#define LYCDoubleLinkList_h

#include <stdio.h>

//双向链表
typedef struct double_link_list_node
{
    struct double_link_list_node *prev;
    struct double_link_list_node *next;
    int data;
}DoubleLinkListNode;

typedef struct double_link_list
{
    int size;
    DoubleLinkListNode *head;//头指针
    DoubleLinkListNode *tail;//尾指针
}DoubleLinkList;

#endif /* LYCDoubleLinkList_h */
