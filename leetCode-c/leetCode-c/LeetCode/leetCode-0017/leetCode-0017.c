//
//  leetCode-0017.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/16.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0017.h"

#include <string.h>
#include <stdlib.h>

char** letterCombinations(char* digits, int* returnSize)
{
    char *letter_matrix[10];
    letter_matrix[0] = "";
    letter_matrix[1] = " ";
    letter_matrix[2] = "abc";
    letter_matrix[3] = "def";
    letter_matrix[4] = "ghi";
    letter_matrix[5] = "jkl";
    letter_matrix[6] = "mno";
    letter_matrix[7] = "pqrs";
    letter_matrix[8] = "tuv";
    letter_matrix[9] = "wxyz";
    
    int letter_length[10];
    letter_length[0] = 0;
    letter_length[1] = 1;
    letter_length[2] = 3;
    letter_length[3] = 3;
    letter_length[4] = 3;
    letter_length[5] = 3;
    letter_length[6] = 3;
    letter_length[7] = 4;
    letter_length[8] = 3;
    letter_length[9] = 4;
    
    int i, j, k;
    int empty = 1;
    int count = 1;
    int digit_len = strlen(digits);
    for (i = 0; i < digit_len; i++) {
        int index = digits[i] - '0';
        if (letter_length[index] > 0) {
            empty = 0;
            count *= letter_length[index];
        }
    }
    
    if (empty) {
        *returnSize = 0;
        return NULL;
    }
    
    *returnSize = count;
    
    char **letters = malloc(sizeof(char *) * count);
    for (i = 0; i < count; i++) {
        letters[i] = malloc(digit_len + 1);
        memset(letters[i], 0, digit_len + 1);
    }
    
    int den = 1;
    for (i = digit_len - 1; i > 0; i--) {
        int index = digits[i] - '0';
        if (letter_length[index] > 0) {
            den *= letter_length[index];
        }
    }
    
    int col = 0;
    for (i = 0; i < digit_len; i++) {
        int index = digits[i] - '0';
        if (letter_length[index] > 0) {
            if (i > 0) {
                int index2 = digits[i] - '0';
                if (letter_length[index2] > 0) {
                    den /= letter_length[index2];
                }
            }
            for (j = 0; j < count; j++) {
                k = j / den % letter_length[index];
                letters[j][col] = letter_matrix[index][k];
            }
            col++;
        }
    }
    
    return letters;
}

void test_0017(void) {
    
}
