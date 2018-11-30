//
//  LYCLinkList.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/11/29.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "LYCLinkList.h"

#include <stdlib.h>

//带头结点
//头插
struct ListNode *linkListCreateHead(int *arr, int size)
{
    struct ListNode *list;
    list = (struct ListNode*)malloc(sizeof(struct ListNode));
    list->next = NULL;

    for (int i = 0; i < size; i++) {
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val = arr[i];
        temp->next = NULL;
        
        //头插法
        temp->next = list->next;
        list->next = temp;
    }
    
    return list;
}

//尾插
struct ListNode *linkListCreateTail(int *arr, int size)
{
    struct ListNode *list;
    list = (struct ListNode*)malloc(sizeof(struct ListNode));
    list->next = NULL;
    
    for (int i = 0; i < size; i++) {
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val = arr[i];
        temp->next = NULL;
        
        //尾插法
        struct ListNode *p = list->next;
        while (p != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
    
    return list;
}

struct ListNode *linkListFindNode(struct ListNode *list, int data) {
    struct ListNode *p = list->next;
    while (p != NULL) {
        if (p->val == data) {
            return p;
        }
        p = p->next;
    }
    
    return NULL;
}

int linkListFindIndex(struct ListNode *list, int i, int *e) {
    struct ListNode *p = list->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    
    if (!p || j > i) {
        return -1;
    }
    
    *e = p->val;
    return 0;
}

int linkListInsert(struct ListNode *list, int i, int e) {
    struct ListNode *p = list->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    
    if (!p || j > i) {
        return -1;
    }
    
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->val = e;
    temp->next = p->next;
    p->next = temp;
    
    return 0;
}

int linkListInsertDelete(struct ListNode *list, int i, int *e)
{
    struct ListNode *p = list->next;
    int j = 1;
    while (p->next && j < i) {
        p = p->next;
        ++j;
    }
    
    if (!(p->next) || j > i) {
        return -1;
    }
    struct ListNode *q = p->next;
    p->next = q->next;
    *e = q->val;
    free(q);
    
    return 0;
}

int linkListDestory(struct ListNode *list)
{
    struct ListNode *p = list->next;
    struct ListNode *q;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    
    free(p);
    
    return 0;
}

void printNode(struct ListNode *p)
{
    struct ListNode *temp = p;
    while (temp) {
        printf("%d",temp->val);
        temp = temp->next;
        if (temp) {
            printf("->");
        }
    }
    printf("\n");
}
