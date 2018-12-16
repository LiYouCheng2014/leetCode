//
//  LYCLinkTree.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/8.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "LYCLinkTree.h"

#include <stdlib.h>
#include <stdbool.h>

#pragma mark - 队

typedef BTree TreeLinkQueueData;

//节点
typedef struct tree_link_queue_node {
    TreeLinkQueueData data;
    struct tree_link_queue_node *next;
}TreeLinkQueueNode;

typedef struct tree_link_queue {
    TreeLinkQueueNode *head;//队头
    TreeLinkQueueNode *tail;//队尾
    int count;//队大小
}TreeLinkQueue;

TreeLinkQueue *treeLinkQueueCreate() {
    TreeLinkQueue *queue = NULL;
    
    queue = (TreeLinkQueue *)malloc(sizeof(TreeLinkQueue));
    if (queue == NULL) {
        return NULL;
    }
    
    queue->head = NULL;
    queue->tail = NULL;
    queue->count = 0;
    
    return queue;
}

bool treeLinkQueueIsEmpty(TreeLinkQueue *queue) {
    return queue->count == 0;
}

int treeLinkQueueEnqueue(TreeLinkQueue *queue, TreeLinkQueueData data) {
    if (queue == NULL) {
        return -1;
    }
    
    TreeLinkQueueNode *p = NULL;
    
    p = (TreeLinkQueueNode *)malloc(sizeof(TreeLinkQueueNode));
    if (p == NULL) {
        return -1;
    }
    
    p->data = data;
    p->next = NULL;
    if (queue->head == NULL) {
        queue->head = p;
    }
    else {
        queue->tail->next = p;
    }
    queue->tail = p;
    queue->count++;
    
    return 0;
}

int treeLinkQueueDequeue(TreeLinkQueue *queue, TreeLinkQueueData *data) {
    if (queue == NULL || treeLinkQueueIsEmpty(queue)) {
        return -1;
    }
    
    *data = queue->head->data;
    
    TreeLinkQueueNode *p = queue->head;
    p = queue->head;
    queue->head = queue->head->next;
    queue->count--;
    
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    
    free(p);
    
    return 0;
}

#pragma mark - 栈

typedef BTree TreeLinkStackData;

//节点
typedef struct tree_link_stack_node {
    TreeLinkStackData data;
    struct tree_link_stack_node *next;
}TreeLinkStackNode;

typedef struct tree_link_stack {
    TreeLinkStackNode *top;//栈顶
    int count;//栈大小
}TreeLinkStack;

TreeLinkStack *treeLinkStackCreate() {
    TreeLinkStack *stack = NULL;
    
    stack = (TreeLinkStack *)malloc(sizeof(TreeLinkStack));
    if (stack == NULL) {
        return NULL;
    }
    
    stack->top = NULL;
    stack->count = 0;
    
    return stack;
}

bool treeLinkStackIsEmpty(TreeLinkStack *stack) {
    return stack->count == 0;
}


int treeLinkStackPush(TreeLinkStack *stack, TreeLinkStackData data) {
    TreeLinkStackNode *p = NULL;
    
    p = (TreeLinkStackNode *)malloc(sizeof(TreeLinkStackNode));
    if (p == NULL) {
        return -1;
    }
    
    p->data = data;
    p->next = stack->top;
    stack->top = p;
    stack->count++;
    
    return 0;
}

int treeLinkStackTop(TreeLinkStack *stack, TreeLinkStackData *data) {
    if (treeLinkStackIsEmpty(stack)) {
        return -1;
    }
    
    TreeLinkStackNode *p = stack->top;
    *data = p->data;
    
    return 0;
}

int treeLinkStackPop(TreeLinkStack *stack, TreeLinkStackData *data) {
    if (treeLinkStackIsEmpty(stack)) {
        return -1;
    }
    
    TreeLinkStackNode *p = stack->top;
    *data = p->data;
    stack->top = p->next;
    stack->count--;
    
    free(p);
    
    return 0;
}

#pragma mark - 树

//根左右
BTree createTree() {
    
    BTree tree;
    char str = getchar();
    if (str == '#') {
        tree = NULL;
    }
    else {
        tree = (BTree)malloc(sizeof(struct link_btree_node));
        tree->data = str;
        tree->left = createTree();
        tree->right = createTree();
    }
    
    return tree;
}

#pragma mark - 递归遍历

//先序 根左右
void linkTreePreTraversal(BTree root) {
    if (root == NULL) {
        return;
    }
    
    printf("%c->",root->data);
    linkTreePreTraversal(root->left);
    linkTreePreTraversal(root->right);
}

//中序 左根右
void linkTreeInTraversal(BTree root) {
    if (root == NULL) {
        return;
    }
    
    linkTreeInTraversal(root->left);
    printf("%c->",root->data);
    linkTreeInTraversal(root->right);
}

