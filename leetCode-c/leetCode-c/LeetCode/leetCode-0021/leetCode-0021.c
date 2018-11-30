//
//  leetCode-0021.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/11/28.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0021.h"

#include <stdlib.h>

#include "LYCLinkList.h"

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    
    if (l2 == NULL) {
        return l1;
    }
    
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = NULL;
    
    struct ListNode *p = head;
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        }
        else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    
    if (l1 != NULL) {
        p->next = l1;
    }
    
    if (l2 != NULL) {
        p->next = l2;
    }
    
    p = head->next;
    free(head);
    
    return p;
}

void test_0021(void) {
    int arr1[3] ={ 4, 2, 1 };
    int arr2[3] ={ 4, 3, 1 };
    struct ListNode *l1 = linkListCreateHead(arr1, sizeof(arr1) / sizeof(arr1[0]));
    struct ListNode *l2 = linkListCreateHead(arr2, sizeof(arr2) / sizeof(arr2[0]));
    printNode(l1);
    printNode(l2);
    
    struct ListNode *ret = mergeTwoLists(l1, l2);
    printNode(ret);
}
