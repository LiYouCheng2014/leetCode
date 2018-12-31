//
//  leetCode-0237.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/31.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0237.h"

#include <stdlib.h>

#include "LYCLinkList.h"

void deleteNode(struct ListNode* node) {
    
    node->val = node->next->val;
    struct ListNode *temp = node->next;
    node->next = temp->next;
    
    free(temp);
}

void test_0237(void) {
    
    int arr[4] = { 4, 5, 1, 9 };
    struct ListNode *l1 = linkListCreateHead(arr, sizeof(arr) / sizeof(arr[0]));
    printNode(l1);
    
    deleteNode(l1);
    
    printNode(l1);
}
