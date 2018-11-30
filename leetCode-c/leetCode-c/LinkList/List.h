//
//  List.h
//  leetCode
//
//  Created by liyoucheng on 2018/11/18.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#ifndef List_h
#define List_h

#include "comman.h"

//顺序
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SqList;

//链式
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;

//静态
typedef struct
{
    ElemType data;
    int cur;
}Component, StaticLinkList[MAXSIZE];

//双向链表
typedef struct double_link_list_node
{
    struct double_link_list_node *prev;
    struct double_link_list_node *next;
    int data;
}DoubleLinkListNode;

typedef struct double_link_list_head
{
    int size;
    DoubleLinkListNode *head;//头指针
    DoubleLinkListNode *tail;//尾指针
}DoubleLinkListHead;

#endif /* List_h */
