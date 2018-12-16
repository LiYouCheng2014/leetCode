//
//  leetCode-0102.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/15.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0102.h"

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct link_queue_node102 {
    struct TreeNode *data;
    struct link_queue_node102 *next;
};

struct link_queue102 {
    int count;
    struct link_queue_node102 *head;
    struct link_queue_node102 *tail;
};

struct link_queue102 *link_queue_create102() {
    struct link_queue102 *queue = (struct link_queue102 *)malloc(sizeof(struct link_queue102));
    queue->count = 0;
    queue->head = NULL;
    queue->tail = NULL;
    
    return queue;
}

int link_queue_enqueue102(struct link_queue102 *queue, struct TreeNode *data) {
    struct link_queue_node102 *node = (struct link_queue_node102 *)malloc(sizeof(struct link_queue_node102));
    node->data = data;
    node->next = NULL;
    
    if (queue->head == NULL) {
        queue->head = node;
    }
    else {
        queue->tail->next = node;
    }
    queue->tail = node;
    queue->count += 1;
    
    return 0;
}

bool link_queue_is_empty102(struct link_queue102 * queue) {
    return queue->count == 0;
}

int link_queue_dequeue102(struct link_queue102 *queue, struct TreeNode **data) {
    
    if ((queue == NULL) || link_queue_is_empty102(queue)) {
        return 1;
    }
    
    *data = queue->head->data;
    
    struct link_queue_node102 *node = queue->head;
    queue->head = queue->head->next;
    queue->count -= 1;
    
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    
    free(node);
    
    return 0;
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    int **results = (int **)malloc(sizeof(int *) * 1000);
    *columnSizes = (int *)malloc(sizeof(int) * 1000);
    *returnSize = 0;
    
    memset(*columnSizes, 0, sizeof(int) * 1000);
    
    struct link_queue102 *queue = link_queue_create102();
    link_queue_enqueue102(queue, root);
    
    int *nums = (int *)malloc(sizeof(int) * 1000);
    while (!link_queue_is_empty102(queue)) {
        int len = queue->count;
        int *temp = (int *)malloc(sizeof(int) * len);
        for (int i = 0; i < len; i++) {
            
            struct TreeNode *treeNode = NULL;
            link_queue_dequeue102(queue, &treeNode);
            
            temp[i] = treeNode->val;
            
            if (treeNode->left) {
                link_queue_enqueue102(queue, treeNode->left);
            }
            
            if (treeNode->right) {
                link_queue_enqueue102(queue, treeNode->right);
            }
        }
        nums[*returnSize] = len;
        results[*returnSize] = temp;
        
        *returnSize += 1;
    }
    
    *columnSizes = nums;
    
    return results;
}

void prePrintNode(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }
    
    printf("%d ",root->val);
    prePrintNode(root->left);
    prePrintNode(root->right);
}

void test_0102(void) {
    struct TreeNode *node3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node3->val = 3;
    node3->left = NULL;
    node3->right = NULL;
    
    struct TreeNode *node9 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node9->val = 9;
    node9->left = NULL;
    node9->right = NULL;
    
    struct TreeNode *node20 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node20->val = 20;
    node20->left = NULL;
    node20->right = NULL;
    
    struct TreeNode *node15 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node15->val = 15;
    node15->left = NULL;
    node15->right = NULL;
    
    struct TreeNode *node7 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node7->val = 7;
    node7->left = NULL;
    node7->right = NULL;
    
    node3->left = node9;
    node3->right = node20;
    node20->left = node15;
    node20->right = node7;
    
//    prePrintNode(node3);
    
    int *column = NULL;
    int size = 0;
    int **ret = levelOrder(node3, &column, &size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < column[i]; j++) {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }
}

