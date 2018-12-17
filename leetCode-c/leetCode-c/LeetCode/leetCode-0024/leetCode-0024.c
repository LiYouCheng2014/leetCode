//
//  leetCode-0024.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/16.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0024.h"

#include <stdlib.h>

#include "LYCLinkList.h"

/**
 两两交换链表中的节点 1->2->3->4
 
 @param head 不带头结点
 @return 交换之后的链表 2->1->4->3
 */
struct ListNode *swapPairs(struct ListNode *head)
{
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *prev = dummy;
    prev->next = head;
    
    while (prev->next != NULL && prev->next->next != NULL) {
        
        struct ListNode *a = prev->next;
        struct ListNode *b = prev->next->next;
        
        struct ListNode *temp = b->next;
        prev->next = b;
        b->next = a;
        a->next = temp;
        prev = a;
    }
    
    return dummy->next;
}

/**
 两两交换链表中的节点测试
 */
void test_0024(void)
{
    int arr[4] = { 1, 2, 3, 4 };
    struct ListNode *head = linkListCreateHead(arr, sizeof(arr) / sizeof(arr[0]));

    printf("========两两交换链表中的节点测试========\n");
    
    printNode(head);
    struct ListNode *new = swapPairs(head->next);
    printNode(new);
}
