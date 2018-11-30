//
//  leetCode-0141.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/11/28.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0141.h"

#include <stdlib.h>
#include <stdbool.h>

#include "LYCLinkList.h"

bool hasCycle(struct ListNode *head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (slow != NULL && fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        
        if (fast == slow) {
            return true;
        }
    }
    
    return false;
}

/**
 创建环
 
 @return 环
 */
struct ListNode *create_cycle_list()
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

void test_0141(void)
{
    int arr[4] = { 1, 2, 3, 4 };
    struct ListNode *l1 = linkListCreateHead(arr, sizeof(arr) / sizeof(arr[0]));
    
    struct ListNode *l2 = create_cycle_list();
    
    printf("========环形链表测试========\n");
    bool isCycle = hasCycle(l1);
    printf("是否存在环:1是，0不是=>%d\n",isCycle);
    
    bool isCycle1 = hasCycle(l2);
    printf("是否存在环:1是，0不是=>%d\n",isCycle1);
}


