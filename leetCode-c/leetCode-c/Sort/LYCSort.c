//
//  LYCSort.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/2.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "LYCSort.h"

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <memory.h>

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

#pragma mark - 冒泡排序

void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortOptimization(int *arr, int size) {
    bool flag = false;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                flag = true;
            }
        }
        
        if (!flag) {
            break;
        }
    }
}

#pragma mark - 插入排序

void insertSort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        int value = arr[i];
        int j = i - 1;
        for (; j >= 0; j--) {
            if (value < arr[j]) {
                arr[j + 1] = arr[j];
            }
            else {
                break;
            }
        }
        arr[j + 1] = value;
    }
}

#pragma mark - 选择排序

void selectSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

#pragma mark - 归并排序

void merge(int *arr, int p, int q, int r) {
    int *temp = (int *)malloc(sizeof(int) * (r - p + 1));
    if (!temp) {
        return;
    }
    
    int i = p;
    int j = q + 1;
    int k = 0;
    for (; i <= q && j <= r; ) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }
    
    // 判断哪个子数组中有剩余的数据
    if (i == q + 1) {
        for (; j <= r; ) {
            temp[k++] = arr[j++];
        }
    }
    else {
        for (; i <= q; ) {
            temp[k++] = arr[i++];
        }
    }
    
    memcpy(arr + p, temp, (r - p + 1) * sizeof(int));
    free(temp);
}

void mergeSortC(int *arr, int p, int r) {
    if (p >= r) {
        return;
    }
    
    int q = (p + r) / 2;
    mergeSortC(arr, p, q);
    mergeSortC(arr, q + 1, r);
    merge(arr, p, q, r);
}

void mergeSort(int *arr, int size) {
    if (arr == NULL || size < 0) {
        return;
    }
    
    mergeSortC(arr, 0, size - 1);
}

#pragma mark - 快速排序

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int p, int r) {
    int i = p;
    int j = p;
    
    for (; j < r; j++) {
        if (arr[j] < arr[r]) {
            if (i != j) {
                swap(arr + i, arr + j);
            }
            i++;
        }
    }
    
    swap(arr + i, arr + r);
    
    return i;
}

void quickSortC(int *arr, int p, int r) {
    if (p >= r) {
        return;
    }
    
    int q = partition(arr, p, r);
    quickSortC(arr, p, q - 1);
    quickSortC(arr, q + 1, r);
}

void quickSort(int *arr, int size) {
    quickSortC(arr, 0, size - 1);
}

#pragma mark - 希尔排序

void shellSort(int *arr, int len) {
    int d = len / 2;
    while (d >= 1) {
        for (int i = d; i < len; i++) {
            //序列中的下一个数据
            int x = arr[i];
            //序列中前一个数据的序号
            int j = i - d;
            //下一个数大于前一个数
            while (j >= 0 && arr[j] > x) {
                //后一个数向前移动
                arr[j + d] = arr[j];
                //向前比较
                j = j - d;
            }
            //保存数据
            arr[j + d] = x;
        }
        //缩小增量
        d /= 2;
    }
}

#pragma mark - 堆排序

