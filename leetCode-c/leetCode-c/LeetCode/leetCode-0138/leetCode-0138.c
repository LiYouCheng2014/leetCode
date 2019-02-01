//
//  leetCode-0138.c
//  leetCode-c
//
//  Created by liyoucheng on 2019/1/12.
//  Copyright © 2019年 Giga. All rights reserved.
//

#include "leetCode-0138.h"

#include <stdlib.h>

struct RandomListNode {
    int label;
    struct RandomListNode *next;
    struct RandomListNode *random;
};

struct RandomListNode *copyRandomList(struct RandomListNode *head) {

    if (head == NULL) {
        
        return NULL;
    }
    
    struct RandomListNode *cur = head;
    // 在原链表的每个节点后面拷贝出一个新的节点
    while (cur) {
        
        struct RandomListNode *next = cur->next;
        struct RandomListNode *copy = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
        copy->label = cur->label;
        cur->next = copy;
        copy->next = next;
        
        cur = next;
    }
    
    cur = head;
    // 依次给新的节点随机指针赋值
    while (cur) {
        
        struct RandomListNode *copy = cur->next;
        if (cur->random) {
            
            copy->random = cur->random->next;
        }
        else {
            
            copy->random = NULL;
        }
        
        cur = copy->next;
    }
    
    // 断开链表可得到深度拷贝后的链表
    struct RandomListNode *tail = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
    struct RandomListNode *copyHead = tail;
    cur = head;
    while (cur) {
        
        struct RandomListNode *copy = cur->next;
        struct RandomListNode *next = copy->next;
        
        tail->next = copy;
        tail = copy;
        
        cur->next = next;
        cur = next;
    }
    
    struct RandomListNode *newNode = copyHead->next;
    free(copyHead);
    
    return newNode;
}

void test_0138(void) {
    
    
}
