#include <stdio.h>

int main(void) {

    int c;
    int space = 0;

    while ((c = getchar()) != EOF) {
        space = (c == ' ') ? (space + 1) : 0;
        if (space < 2) {
            putchar(c);
        }
    }
    return 0;
}
