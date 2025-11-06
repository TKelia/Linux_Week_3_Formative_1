// crypto.c
#include <string.h>

#define KEY 4

void encrypt(char *text) {
    for (int i = 0; text[i]; i++) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            text[i] = ((c - 'a' + KEY) % 26) + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            text[i] = ((c - 'A' + KEY) % 26) + 'A';
        }
    }
}

void decrypt(char *text) {
    for (int i = 0; text[i]; i++) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            text[i] = ((c - 'a' - KEY + 26) % 26) + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            text[i] = ((c - 'A' - KEY + 26) % 26) + 'A';
        }
    }
}
