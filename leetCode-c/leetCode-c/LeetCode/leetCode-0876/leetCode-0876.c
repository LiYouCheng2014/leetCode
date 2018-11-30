//
//  leetCode-0876.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/11/28.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0876.h"

#include <stdlib.h>

#include "LYCLinkList.h"

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow;
}

void test_0876(void)
{
    int arr[5] = { 5, 4, 3, 2, 1 };
    struct ListNode *l1 = linkListCreateHead(arr, sizeof(arr) / sizeof(arr[0]));
    printNode(l1);
    
    struct ListNode *ret1 = middleNode(l1);
    printNode(ret1);
    
    int arr2[6] = { 6, 5, 4, 3, 2, 1 };
    struct ListNode *l2 = linkListCreateHead(arr2, sizeof(arr2) / sizeof(arr2[0]));
    printNode(l2);
    
    struct ListNode *ret2 = middleNode(l2);
    printNode(ret2);
}
