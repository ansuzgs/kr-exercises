#include <stdio.h>

#define TAB_LEN 8

int main(void) {

    int c;
    unsigned int num_spaces;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            num_spaces = TAB_LEN;

            while (num_spaces) {
                putchar(' ');
                num_spaces--;
            }
        } else {
            putchar(c);
        }
    }

    return 0;
}
