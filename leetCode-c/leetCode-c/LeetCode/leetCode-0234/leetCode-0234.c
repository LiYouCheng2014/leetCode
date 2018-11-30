//
//  leetCode-0234.c
//  leetCode-0234
//
//  Created by liyoucheng on 2018/10/23.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

#include "leetCode-0234.h"

/*
 我们使用快慢指针找中点的原理是fast和slow两个指针，每次快指针走两步，慢指针走一步，同时前置慢指针部分,等快指针走完时，慢指针的位置就是中点。同时比较slow和prev的值
 */

#include <stdlib.h>
#include <stdbool.h>

#include "LYCLinkList.h"

bool isPalindrome1(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    struct ListNode *prev = NULL;
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        
        //前置前部分
        struct ListNode *temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }
    
    //奇数时判断
    if (fast != NULL) {
        slow = slow->next;
    }
    
    while (slow != NULL) {
        if (prev->val != slow->val) {
            return false;
        }
        prev = prev->next;
        slow = slow->next;
    }
    
    return true;
}

/**
 回文链表
 */
void test_0234(void)
{
    int arr[4] = { 1, 2, 2, 1 };
//    int arr[2] = { 1, 2 };
    struct ListNode *head = linkListCreateHead(arr, sizeof(arr) / sizeof(arr[0]));
    
    printNode(head);

    bool flag = isPalindrome1(head);
    printf("是否回文:1回文，0非回文 => %d\n",flag);
}
