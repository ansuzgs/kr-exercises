#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

void my_itoa(int n, char s[]);
void rev(char s[]);

int main(void) {

    int n = 76;
    char s[MAXLEN] = {0};

    my_itoa(n, s);
    printf("%s\n", s);

    return 0;
}

void my_itoa(int n, char s[]) {
    int i, sign;

    sign = n;
    i = 0;

    do {
        s[i++] = (abs(n) % 10) + '0';
    } while ((n /= 10));

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    rev(s);
}

void rev(char s[]) {

    // Initialize l and r pointers
    int l = 0;
    int r = strlen(s) - 1;
    char t;

    // Swap characters till l and r meet
    while (l < r) {

        // Swap characters
        t = s[l];
        s[l] = s[r];
        s[r] = t;

        // Move pointers towards each other
        l++;
        r--;
    }
}
