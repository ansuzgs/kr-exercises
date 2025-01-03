#include <ctype.h>
#include <stdio.h>

#define MAX_STR 100

int get_line(char line[], int lim);
int htoi(char str[], int len);

int main(void) {

    char line[MAX_STR];
    int len = get_line(line, MAX_STR);
    printf("%d\n", htoi(line, len));
    return 0;
}

int get_line(char line[], int lim) {
    int c, i = 0;
    while (i < lim - 1 && (c = getchar()) != EOF && c != '\n') {
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}

int htoi(char str[], int len) {
    int res = 0;
    int i = 0;

    while (i < len) {
        if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X')) {
            i += 2;
        }
        int tmp = tolower(str[i]);

        if (isdigit(tmp)) {
            tmp -= '0';
        } else if (tmp >= 'a' && tmp <= 'f') {
            tmp = tmp - 'a' + 10;
        } else {
            printf("Error\n");
            break;
        }

        res = 16 * res + tmp;
        i++;
    }

    return res;
}
