#include <stdio.h>

#define ALPHA_NUM 26
#define NUM_NUM 10

int main(void) {
    int c;
    int histogram[ALPHA_NUM + NUM_NUM] = {0};

    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') {
            histogram[c - 'a']++;
        } else if (c >= '0' && c <= '9') {
            histogram[ALPHA_NUM + (c - '0')]++;
        }
    }

    for (int i = 0; i < (ALPHA_NUM + NUM_NUM); i++) {
        if (i < ALPHA_NUM) {
            printf("%c: ", 'a' + i);
        } else if (i >= ALPHA_NUM) {
            printf("%c: ", '0' + i - ALPHA_NUM);
        }

        int j;
        for (j = 0; j < histogram[i]; ++j) {
            printf("#");
        }

        putchar('\n');
    }
}
