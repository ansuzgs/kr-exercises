#include <stdio.h>

#define MAXLINE 1000
#define LIM 80

int my_getline(char line[], int maxline);
void reverse(char line[], int length);

int main(void) {
    int len;
    char line[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0) {
        reverse(line, len);
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

void reverse(char line[], int length) {
    int i, j;
    int temp;

    i = 0;
    j = (line[length - 1] == '\n') ? (length - 2) : (length - 1);

    while (i < j) {
        temp = line[i];
        line[i] = line[j];
        line[j] = temp;
        i++;
        j--;
    }
}
