//
//  LYCSearch.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/7.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "LYCSearch.h"

//变体一：查找第一个值等于给定值的元素
int bsearch_bt1(int *arr, int size, int key) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + ((high -low) >> 1);
        if (arr[mid] > key) {
            high = mid - 1;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            if ((mid == 0) || (arr[mid - 1] != key)) {
                return mid;
            }
            else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

//变体二：查找最后一个值等于给定值的元素
int bsearch_bt2(int *arr, int size, int key) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + ((high -low) >> 1);
        if (arr[mid] > key) {
            high = mid - 1;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            if ((mid == size - 1) || (arr[mid + 1] != key)) {
                return mid;
            }
            else {
                low = mid + 1;
            }
        }
    }
    return -1;
}

//变体三：查找第一个大于等于给定值的元素
int bsearch_bt3(int *arr, int size, int key) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + ((high -low) >> 1);
        if (arr[mid] >= key) {
            if ((mid == 0) || (arr[mid - 1] < key)) {
                return mid;
            }
            else {
                high = mid - 1;
            }
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

//变体四：查找最后一个小于等于给定值的元素
int bsearch_bt4(int *arr, int size, int key) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + ((high -low) >> 1);
        if (arr[mid] > key) {
            high = mid - 1;
        }
        else {
            if ((mid == size - 1) || (arr[mid + 1] > key)) {
                return mid;
            }
            else {
                low = mid + 1;
            }
        }
    }
    return -1;
}

int bsearch1(int *arr, int size, int key) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        // int mid = (low + high) / 2;
        // int mid = low + (high - low) / 2;
        int mid = low + ((high - low) >> 1);
        
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    return -1;
}

// 递归实现

int bsearchInternally(int *arr, int low, int high, int key) {
    
    if (low > high) {
        return - 1;
    }
    
    int mid = low + ((high - low) >> 1);
    if (arr[mid] == key) {
        return mid;
    }
    else if (arr[mid] < key) {
        return bsearchInternally(arr, mid + 1, high, key);
    }
    else {
        return bsearchInternally(arr, low, mid - 1, key);
    }
}

int bsearch2(int *arr, int size, int key) {
    return bsearchInternally(arr, 0, size - 1, key);
}

void testSearch(void) {
    int arr[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int len = sizeof(arr)/ sizeof(arr[0]);
    int key = 6;
    
//    int ret = bsearch1(arr, len, key);
    int ret = bsearch2(arr, len, key);
    printf("ret = %d\n",ret);
    
}
