#include <stdio.h>

#define MAXLINE 1000
#define LIM 80

int my_getline(char line[], int maxline);
void remove_trailing(char line[], int length);

int main(void) {
    int len;
    char line[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0) {
        remove_trailing(line, len);
        printf("%s", line);
    }

    return 0;
}

int my_getline(char line[], int maxline) {

    int c, i;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}

void remove_trailing(char line[], int length) {
    int i;

    for (i = length - 2; line[i] != ' ' || line[i] != '\t'; i--)
        ;

    line[i + 1] = '\n';
    line[i + 2] = '\0';
}
