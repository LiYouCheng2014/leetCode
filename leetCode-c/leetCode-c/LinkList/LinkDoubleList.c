//
//  LinkDoubleList.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/11/27.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "LinkDoubleList.h"

#include <stdlib.h>
#include <string.h>

#include "List.h"

/**
 创建双向链表
 
 @param list 双向链表
 */
void double_link_list_create(DoubleLinkListHead *list)
{
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}

/**
 销毁双向链表
 
 @param list 双向链表
 */
void double_link_list_destory(DoubleLinkListHead *list)
{
    DoubleLinkListNode *temp = NULL;
    while (list->size > 0) {
        temp = list->head;
        list->head = temp->next;
        free(temp);
        list->size--;
    }
    
    memset(list, 0, sizeof(DoubleLinkListHead));
}


/**
 头部插入
 
 @param list 双向链表
 @param node 需插入的节点
 @param data 需插入的数据
 @return 是否插入成功
 */
int double_link_list_insert_head(DoubleLinkListHead *list, DoubleLinkListNode *node, int data)
{
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

/**
 移除尾部节点
 
 @param list 双向链表
 @return 移除的尾部节点
 */
DoubleLinkListNode *double_link_list_remove_tail(DoubleLinkListHead *list)
{
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

/**
 移除节点
 
 @param list 双向链表
 @param node 移除的节点
 */
void double_link_list_remove_node(DoubleLinkListHead *list, DoubleLinkListNode *node)
{
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
        memset(list, 0, sizeof(DoubleLinkListHead));
    }
}

/**
 查找节点
 
 @param list 双向链表
 @param data 查找的数据
 @return 查找到的节点
 */
DoubleLinkListNode *double_link_list_search(DoubleLinkListHead *list, int data)
{
    DoubleLinkListNode *node = list->head;
    while (node != NULL) {
        if (node->data == data) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

/**
 遍历双向链表
 
 @param list 双向链表
 */
void double_link_list_dump(DoubleLinkListHead *list)
{
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

/**
 LRU缓存淘汰算法
 
 @param list 双向链表
 @param data 数据
 */
void LRU_list(DoubleLinkListHead *list, int data)
{
    DoubleLinkListNode *node = double_link_list_search(list, data);
    if (node != NULL) {
        double_link_list_remove_node(list, node);
    }
    else if (list->size >= 4) {
        node = double_link_list_remove_tail(list);
    }
    
    double_link_list_insert_head(list, node, data);
}

/**
 LRU缓存淘汰算法测试
 */
void LRU_list_test()
{
    DoubleLinkListHead list = {0};
    DoubleLinkListNode *node = NULL;
    
    double_link_list_create(&list);
    
    printf("插入 1 2 3\n");
    double_link_list_insert_head(&list, NULL, 1);
    double_link_list_insert_head(&list, NULL, 2);
    double_link_list_insert_head(&list, NULL, 3);
    
    double_link_list_dump(&list);
    
    node = double_link_list_remove_tail(&list);
    if (node != NULL) {
        printf("删除 %d\n",node->data);
    }
    double_link_list_insert_head(&list, node, 4);
    
    double_link_list_dump(&list);
    
    LRU_list(&list, 5);
    double_link_list_dump(&list);
    
    LRU_list(&list, 6);
    double_link_list_dump(&list);
    
    LRU_list(&list, 7);
    double_link_list_dump(&list);
    
    LRU_list(&list, 5);
    double_link_list_dump(&list);
    
    while (list.size > 0) {
        node = double_link_list_remove_tail(&list);
        if (node != NULL) {
            printf("删除 %d\n", node->data);
            free(node);
        }
    }
}