//后序 左右根
void linkTreePostTraversal(BTree root) {
    if (root == NULL) {
        return;
    }
    
    linkTreePostTraversal(root->left);
    linkTreePostTraversal(root->right);
    printf("%c->",root->data);
}

#pragma mark - 迭代遍历

//先序
void linkTreePreTraversalIter(BTree root) {
    BTree tree = root;
    TreeLinkStack *stack = treeLinkStackCreate();
    while (tree || !treeLinkStackIsEmpty(stack)) {
        //一直向左并将沿途经点入栈
        if (tree) {
            printf("%c->", tree->data);
            treeLinkStackPush(stack, tree);
            tree = tree->left;
        }
        else {
            treeLinkStackPop(stack, &tree);
            //转向右子树
            tree = tree->right;
        }
    }
}

//中序
void linkTreeInTraversalIter(BTree root) {
    BTree tree = root;
    TreeLinkStack *stack = treeLinkStackCreate();
    while (tree || !treeLinkStackIsEmpty(stack)) {
        //一直向左并将沿途经点入栈
        if (tree) {
            treeLinkStackPush(stack, tree);
            tree = tree->left;
        }
        else {
            treeLinkStackPop(stack, &tree);
            printf("%c->", tree->data);
            //转向右子树
            tree = tree->right;
        }
    }
}

//后序
void linkTreePostTraversalIter(BTree root) {
    BTree tree = root;
    TreeLinkStack *stack1 = treeLinkStackCreate();
    TreeLinkStack *stack2 = treeLinkStackCreate();
    while (tree || !treeLinkStackIsEmpty(stack2)) {
        //一直向右并将沿途经点入栈
        if (tree) {
            treeLinkStackPush(stack1, tree);
            treeLinkStackPush(stack2, tree);
            tree = tree->right;
        }
        else {
            treeLinkStackPop(stack2, &tree);
            //转向左子树
            tree = tree->left;
        }
    }
    
    while (!treeLinkStackIsEmpty(stack1)) {
        treeLinkStackPop(stack1, &tree);
        printf("%c->", tree->data);
    }
}

#pragma mark - 其它

// 层次遍历
void linkTreeLevelTraversal(BTree root) {
    if (root) {
        TreeLinkQueue *queue = treeLinkQueueCreate();
        
        BTree tree = root;
        treeLinkQueueEnqueue(queue, tree);
        
        while (!treeLinkQueueIsEmpty(queue)) {
            treeLinkQueueDequeue(queue, &tree);
            printf("%c->",tree->data);
            
            if (tree->left) {
                treeLinkQueueEnqueue(queue, tree->left);
            }
            if (tree->right) {
                treeLinkQueueEnqueue(queue, tree->right);
            }
        }
    }
}

// 树深度
int linkTreeHeight(BTree root) {
    int leftHeight;
    int rightHeight;
    if (root == NULL) {
        return 0;
    }
    else {
        leftHeight = linkTreeHeight(root->left);
        rightHeight = linkTreeHeight(root->right);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

// 每层结点的个数
void linkTreeLevelCount(BTree root, int level, int *nums) {
    if (root) {
        nums[level]++;
        linkTreeLevelCount(root->left, level + 1, nums);
        linkTreeLevelCount(root->right, level + 1, nums);
    }
}

// 结点总数
int linkTreeCount(BTree root) {
    int leftCount;
    int rightCount;
    if (root == NULL) {
        return 0;
    }
    
    leftCount = linkTreeCount(root->left);
    rightCount = linkTreeCount(root->right);
    return leftCount + rightCount + 1;
}

void testLinkTree(void) {
    //ABD##E##CF##G##
    BTree root = createTree();
    
    printf("递归先序：");
    linkTreePreTraversal(root);
    printf("\n");
    
    printf("递归先序：");
    linkTreeInTraversal(root);
    printf("\n");
    
    printf("递归先序：");
    linkTreePostTraversal(root);
    printf("\n");
    
    printf("迭代先序：");
    linkTreePreTraversalIter(root);
    printf("\n");
    
    printf("迭代中序：");
    linkTreeInTraversalIter(root);
    printf("\n");
    
    printf("迭代后序：");
    linkTreePostTraversalIter(root);
    printf("\n");
    
    printf("层次遍历：");
    linkTreeLevelTraversal(root);
    printf("\n");
    
    int treeHeight = linkTreeHeight(root);
    printf("树深度: %d\n", treeHeight);
    
    int level = 1;
    int *ret = (int *)malloc(sizeof(int) * (treeHeight + 1));
    for (int i = 0; i < treeHeight + 1; i++) {
        ret[i] = 0;
    }
    linkTreeLevelCount(root, level, ret);
    for (int i = 1; i <= treeHeight; i++) {
        printf("第%d层数目:%d\n",i, ret[i]);
    }
    
    int count = linkTreeCount(root);
    printf("树总结结点数:%d\n",count);
    
    
}

