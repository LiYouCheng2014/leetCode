//
//  leetCode-0122.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/16.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0122.h"

int maxProfit(int* prices, int pricesSize) {
    int ret = 0;
    for (int i = 0; i < pricesSize - 1; i++) {
        if (prices[i] < prices[i + 1]) {
            ret += (prices[i + 1] - prices[i]);
        }
    }
    return ret;
}

void test_0122(void)
{
    //    int arr[6] = { 7,1,5,3,6,4 };
    //    int arr[5] = { 1,2,3,4,5 };
    int arr[5] = { 7,6,4,3,1 };
    int max = maxProfit(arr, sizeof(arr)/sizeof(arr[0]));
    printf("max = %d\n",max);
}
