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
        if (ch == 'À' || ch == 'A') printf(".-");
        if (ch == 'Å' || ch == '¨' || ch == 'E') printf(".");
        if (ch == 'Ê' || ch == 'K') printf("-.-");
        if (ch == 'Ï' || ch == 'P') printf(".--.");
        if (ch == 'Ô' || ch == 'F') printf("..-.");
        if (ch == 'Ù' || ch == 'Q') printf("--.-");
        if (ch == 'Á' || ch == 'B') printf("-...");
        if (ch == 'Æ' || ch == 'V') printf("...-");
        if (ch == 'Ë' || ch == 'L') printf(".-..");
        if (ch == 'Ð' || ch == 'R') printf(".-.");
        if (ch == 'Õ' || ch == 'H') printf("....");
        if (ch == 'Â' || ch == 'W') printf(".--");
        if (ch == 'Ç' || ch == 'Z') printf("--..");
        if (ch == 'Ì' || ch == 'M') printf("--");
        if (ch == 'Ñ' || ch == 'S') printf("...");
        if (ch == 'Ö' || ch == 'C') printf("-.-.");
        if (ch == 'Û' || ch == 'Y') printf("-.--");
        if (ch == 'Ã' || ch == 'G') printf("--.");
        if (ch == 'È' || ch == 'I') printf("..");
        if (ch == 'Í' || ch == 'N') printf("-.");
        if (ch == 'Ò' || ch == 'T') printf("-");
        if (ch == 'Ü' || ch == 'X') printf("-..-");
        if (ch == 'Ä' || ch == 'D') printf("-.. ");
        if (ch == 'É' || ch == 'J') printf(".---");
        if (ch == 'Î' || ch == 'O') printf("---");
        if (ch == 'Ó' || ch == 'U') printf("..-");
        if (ch == '×') printf("---.");
        if (ch == 'Ø') printf("----");
        if (ch == 'Ú') printf(".--.-.");
        if (ch == 'Ý') printf("...-...");
        if (ch == 'Þ') printf("..--");
        if (ch == 'ß') printf(".-.-");
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