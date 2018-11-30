//
//  leetCode-0206.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/11/28.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0206.h"

#include <stdlib.h>

#include "LYCLinkList.h"

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *p = head;
    struct ListNode *prev = NULL;
    
    while (p != NULL) {
        struct ListNode *temp = p->next;
        p->next = prev;
        prev = p;
        p = temp;
    }
    
    return prev;
}

void test_0206(void)
{
    int arr[5] = { 5, 4, 3, 2, 1 };
    struct ListNode *l1 = linkListCreateHead(arr, sizeof(arr) / sizeof(arr[0]));
    printNode(l1);
    
    struct ListNode *ret = reverseList(l1);
    printNode(ret);
}
