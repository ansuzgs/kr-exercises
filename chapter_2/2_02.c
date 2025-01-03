#include <stdio.h>

#define MAXLINE 1000

int main(void) {
    char s[MAXLINE];

    // int i;
    // int c;
    // for (i = 0; (i < MAXLINE - 1) * ((c = getchar()) != '\n') * (c != EOF);
    // ++i)
    // {
    //   s[i] = c;
    // }

    int i = 0;
    int loop = 1;
    while (loop) {
        char c = getchar();

        if (i >= (MAXLINE - 1) || c == '\n' || c == EOF) {
            loop = 0;
        }

        s[i++] = c;
    }

    s[i] = '\0';

    printf("%s", s);

    return 0;
}
