//
//  leetCode-0012.c
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/16.
//  Copyright © 2018年 Giga. All rights reserved.
//

#include "leetCode-0012.h"

#include <stdlib.h>
#include <string.h>

void num2char(char **num, int bit, int n)
{
    char *p = *num;
    char low = '\0';
    char mid = '\0';
    char high = '\0';
    
    switch (n) {
        case 2:
            low = 'C';
            mid = 'D';
            high = 'M';
            break;
        case 1:
            low = 'X';
            mid = 'L';
            high = 'C';
            break;
        case 0:
            low = 'I';
            mid = 'V';
            high = 'X';
            break;
    }
    
    if (bit > 0) {
        switch (bit) {
            case 1:
            case 2:
            case 3:
                for (int i = 0; i < bit; i++) {
                    *p++ = low;
                }
                break;
            case 4:
                *p++ = low;
                *p++ = mid;
                break;
            case 5:
                *p++ = mid;
                break;
            case 6:
            case 7:
            case 8:
                *p++ = mid;
                for (int i = 5; i < bit; i++) {
                    *p++ = low;
                }
                break;
            case 9:
                *p++ = low;
                *p++ = high;
                break;
        }
    }
    *num = p;
}

static char roman_numeral[64];

char* intToRoman(int num) {
    char *p = &roman_numeral[0];
    int thousand_bit = num / 1000;
    int thundred_bit = (num % 1000) / 100;
    int ten_bit = (num % 100) / 10;
    int one_bit = num % 10;
    
    memset(roman_numeral,0,sizeof(roman_numeral));
    
    if (thousand_bit > 0) {
        if (thousand_bit < 4) {
            for (int i = 0; i < thousand_bit; i++) {
                *p++ = 'M';
            }
        }
    }
    
    num2char(&p, thundred_bit, 2);
    num2char(&p, ten_bit, 1);
    num2char(&p, one_bit, 0);
    
    return roman_numeral;
}

void test_0012(void) {
    
}
