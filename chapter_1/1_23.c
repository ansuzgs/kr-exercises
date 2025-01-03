#include <stdio.h>

#define MAXLINE 10000

#define TRUE (1 == 1)
#define FALSE !TRUE

typedef enum states_e {
    STATE_NORMAL,
    STATE_IN_QUOTE,
    STATE_IN_LINE_COMMENT,
    STATE_IN_BLOCK_COMMENT
} states_e;

// This is a test comment.

int get_line(char line[], int max_line_len);
void remove_comments(char line[], char no_comments_line[]);

int main(void) {
    /**
     * This is multiline
     * block
     * comment
     */
    char line[MAXLINE];
    char no_comments_line[MAXLINE];

    get_line(line, MAXLINE);
    remove_comments(line, no_comments_line);
    printf("%s", no_comments_line);

    return 0;
}

int get_line(char line[], int max_line_len) {
    int c, i = 0;

    while (i < max_line_len - 1 && (c = getchar()) != EOF) {
        line[i++] = c;
    }

    line[i] = '\0';

    return i;
}

void remove_comments(char line[], char no_comments_line[]) {

    int i = 0;
    int j = 0;
    states_e state = STATE_NORMAL;

    while (line[i] != '\0') {
        switch (state) {
        case STATE_NORMAL:
            if (line[i] == '\"') {
                state = STATE_IN_QUOTE;
            } else if (line[i] == '/' && line[i + 1] == '/') {
                state = STATE_IN_LINE_COMMENT;
            } else if (line[i] == '/' && line[i + 1] == '*') {
                state = STATE_IN_BLOCK_COMMENT;
            } else {
                no_comments_line[j++] = line[i];
            }
            break;
        case STATE_IN_QUOTE:
            if (line[i] == '\"') {
                state = STATE_NORMAL;
            } else {
                no_comments_line[j++] = line[i];
            }
            break;
        case STATE_IN_LINE_COMMENT:
            if (line[i] == '\n') {
                state = STATE_NORMAL;
            }
            break;
        case STATE_IN_BLOCK_COMMENT:
            if (line[i] == '*' && line[i + 1] == '/') {
                i++;
                state = STATE_NORMAL;
            }
            break;
        }
        i++;
    }
}
