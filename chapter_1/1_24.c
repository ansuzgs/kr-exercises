#include <stdio.h>

#define MAXLINE 10000
#define MAX_STACK 1024

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
int check_syntax(char text[]);

int main(void) {
    /**
     * This is multiline
     * block
     * comment
     */
    char line[MAXLINE];

    get_line(line, MAXLINE);
    int check = check_syntax(line);
    if (check == 0) {
        printf("OK\n");
    } else {
        printf("Failed\n");
    }

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

int check_syntax(char text[]) {

    states_e state = STATE_NORMAL;
    char stack[MAX_STACK];
    int top = -1;

    int i = 0;

    while (text[i] != EOF) {
        switch (state) {
        case STATE_NORMAL:
            if (text[i] == '\"') {
                state = STATE_IN_QUOTE;
            } else if (text[i] == '/' && text[i + 1] == '/') {
                state = STATE_IN_LINE_COMMENT;
            } else if (text[i] == '/' && text[i + 1] == '*') {
                state = STATE_IN_BLOCK_COMMENT;
            } else if (text[i] == '(' || text[i] == '[' || text[i] == '{') {
                if (top < MAX_STACK - 1) {
                    stack[++top] = text[i];
                } else {
                    fprintf(stderr, "Error: stack overflow\n");
                    return 1;
                }
            } else if (text[i] == ')' || text[i] == ']' || text[i] == '}') {
                if (top < 0) {
                    fprintf(stderr,
                            "Error: closure symbol '%c' without opening\n",
                            text[i]);
                    return 1;
                } else {
                    char open = stack[top--];
                    if ((open == '(' && text[i] != ')') ||
                        (open == '[' && text[i] != ']') ||
                        (open == '{' && text[i] != '}')) {
                        fprintf(stderr, "Error: dont match '%c' with '%c'\n",
                                open, text[i]);
                        return 1;
                    }
                }
            }
            break;
        case STATE_IN_QUOTE:
            if (text[i] == '\"') {
                state = STATE_NORMAL;
            }
            break;
        case STATE_IN_LINE_COMMENT:
            if (text[i] == '\n') {
                state = STATE_NORMAL;
            }
            break;
        case STATE_IN_BLOCK_COMMENT:
            if (text[i] == '*' && text[i + 1] == '/') {
                i++;
                state = STATE_NORMAL;
            }
            break;
        }
        i++;
    }

    if (top >= 0) {
        fprintf(stderr, "Error: unbalanced symbols\n");
        return 1;
    } else {
        switch (state) {
        case STATE_IN_BLOCK_COMMENT:
        case STATE_IN_LINE_COMMENT:
            fprintf(stderr, "Error: unclosed comment\n");
            return 1;
        case STATE_IN_QUOTE:
            fprintf(stderr, "Error: unfinished string\n");
            return 1;
        case STATE_NORMAL:
            return 0;
        }
    }
    return 1;
}
