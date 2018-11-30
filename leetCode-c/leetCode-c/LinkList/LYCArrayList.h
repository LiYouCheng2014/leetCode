//
//  LYCArrayList.h
//  leetCode-c
//
//  Created by liyoucheng on 2018/11/29.
//  Copyright © 2018年 Giga. All rights reserved.
//

#ifndef LYCArrayList_h
#define LYCArrayList_h

#include <stdio.h>

typedef int ArrayListData;

#define MAXSIZE 100

typedef struct array_list {
    ArrayListData Data[MAXSIZE];
    int length;//线性表最后一个元素位置，从0开始
}ArrayList;

#endif /* LYCArrayList_h */
