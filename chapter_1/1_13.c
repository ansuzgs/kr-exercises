#include <stdio.h>

#define BUFFER 100

int main(void) {

    int c;
    int histogram[BUFFER] = {0};
    int histogram_length = 0;

    int wc = 0;
    while ((c = getchar()) != EOF) {

        if (c == ' ' || c == '\t' || c == '\n' || c == EOF) {
            histogram[wc - 1]++;
            histogram_length =
                (histogram_length < wc - 1) ? (wc - 1) : histogram_length;
            wc = 0;
            if (c == EOF) {
                break;
            }
        } else {
            wc++;
        }
    }

    putchar('\n');
    printf("Horizontal histogram\n");

    int col_index = 0;
    while (col_index <= histogram_length) {
        printf("%3d: \t", col_index + 1);
        for (int line_index = 0; line_index < histogram[col_index];
             line_index++) {
            putchar('#');
        }
        putchar('\n');
        col_index++;
    }

    return 0;
}
