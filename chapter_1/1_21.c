#include <stdio.h>

#define TAB_LENGTH 8

int main(void) {
    int c;
    unsigned int line_pos = 0;
    unsigned int num_spaces = 0;

    while ((c = getchar()) != EOF) {
        line_pos++;

        if (c == ' ') {
            num_spaces++;

            if (line_pos % TAB_LENGTH == 0 && num_spaces > 1) {
                putchar('\t');
                num_spaces = 0;
            }
        } else {
            while (num_spaces) {
                putchar(' ');
                num_spaces--;
            }

            if (c == '\n') {
                line_pos = 0;
            }

            putchar(c);
        }
    }

    return 0;
}
