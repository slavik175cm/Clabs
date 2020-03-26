#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_string() {
    static char number[81] = "";
    char c = 'a';
    int kol = 0;
    while (1) {
        c = getchar();
        if (c == '\n') break;
        if (kol == 80) {
            puts("The input is too big, try again");
            while (c != '\n') c = getchar();
            return get_string(); 
        }
        number[kol++] = c;
    }
    if (kol == 0) {
        puts("String is empty, try again");
        return get_string();
    }
    number[kol] = '\0';
    return number;
}
