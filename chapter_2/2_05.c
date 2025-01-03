#include <stdio.h>

int any(char s[], char c[]);

int main(void) {

    char s[] = "abcdef";
    char c[] = "gde";
    int res = any(s, c);
    printf("%d\n", res);

    return 0;
}

int any(char s[], char c[]) {
    int i, k;

    for (k = 0; c[k] != '\0'; k++) {
        for (i = 0; s[i] != '\0'; i++) {
            if (s[i] == c[k]) {
                return i;
            }
        }
    }
    return -1;
}
