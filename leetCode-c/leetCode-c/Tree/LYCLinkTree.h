//
//  LYCLinkTree.h
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/8.
//  Copyright © 2018年 Giga. All rights reserved.
//

#ifndef LYCLinkTree_h
#define LYCLinkTree_h

#include <stdio.h>

typedef char LinkTreeData;

typedef struct link_btree_node {
    LinkTreeData data;
    struct link_btree_node *left;
    struct link_btree_node *right;
}LinkBTreeNode, *BTree;

void testLinkTree(void);

#endif /* LYCLinkTree_h */
