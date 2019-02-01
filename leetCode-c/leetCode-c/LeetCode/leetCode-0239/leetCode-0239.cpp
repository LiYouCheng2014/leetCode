//
//  leetCode-0239.cpp
//  leetCode-c
//
//  Created by liyoucheng on 2019/1/19.
//  Copyright © 2019年 Giga. All rights reserved.
//

#include "leetCode-0239.hpp"

#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // 存放结果
        vector<int> res;
        // 双向队列 存放下标
        deque<int> q;
        
        for (int i = 0; i < nums.size(); ++i) {
            
            // 如果队列的首元素是i-k的话，窗口向右移了一步，移除队首元素
            if (!q.empty() && q.front() == i - k) {
                
                q.pop_front();
            }
            
            // 比较队尾元素和将要进来的值，如果小的话就都移除
            while (!q.empty() && nums[q.back()] < nums[i]) {
                
                q.pop_back();
            }
            
            // 新元素入队
            q.push_back(i);
            
            if (i >= k - 1) {
                
                // 将队首元素加入结果
                res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};
