#include <stdio.h>
#define MAX_DEPTH 100

static int sp = 0;
static double s[MAX_DEPTH];

int push(double number) {
    if(sp < MAX_DEPTH) {
        s[sp++] = number;
        return 1;
    }
    printf("The stack is full");
    return 0;
}

int pop(double *number) {
    if(sp > 0) {
        *number = s[--sp];
        return 1;
    }
    printf("The stack is empty");
    return 0;
}

void clear() {
    sp = 0;
}
