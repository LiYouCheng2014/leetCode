//
//  leetCode-0001.cpp
//  leetCode-c
//
//  Created by liyoucheng on 2019/1/20.
//  Copyright © 2019年 Giga. All rights reserved.
//

#include "leetCode-0001.hpp"

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> m;
        vector<int> res;
        
        // 使用一个HashMap，来建立数字和其坐标位置之间的映射
        for (int i = 0; i < nums.size(); ++i) {
            
            m[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            
            // 用target减去遍历到的数字，就是另一个需要的数字了
            int t = target - nums[i];
            // 在HashMap中查找其是否存在
            if (m.count(t) && m[t] != i) {
                
                res.push_back(i);
                res.push_back(m[t]);
                break;
            }
        }
        
        return res;
    }
};
