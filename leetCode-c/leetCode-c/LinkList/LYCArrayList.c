//
//  LYCArrayList.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/11/29.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "LYCArrayList.h"

#include <stdlib.h>

ArrayList *arrayListCreate(int size) {
    ArrayList *list;
    
    list = (ArrayList *)malloc(sizeof(ArrayList));
    if (list == NULL) {
        return NULL;
    }
    
    list->length = 0;
    
    return list;
}

int arrayListFind(ArrayList *list, ArrayListData key) {
    int i;
    for (i = 0; i <= list->length && list->Data[i] != key; i++) {
    }
    
    if (i > list->length) {
        return -1;
    }
    else {
        return i;
    }
}

int arrayListInsert(ArrayList *list, ArrayListData data, int i) {
    if (list->length == MAXSIZE - 1) {
        return -1;
    }
    
    if (i < 0 || i > list->length + 1) {
        return -1;
    }
    
    for (int j = list->length; j >= i - 1; j--) {
        list->Data[j + 1] = list->Data[j];
    }
    list->Data[i - 1] = data;
    list->length++;
    
    return 0;
}

int arrayListDelete(ArrayList *list, int i) {
    if (list->length < 0) {
        return -1;
    }
    
    if (i < 0 || i > list->length) {
        return -1;
    }
    
    for (int j = i; j <= list->length - 1; j++) {
        list->Data[j - 1] = list->Data[j];
    }
    list->length--;
    
    return -1;
}

