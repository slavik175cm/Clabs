#include <stdio.h>
#include "safe_input.h"
#include <locale.h>
#include <Windows.h>
int main() {
    setlocale (LC_ALL, "rus");
    SetConsoleCP(1251);
    puts("input text");
    char *text = get_string();
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (ch == '�' || ch == 'A') printf(".-");
        if (ch == '�' || ch == '�' || ch == 'E') printf(".");
        if (ch == '�' || ch == 'K') printf("-.-");
        if (ch == '�' || ch == 'P') printf(".--.");
        if (ch == '�' || ch == 'F') printf("..-.");
        if (ch == '�' || ch == 'Q') printf("--.-");
        if (ch == '�' || ch == 'B') printf("-...");
        if (ch == '�' || ch == 'V') printf("...-");
        if (ch == '�' || ch == 'L') printf(".-..");
        if (ch == '�' || ch == 'R') printf(".-.");
        if (ch == '�' || ch == 'H') printf("....");
        if (ch == '�' || ch == 'W') printf(".--");
        if (ch == '�' || ch == 'Z') printf("--..");
        if (ch == '�' || ch == 'M') printf("--");
        if (ch == '�' || ch == 'S') printf("...");
        if (ch == '�' || ch == 'C') printf("-.-.");
        if (ch == '�' || ch == 'Y') printf("-.--");
        if (ch == '�' || ch == 'G') printf("--.");
        if (ch == '�' || ch == 'I') printf("..");
        if (ch == '�' || ch == 'N') printf("-.");
        if (ch == '�' || ch == 'T') printf("-");
        if (ch == '�' || ch == 'X') printf("-..-");
        if (ch == '�' || ch == 'D') printf("-.. ");
        if (ch == '�' || ch == 'J') printf(".---");
        if (ch == '�' || ch == 'O') printf("---");
        if (ch == '�' || ch == 'U') printf("..-");
        if (ch == '�') printf("---.");
        if (ch == '�') printf("----");
        if (ch == '�') printf(".--.-.");
        if (ch == '�') printf("...-...");
        if (ch == '�') printf("..--");
        if (ch == '�') printf(".-.-");
        if (ch == '1') printf(".----");
        if (ch == '2') printf("..---");
        if (ch == '3') printf("...--");
        if (ch == '4') printf("....-");
        if (ch == '5') printf(".....");
        if (ch == '6') printf("-....");
        if (ch == '7') printf("--...");
        if (ch == '8') printf("---..");
        if (ch == '9') printf("----.");
        if (ch == '0') printf("-----");
        if (ch == '.') printf(".-.-.-");
        if (ch == ',') printf("--..--");
        if (ch == ':') printf("---...");
        if (ch == '?') printf("..--..");
        if (ch == '"') printf(".----.");
        if (ch == '-') printf("-....-");
        if (ch == '/') printf("-..-.");
        if (ch == ';') printf("-.--.-");

        printf(" ");
    }
    return 0;
}