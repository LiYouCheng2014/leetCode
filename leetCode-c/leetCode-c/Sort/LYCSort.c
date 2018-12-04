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
}//O(n^2)

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
    quickSort(arr, len);
    
    printf("排序后:");
    printArray(arr, len);
}
