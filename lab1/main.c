#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_double.h"

void write(char str[]) {
    if (*str == '\0') return;
    write(str + 1);
    printf("%c", *str);
}

int increment(char str[]) {
    if (*str == '\0') return 1;
    if (*str == '9') {
        *str = '0';
        return increment(str + 1);
    } else {
        (*str)++;
        return 0;
    } 
}

int main() {
    char *number, rub[81] = "", pen[4] = "";
    int i, ps, len;
    puts("input non-negative number");
    while(1) {
        number = get_string();
        if (valid(number)) break;
    }
    len = ps = (int)strlen(number);
    for (i = 0; i < len; i++) {
        if (number[i] == '.') {
            ps = i;
            break;
        }
    }
    for (i = ps - 1; i >= 0; i--) 
        strncat(rub, &number[i], 1);
    if (ps != len) {
        for (i = min(len - 1, ps + 2); i >= ps + 1; i--) 
            strncat(pen, &number[i], 1);
        if (ps + 3 < len && number[ps + 3] >= '5') {
            if (increment(pen) && (increment(rub))) 
                strcat(rub, "1");
        }
    }
    
    write(rub);
    printf(" rub. ");
    write(pen);
    for (i = (int)strlen(pen); i < 2; i++) printf("0");
    printf(" pen.");
    return 0;
}