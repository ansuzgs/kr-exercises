#include <stdio.h>

void squeeze(char s[], char c[]);

int main(void) {

    char s[] = "abcdef";
    char c[] = "cde";
    squeeze(s, c);
    printf("%s\n", s);

    return 0;
}

void squeeze(char s[], char c[]) {
    int i, j, k;

    for (k = 0; c[k] != '\0'; k++) {
        for (i = j = 0; s[i] != '\0'; i++) {
            if (s[i] != c[k]) {
                s[j++] = s[i];
            }
        }
        s[j] = '\0';
    }
}
