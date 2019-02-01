//
//  leetCode-0025.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/16.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0025.h"

#include <stdlib.h>
#include <stdbool.h>

#include "LYCLinkList.h"

/**
 反转链表 1->2-3->4
 
 @param head 不带头结点
 @return 反转后的链表 4->3->2->1
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *cur = head;
    struct ListNode *prev = NULL;
    while(cur) {
        struct ListNode *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}

/**
 k个一组翻转链表 1->2->3->4->5
 
 @param head 不带头结点
 @param k 几个节点 2
 @return 翻转后的链表 2->1->4->3->5
 */
struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
    struct ListNode *root = NULL;
    struct ListNode *p = NULL;
    
    while (head != NULL) {
        struct  ListNode *tempHead = head;
        struct ListNode *tempP = NULL;
        
        int count = 0;
        bool isReverse = true;
        
        while (count < k) {
            if (head == NULL) {
                isReverse = false;
                break;
            }
            
            tempP = head;
            head = head->next;
            count++;
        }
        tempP->next = NULL;
        
        if (isReverse) {
            if (root == NULL) {
                root = reverseList(tempHead);
                p = tempHead;
            }
            else {
                p->next = reverseList(tempHead);
                p = tempHead;
            }
        }
        else {
            if (root == NULL) {
                
                root = tempHead;
            }
            else {
                
                p->next = tempHead;
            }
        }
    }
    
    return root;
}

/**
 k个一组翻转链表测试
 */
void test_0025(void)
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    struct ListNode *head = linkListCreateHead(arr, sizeof(arr) / sizeof(arr[0]));
    

    printf("========k个一组翻转链表测试========\n");
    printNode(head);
    struct ListNode *new = reverseKGroup(head->next, 2);
    printNode(new);
}
