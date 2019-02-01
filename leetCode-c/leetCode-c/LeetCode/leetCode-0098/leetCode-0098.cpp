//
//  leetCode-0098.cpp
//  leetCode-c
//
//  Created by liyoucheng on 2019/1/21.
//  Copyright © 2019年 Giga. All rights reserved.
//

#include "leetCode-0098.hpp"


#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//    bool isValidBST(TreeNode* root) {
//
//        // 初始化时带入系统最大值和最小值
//        return isValidBST(root, LONG_MIN, LONG_MAX);
//    }
//
//    bool isValidBST(TreeNode *root, long min, long max) {
//
//        if (!root) {
//
//            return true;
//        }
//
//        if (root->val <= min || root->val >= max) {
//
//            return false;
//        }
//
//        // 在递归过程中换成它们自己的节点值
//        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
//    }
//};


//class Solution {
//public:
//    bool isValidBST(TreeNode* root) {
//
//        if (!root) {
//
//            return true;
//        }
//
//        vector<int> vals;
//        inorder(root, vals);
//
//        for (int i = 0; i < vals.size() - 1; ++i) {
//
//            if (vals[i] >= vals[i + 1]) {
//
//                return false;
//            }
//        }
//
//        return true;
//    }
//
//    void inorder(TreeNode *root, vector<int>& vals) {
//
//        if (!root) {
//
//            return;
//        }
//
//        inorder(root->left, vals);
//        vals.push_back(root->val);
//        inorder(root->right, vals);
//    }
//};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        TreeNode *pre = NULL;
        return inorder(root, pre);
    }
    
    bool inorder(TreeNode *node, TreeNode*& pre) {
        
        if (!node) {
            
            return true;
        }
        
        bool res = inorder(node->left, pre);
        if (!res) {
            
            return false;
        }
        
        if (pre) {
            
            if (node->val <= pre->val) {
                
                return false;
            }
        }
        
        pre = node;
        
        return inorder(node->right, pre);
    }
};
