#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

void my_itob(int n, char s[], int b);
char itoc(int a);
void rev(char s[]);

int main(void) {

    int n = 76;
    int b = 2;
    char s[MAXLEN] = {0};

    my_itob(n, s, b);
    printf("%s\n", s);

    return 0;
}

char itoc(int a) {
    if (a <= 9) {
        return a + '0';
    }
    return a + 'a' - 10;
}

void my_itob(int n, char s[], int b) {
    int i, sign;

    sign = n;
    i = 0;

    do {
        s[i++] = itoc(abs(n) % b);
    } while ((n /= b) > 0);

    switch (b) {
    case 2:
        s[i++] = 'b';
        s[i++] = '0';
        break;
    case 16:
        s[i++] = 'x';
        s[i++] = '0';
        break;
    }
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
