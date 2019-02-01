//
//  leetCode-0235.cpp
//  leetCode-c
//
//  Created by liyoucheng on 2019/1/23.
//  Copyright © 2019年 Giga. All rights reserved.
//

#include "leetCode-0235.hpp"

#include <iostream>
//#include <queue>
//#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//
//        if (!root) {
//
//            return root;
//        }
//
//        if (root->val > max(p->val, q->val)) {
//
//            return lowestCommonAncestor(root->left, p, q);
//        }
//        else if (root->val < min(p->val, q->val)) {
//
//            return lowestCommonAncestor(root->right, p, q);
//        }
//        else {
//
//            return root;
//        }
//    }
//};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        while (true) {
            
            if (root->val > max(p->val, q->val)) {
                
                root = root->left;
            }
            else if (root->val < min(p->val, q->val)) {
                
                root = root->right;
            }
            else {
                
                return root;
            }
        }
    }
};
