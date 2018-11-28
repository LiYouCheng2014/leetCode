//
//  leetCode-0019.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/11/28.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0019.h"

#include <stdlib.h>

#include "LinkList.h"

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    
    struct ListNode *fast = dummy;
    struct ListNode *slow = dummy;
    
    for (int i = 1; i <= n + 1; i++) {
        fast = fast->next;
    }
    
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    struct ListNode *p = slow->next;
    slow->next = p->next;
    free(p);
    
    return dummy->next;
}

void test_0019(void) {
    int arr1[5] ={ 5, 4, 3, 2, 1 };
    struct ListNode *l1 = createNode(arr1, sizeof(arr1) / sizeof(arr1[0]));
    int n = 2;
    
    printNode(l1);
    
    struct ListNode *ret = removeNthFromEnd(l1, n);
    printNode(ret);
}
