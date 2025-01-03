#include <stdio.h>

int main(void) {
    int c, ns, nt, nl;
    ns = 0;
    nt = 0;
    nl = 0;

    while ((c = getchar()) != EOF) {
        switch (c) {
        case ' ':
            ++ns;
            break;

        case '\t':
            ++nt;
            break;

        case '\n':
            ++nl;
            break;
        }
    }

    printf("Num blanks: %d\n", ns);
    printf("Num tabs: %d\n", nt);
    printf("Num newlines: %d\n", nl);
    return 0;
}
