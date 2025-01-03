#include <stdio.h>

int lower(int c);

int main(void) {
    int c = 'A';
    printf("'%c' lowered is: '%c'\n", c, lower(c));
    return 0;
}

int lower(int c) { return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c; }