void heapify(int *arr, int size, int i) {
    while (true) {
        int maxPos = i;
        if (2 * i + 1 <= size && arr[i] < arr[2 * i + 1]) {
            maxPos = 2 * i + 1;
        }
        
        if (2 * i + 2 <= size && arr[maxPos] < arr[2 * i + 2]) {
            maxPos = 2 * i + 2;
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

void buildHeap(int *arr, int size) {
    for (int i = (size - 1) / 2; i >= 0; i--) {
        heapify(arr, size, i);
    }
}

void heapSort(int *arr, int size) {
    buildHeap(arr, size);
    
    int k = size - 1;
    while (k > 0) {
        int temp = arr[0];
        arr[0] = arr[k];
        arr[k] = temp;
        
        k--;
        heapify(arr, k, 0);
    }
}

///**
// 创建大堆
//
// @param arr 原数组
// @param s 当前结点
// @param n 堆的大小
// */
//void HeapAdjus(int *arr, int s, int n)
//{
//    while (2 * s + 1 < n) {
//        int j = 2 * s + 1;
//        if ((j + 1) < n) {
//            //左子树小于右子树，则需要比较右子树
//            if (arr[j] < arr[j + 1]) {
//                j++;//序号增加1，指向右子树
//            }
//        }
//
//        //比较s与j为序号的数据
//        if (arr[s] < arr[j]) {
//            int t = arr[s];
//            arr[s] = arr[j];
//            arr[j] = t;
//            //堆被破坏，需要重新调整
//            s = j;
//        }
//        else {
//            //不再需要调整
//            break;
//        }
//    }
//}
//
///**
// 堆排序
//
// @param arr 原数组
// @param len 数组长度
// */
//void heapSort(int *arr, int len)
//{
//    //将a[0]至a[n-1]构成堆
//    for (int i = len / 2 - 1; i >= 0; i--) {
//        HeapAdjus(arr, i, len);
//    }
//
//    //取根节点与末节点交换
//    for (int i = len - 1; i > 0; i--) {
//        int t = arr[0];
//        arr[0] = arr[i];//与第i个记录交换
//        arr[i] = t;
//        //将a[0]至a[i]重新调整为堆
//        HeapAdjus(arr, 0, i);
//    }
//}

#pragma mark - 桶排序

struct barrel {
    int node[10];
    int count;
};

int partitionBucket(int *arr, int left, int right) {
    int i = left;
    int j = right;
    int key = arr[left];
    
    while (i < j) {
        while ((i < j) && (arr[j] >= key)) {
            j--;
        }
        
        if (i < j) {
            arr[i] = arr[j];
        }
        
        while ((i < j) && (arr[j] <= key)) {
            i++;
        }
        
        if (i < j) {
            arr[j] = arr[i];
        }
    }
    arr[i] = key;
    
    return i;
}

void quickSortBucket(int *arr, int left, int right) {
    if (left >= right) {
        return;
    }
    
    int q = partitionBucket(arr, left, right);
    quickSortBucket(arr, left, (q - 1));
    quickSortBucket(arr, (q + 1), right);
}

void bucketSort(int *arr, int size) {
    int max;
    int min;
    max = min = arr[0];
    
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        else if (arr[i] < min) {
            min = arr[i];
        }
    }
    
    int num = (max - min + 1) / 10 + 1;
    struct barrel *pBarrel = (struct barrel*)malloc(sizeof(struct barrel) * num);
    memset(pBarrel, 0, sizeof(struct barrel) * num);
    
    for (int i = 0; i < size; i++) {
        int k = (arr[i] - min + 1) / 10;
        (pBarrel + k)->node[(pBarrel + k)->count] = arr[i];
        (pBarrel + k)->count++;
    }
    
    int pos = 0;
    for (int i = 0; i < num; i++) {
        if ((pBarrel + i)->count != 0) {
            quickSortBucket((pBarrel + i)->node, 0, (pBarrel + i)->count - 1);
            
            for (int j = 0; j < (pBarrel + i)->count; j++) {
                arr[pos++] = (pBarrel + i)->node[j];
            }
        }
    }
    
    free(pBarrel);
}

#pragma mark - 计数排序

void countSort(int *arr, int size) {
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    int *count = (int *)malloc(sizeof(int) * (max + 1));
    
    memset(count, 0, sizeof(int) * (max + 1));
    
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    
    int *res = (int *)malloc(sizeof(int) * size);
    for (int i = size - 1; i >= 0; i--) {
        res[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    memcpy(arr, res, sizeof(int) * size);
    
    free(res);
    free(count);
}

#pragma mark - 基数排序

#define NUM_OF_POS(a,pval) ((a)/pval)%10
void radixSort(int *arr, int size, int numCount) {
    int *pres = (int *)malloc(sizeof(int) * size);
    int index = 0;
    int breakFlag = 0;
    
    int count[10] = {0};
    for (int i = 0; i < numCount; i++) {
        memset(count, 0, sizeof(int) * 10);
        
        //求当前的基数
        int pval = pow(10, i);
        
        //计数
        for (int j = 0; j < size; j++) {
            index = NUM_OF_POS(arr[j], pval);
            count[index]++;
        }
        
        //小的优化，可能位数最大的就1，其他的位数差很多
        if (count[0] == 9) {
            breakFlag++;
        }
        
        if (breakFlag >= 2) {
            break;
        }
        
        //累加
        for (int j = 1; j < 10; j++) {
            count[j] += count[j - 1];
        }
        
        //排序必须从后往前，否则不是稳定排序
        for (int j = size - 1; j >= 0; j--) {
            index = NUM_OF_POS(arr[j], pval);
            pres[count[index] - 1] = arr[j];
            count[index]--;
        }
        
        //本轮排序好的，拷贝到a中
        memcpy(arr, pres, sizeof(int) * size);
    }
}


void testSort(void) {
    int arr[8] = { 19, 3, 10, 9, 16, 11, 28, 26 };
    int len = sizeof(arr)/ sizeof(arr[0]);
    
    printf("排序前:");
    printArray(arr, len);
    
//    bubbleSort(arr, len);
//    bubbleSortOptimization(arr, len);
//    insertSort(arr, len);
//    selectSort(arr, len);
//    mergeSort(arr, len);
//    quickSort(arr, len);
    
//    shellSort(arr, len);
    heapSort(arr, len);
    
//    bucketSort(arr, len);
//    countSort(arr, len);
//    radixSort(arr, len, len);
    
    printf("排序后:");
    printArray(arr, len);
}
