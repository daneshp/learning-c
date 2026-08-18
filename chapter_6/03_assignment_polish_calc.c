#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.c"
#include "character_buffer.c"

#define MAX_OPERATOR_SIZE 20
#define TOO_BIG '9'
#define NUMBER '0'
#define FUNCTION_STORE '1'
#define FUNCTION_OP '2'

int getop(char s[]);

int main() {
    double op1;
    double op2;
    char s[MAX_OPERATOR_SIZE];
    int var_init[26];
    double var[26];
    int type;

    for(int i = 0; i < 26; i++) {
        var_init[i] = -1;
    }

    while((type = getop(s)) != EOF) {
        switch (type) {

            case NUMBER:
                push(atof(s));
                break;
            case '+':
                pop(&op1);
                pop(&op2);
                push(op1 + op2);
                break;
            case '*':
                pop(&op1);
                pop(&op2);
                push(op1 * op2);
                break;
            case '-':
                pop(&op1);
                pop(&op2);
                push(op2 - op1);
                break;
            case '/':
                pop(&op1);
                pop(&op2);
                if (op1 != 0.0)
                    push(op2 / op1);
                else
                    printf("zero divisor popped\n");
                break;
            case '%':
                pop(&op1);
                pop(&op2);
                if (op1 != 0.0)
                    push(fmod(op2, op1));
                else
                    printf("zero divisor popped\n");
                break;
            case '~':
                pop(&op1);
                push(op1 * -1);
                break;
            case 'e':
                pop(&op1);
                break;
            case '=':
                pop(&op1);
                push(op1);
                printf("\t%f\n", op1);
                break;
            case 'c':
                clear();
                break;
            case FUNCTION_STORE:
                pop(&op1);
                var_init[s[0] - 'A'] = 1;
                var[s[0] - 'A'] = op1;
            case FUNCTION_OP:
                if(var_init[s[0] - 'A'] == -1) {
                    printf("Variable %c has not been initialized", s[0]);
                } else {
                    push(var[s[0] - 'A']);
                }
                break;
            case TOO_BIG:
                printf("%.20s ... is too long\n", s);
                break;
            default:
                printf("unknown command '%c'\n", type);
                break;
        }
    }
}

int getop(char s[]) {
    int c;

    while((c = getch()) == ' ' || c == '\t' || c == '\n' || c == '\0');

    if(c == '>') {
        if ((c = getch()) >= 'A' && c <= 'Z') {
            s[0] = c;
            return FUNCTION_STORE;
        }
        ungetch(c);
        return '>';
    }

    if(c >= 'A' && c <= 'Z') {
        s[0] = c;
        return FUNCTION_OP;
    }

    if(c != '.' && (c < '0' || c > '9')) {
        return c;
    }

    s[0] = c;
    int i;
    for(i = 1; i < MAX_OPERATOR_SIZE; i++) {
        c = getch();
        if(c >= '0' && c <= '9') {
            s[i] = c;
            continue;
        }
        break;
    }
    if(c == '.') {
        s[i++] = c;
        for(;i < MAX_OPERATOR_SIZE; i++) {
            c = getch();
            if(c >= '0' && c <= '9') {
                s[i] = c;
                continue;
            }
            break;
        }
    }

    if (i < MAX_OPERATOR_SIZE) {
        ungetch(c);
        s[i] = '\0';
        return NUMBER;

    }

    while((c = getch()) != '\n' && c != EOF);
    s[MAX_OPERATOR_SIZE-1] = '\0';
    return TOO_BIG;
}
