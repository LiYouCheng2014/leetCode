//
//  LYCDoubleLinkList.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/1.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "LYCDoubleLinkList.h"

#include <stdlib.h>
#include <string.h>

void doubleLinkListCreate(DoubleLinkList *list) {
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}

void doubleLinkListDestory(DoubleLinkList *list) {
    DoubleLinkListNode *temp = NULL;
    while (list->size > 0) {
        temp = list->head;
        list->head = temp->next;
        free(temp);
        list->size--;
    }
    
    memset(list, 0, sizeof(DoubleLinkList));
}

int doubleLinkListInsertHead(DoubleLinkList *list, DoubleLinkListNode *node, int data) {
    if (node == NULL) {
        node = (DoubleLinkListNode *)malloc(sizeof(DoubleLinkListNode));
        if (node == NULL) {
            return -1;
        }
    }
    
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    
    if (list->size == 0) {
        list->head = node;
        list->tail = node;
    }
    else {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
    
    list->size++;
    
    return 0;
}

DoubleLinkListNode *doubleLinkListRemoveTail(DoubleLinkList *list) {
    DoubleLinkListNode *node = NULL;
    if (list->size == 0) {
        return NULL;
    }
    
    node = list->tail;
    if (list->size > 1) {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    else {
        list->head = NULL;
        list->tail = NULL;
    }
    list->size--;
    
    return node;
}

void doubleLinkListRemoveNode(DoubleLinkList *list, DoubleLinkListNode *node) {
    if ((list == NULL) || (node == NULL)) {
        return;
    }
    
    if (list->head == node) {
        list->head = list->head->next;
    }
    else if (list->tail == node) {
        list->tail = node->prev;
        list->tail->next = NULL;
    }
    else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    list->size--;
    node->prev = NULL;
    node->next = NULL;
    
    if (list->size == 0) {
        memset(list, 0, sizeof(DoubleLinkList));
    }
}

DoubleLinkListNode *doubleLinkListSearch(DoubleLinkList *list, int data) {
    DoubleLinkListNode *node = list->head;
    while (node != NULL) {
        if (node->data == data) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void doubleLinkListDump(DoubleLinkList *list) {
    int count = 0;
    printf("打印链表\n");
    DoubleLinkListNode *node = list->head;
    while (node != NULL) {
        printf("[%d] = %d\n",count++, node->data);
        node = node->next;
    }
}

/*
 我们维护一个有序循环链表，越靠近链表尾部的结点是越早之前访问的。当有一个新的数据被访问时，我们从链表头开始顺序遍历链表。
 如果此数据之前已经被缓存在链表中了，我们遍历得到这个数数据对应的结点，并将其从原来的位置删除，然后再插入到链表的头部。
 如果此数据没有在缓存链表中，又可以分为两种情况：
 如果此时缓存未满，则将此结点直接插入到链表的头部；
 如果此时缓存已满，则链表尾结点删除，将新的数据结点插入链表的头部。
 */

void doubleLinkListLRU(DoubleLinkList *list, int data) {
    DoubleLinkListNode *node = doubleLinkListSearch(list, data);
    if (node != NULL) {
        doubleLinkListRemoveNode(list, node);
    }
    else if (list->size >= 4) {
        node = doubleLinkListRemoveTail(list);
    }
    
    doubleLinkListInsertHead(list, node, data);
}

void doubleLinkListTest() {
    DoubleLinkList list = {0};
    DoubleLinkListNode *node = NULL;
    
    doubleLinkListCreate(&list);
    
    printf("插入 1 2 3\n");
    doubleLinkListInsertHead(&list, NULL, 1);
    doubleLinkListInsertHead(&list, NULL, 2);
    doubleLinkListInsertHead(&list, NULL, 3);
    
    doubleLinkListDump(&list);
    
    node = doubleLinkListRemoveTail(&list);
    if (node != NULL) {
        printf("删除 %d\n",node->data);
    }
    doubleLinkListInsertHead(&list, node, 4);
    
    doubleLinkListDump(&list);
    
    doubleLinkListLRU(&list, 5);
    doubleLinkListDump(&list);
    
    doubleLinkListLRU(&list, 6);
    doubleLinkListDump(&list);
    
    doubleLinkListLRU(&list, 7);
    doubleLinkListDump(&list);
    
    doubleLinkListLRU(&list, 5);
    doubleLinkListDump(&list);
    
    while (list.size > 0) {
        node = doubleLinkListRemoveTail(&list);
        if (node != NULL) {
            printf("删除 %d\n", node->data);
            free(node);
        }
    }
}
