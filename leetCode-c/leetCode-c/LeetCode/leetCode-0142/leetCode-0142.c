//
//  leetCode-0142.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/11/28.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0142.h"

#include <stdlib.h>

#include "LYCLinkList.h"

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    
    while (slow != NULL && fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        
        if (slow == fast) {
            fast = head;
            while (fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
    }
    
    return NULL;
}

/**
 创建环
 
 @return 环
 */
struct ListNode *create_cycle_list1()
{
    struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node1->val = 1;
    
    struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node2->val = 2;
    
    struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node3->val = 3;
    
    struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node4->val = 4;
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;
    
    return node1;
}

void test_0142(void)
{
    struct ListNode *l1 = create_cycle_list1();
    
    struct ListNode *ret =detectCycle(l1);
    
    printf("入环的第一个节点值：%d\n",ret->val);
}
