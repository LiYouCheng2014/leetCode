//
//  leetCode-0242.cpp
//  leetCode-c
//
//  Created by liyoucheng on 2019/1/20.
//  Copyright © 2019年 Giga. All rights reserved.
//

#include "leetCode-0242.hpp"

#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.size() != t.size()) {
            
            return false;
        }
        
        int count[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            
            ++count[s[i] - 'a'];
        }
        
        for (int i = 0; i < t.size(); ++i) {
            
            if (--count[t[i] - 'a'] < 0) {
                
                return false;
            }
        }
        
        return true;
    }
};
