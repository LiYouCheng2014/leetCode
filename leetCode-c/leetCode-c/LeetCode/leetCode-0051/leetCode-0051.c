//
//  leetCode-0051.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/15.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0051.h"

#include <stdlib.h>
#include <assert.h>

void push(int *stack, int row, int col) {
    stack[row] = col;
}

int pop(int *stack, int row) {
    int col = stack[row];
    stack[row] = -1;
    return col;
}

int top(int *stack, int n) {
    for (int row = n - 1; row >= 0; row--) {
        if (stack[row] != -1) {
            return row;
        }
    }
    return 0;
}

//判断在row行col列位置放一个皇后，是否是合法的状态
//已经保证了每行一个皇后，只需要判断列是否合法以及对角线是否合法。
int conflict(int *stack, int row, int col) {
    for (int k = 0; k < row; k++) {
        if (col == stack[k] || abs(row - k) == abs(col - stack[k])) {
            return 1;
        }
    }
    
    return 0;
}

char **solution(int *stack, int n) {
    int row;
    int col;
    char **solution = malloc(n * sizeof(char *));
    for (row = 0; row < n; row++) {
        char *line = malloc(n + 1);
        for (col = 0; col < n; col++) {
            line[col] = (col == stack[row] ? 'Q' : '.');
        }
        line[col] = '\0';
        solution[row] = line;
    }
    return solution;
}

char*** solveNQueens(int n, int* returnSize) {
    int row = 0;
    int col = 0;
    int sum = 0;
    
    char ***solutions = malloc(1000 * sizeof(char **));
    
    int *stack = malloc(n * sizeof(int));
    for (row = 0; row < n; row++) {
        stack[row] = -1;
    }
    
    if (n == 1) {
        stack[0] = 0;
        solutions[0] = solution(stack, n);
        *returnSize = 1;
        return solutions;
    }
    
    for (; ;) {
        for (; row < n; row++) {
            while (col < n) {
                if (conflict(stack, row, col)) {
                    while (col == n - 1) {
                        if (--row < 0) {
                            free(stack);
                            *returnSize = sum;
                            return solutions;
                        }
                        col = pop(stack, row);
                    }
                    col++;
                }
                else {
                    push(stack, row, col);
                    break;
                }
            }
            col = 0;
        }
        
        row = top(stack, n);
        if (row == n - 1) {
            solutions[sum++] = solution(stack, n);
        }
        
        col = pop(stack, row);
        col++;
    }
    
    assert(0);
}

void test_0051(void) {
    int n = 4;
    int row = 0;
    int col = 0;
    int i = 0;
    int num_of_solution;
    char ***solutions = solveNQueens(n, &num_of_solution);
    for (i = 0; i < num_of_solution; i++) {
        char **solution = solutions[i];
        for (row = 0; row < n; row++) {
            char *line = solution[row];
            for (col = 0; col < n; col++) {
                printf("%c\t",line[col]);
            }
            printf("\n");
        }
        printf("The %dth solution.\n", i + 1);
    }
}
