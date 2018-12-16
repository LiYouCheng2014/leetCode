//
//  LYCHeap.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/11.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "LYCHeap.h"

#include <stdlib.h>
#include <stdbool.h>

int *arr; //数组，从下标1开始存储数据
int n; //堆可以存储的最大数据个数
int count; //堆中已经存储的数据个数

void heap(int capacity) {
    arr = (int *)sizeof(sizeof(int) * (capacity + 1));
    n = capacity;
    count = 0;
}

void lyc_insert(int data) {
    if (count >= n) {
        //堆满
        return;
    }
    
    ++count;
    arr[count] = data;
    int i = count;
    // 从下往上堆化
    while (i / 2 > 0 && arr[i] > arr[i / 2]) {
        int temp = arr[i];
        arr[i] = arr[i / 2];
        arr[i / 2] = temp;
        
        i /= 2;
    }
}

void lyc_heapify(int *a, int n, int i) {
    //自上往下堆化
    while (true) {
        int maxPos = i;
        if (i * 2 <= n && arr[i] < arr[i * 2]) {
            maxPos = i * 2;
        }
        
        if (i * 2 + 1 <= n && arr[maxPos] < arr[i * 2 + 1]) {
            maxPos = i * 2 + 1;
        }
        
        if (maxPos == i) {
            break;
        }
        
        int temp = arr[i];
        arr[i] = arr[maxPos];
        arr[maxPos] = temp;
        
        i = maxPos;
    }
}

void lyc_removeMax() {
    if (count == 0) {
        // 堆中没有数据
        return;
    }
    
    arr[1] = arr[count];
    --count;
    lyc_heapify(arr, count, 1);
}

void lyc_buildHeap(int *arr, int n) {
    for (int i = n / 2; i >= 1; i--) {
        lyc_heapify(arr, n, i);
    }
}

void lyc_heapSort(int *arr, int n) {
    lyc_buildHeap(arr, n);
    int k = n;
    while (k > 1) {
        int temp = arr[1];
        arr[1] = arr[k];
        arr[k] = temp;
        
        k--;
        lyc_heapify(arr, k, 1);
    }
}

