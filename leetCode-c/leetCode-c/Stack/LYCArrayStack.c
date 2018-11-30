//
//  LYCArrayStack.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/11/29.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "LYCArrayStack.h"

#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

int arrayStackSize(ArrayStack *stack) {
    return stack->size;
}

bool arrayStackIsEmpty(ArrayStack *stack) {
    return stack->top == -1;
}

bool arrayStackIsFull(ArrayStack *stack) {
    return stack->top == stack->size - 1;
}

ArrayStack *arrayStackCreate(int size) {
    ArrayStack *stack = NULL;
    
    stack = (ArrayStack *)malloc(sizeof(ArrayStack));
    if (stack == NULL) {
        return NULL;
    }
    
    stack->size = size;
    stack->top = -1;
    stack->array = (ArrayStackData *)malloc(sizeof(ArrayStackData) * size);
    if (stack->array == NULL) {
        free(stack);
        return NULL;
    }
    
    return stack;
}

void arrayStackDestory(ArrayStack *stack) {
    if (stack == NULL) {
        return;
    }
    
    if (stack->array != NULL) {
        free(stack->array);
    }
    
    free(stack);
}

int arrayStackPop(ArrayStack *stack, ArrayStackData *data) {
    if (arrayStackIsEmpty(stack)) {
        return -1;
    }
    *data = stack->array[stack->top];
    stack->top--;
    
    return 0;
}

int arrayStackPush(ArrayStack *stack, ArrayStackData data) {
    if (arrayStackIsFull(stack)) {
        return -1;
    }
    
    stack->top++;
    stack->array[stack->top] = data;
    
    return 0;
}

int arrayStackPushExtension(ArrayStack *stack, ArrayStackData data) {
    if (!arrayStackIsFull(stack)) {
        return arrayStackPush(stack, data);
    }
    
    //栈满
    ArrayStackData *temp = NULL;
    temp = (ArrayStackData *)malloc(sizeof(ArrayStackData) * (2 * stack->size));
    if (temp == NULL) {
        return -1;
    }
    
    memcpy(temp, stack->array, stack->size * sizeof(ArrayStackData));
    
    free(stack->array);
    
    stack->array = temp;
    stack->size = 2 * stack->size;
    stack->top++;
    stack->array[stack->top] = data;
    
    return 0;
}

void arrayStackDump(ArrayStack *stack) {
    if (!arrayStackIsEmpty(stack)) {
        printf("stack: size => %d, top => %d\n",stack->size, stack->top);
        
        for (int i = 0; i <= stack->top; i++) {
            printf("%d\n", stack->array[i]);
        }
    }
}

void arrayStackTest(void) {
    ArrayStack *stack = NULL;
    
    stack = arrayStackCreate(4);
    if (stack == NULL) {
        return;
    }
    
    for (int i = 0; i < 5; i++) {
        int ret = arrayStackPush(stack, i);
        if (ret != 0) {
            printf("insert failure => %d\n",i);
        }
    }
    
    arrayStackDump(stack);
    
    int ret = arrayStackPushExtension(stack, 4);
    if (ret != 0) {
        printf("insert failure => %d\n",4);
        return;
    }
    
    arrayStackDump(stack);
    
    arrayStackDestory(stack);
}

