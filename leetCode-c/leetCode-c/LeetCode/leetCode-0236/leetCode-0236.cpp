//
//  leetCode-0236.cpp
//  leetCode-c
//
//  Created by liyoucheng on 2019/1/23.
//  Copyright © 2019年 Giga. All rights reserved.
//

#include "leetCode-0236.hpp"

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
//        if (!root || p == root || q == root) {
//
//            return root;
//        }
//
//        TreeNode *left = lowestCommonAncestor(root->left, p, q);
//        TreeNode *right = lowestCommonAncestor(root->right, p, q);
//
//        if (left && right) {
//
//            return root;
//        }
//
//        if (left) {
//
//            return left;
//        }
//        else {
//
//            return right;
//        }
//    }
//};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (!root || p == root || q == root) {
            
            return root;
        }
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        if (left && left != p && left != q) {
            
            return left;
        }
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        if (left && right) {
            
            return root;
        }
        
        if (left) {
            
            return left;
        }
        else {
            
            return right;
        }
    }
};
