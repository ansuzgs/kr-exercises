#include <stdio.h>

int bitcount(unsigned x);

int main(void) {
    unsigned int x = 5;
    int bits = bitcount(x);
    printf("%d\n", bits);
    return 0;
}

int bitcount(unsigned x) {
    int b;

    while (x != 0) {
        x &= (x - 1);
        b++;
    }
    return b;
}
