#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **vocab;
int kol = 0;

void read_key_words(FILE* vocabulary) {
    char s[100];
    int i;
    while (!feof(vocabulary)) {
        fgets(s, 30, vocabulary);
        int cur = 0;
        for (i = 0; s[i] != '\0'; i++) {
            if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') continue;
            vocab[kol][cur++] = s[i];
        }
        vocab[kol][cur] = '\0';
        kol++;
    }
}

int cmp(char *word, char* keyword) {
    int i1 = 0, i2 = 0;
    while (word[i1] != '\0' && keyword[i2] != '\0') {
        if (word[i1] != keyword[i2]) return 0;
        i1++;
        i2++;
    }
    if (word[i1] == '\0' && keyword[i2] == '\0') return 1;
    return 0;
}

int is_key_word(char *word) {
    int i;
    for (i = 0; i < kol; i++) 
        if (cmp(word, vocab[i]) == 1) return 1;
    return 0;
}

void to_upper(char *word) {
    int i;
    for (i = 0; word[i] != '\0'; i++) {
        word[i] = word[i] - 32;
    }
}

void rewrite(FILE* program) {
    char s[300], cur[300], new[1000][300], text[300];
    int i, len = 0, kol = 0;
    while (!feof(program)) {
        fgets(s, 299, program);
        text[0] = '\0';
        for (i = 0; s[i] != '\0'; i++) {
            if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') { strncat(text, &s[i], 1); continue; }
            cur[len++] = s[i];
            if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && (s[i + 1] < 'a' || s[i + 1] > 'z')) {
                cur[len] = '\0';
                if (is_key_word(cur))
                    to_upper(cur);
                strcat(text, cur);
                len = 0;
            }
        }
        if (kol == 300) {
            printf("File is too big");
            return;
        }
        for (i = 0; text[i] != '\0'; i++)
            new[kol][i] = text[i];
        new[kol][i] = text[i];
        kol++;
    }   
    program = fopen("program.txt", "w");
    for (i = 0; i < kol; i++) 
        fprintf(program, "%s", new[i]);
}

int main() {    
    FILE* vocabulary = fopen("keywords.txt", "r");
    FILE* program = fopen("program.txt", "r");
    
    int i;
    vocab = (char **) malloc(100 * sizeof(char*));
    if (vocab == NULL) {
        printf("Not enough memory!");
        return;
    }
    for (i = 0; i < 100; i++) {
        vocab[i] = (char *) malloc(100 * sizeof(char));
        if (vocab[i] == NULL) {
            printf("Not enough memory!");
            return;
        }
    }
    
    read_key_words(vocabulary);
    rewrite(program);

    return 0;
}