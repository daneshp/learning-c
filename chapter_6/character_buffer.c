#include <stdio.h>

#define BUFFER_SIZE 100

static int buffer[BUFFER_SIZE];
static int i = 0;

int getch() {
    // buffer is empty
    if(i > 0) {
        return buffer[i--];
    }

    return getchar();
}

void ungetch(int c) {
    if(i < BUFFER_SIZE) {
        buffer[i++] = c;
        return;
    }
    printf("Character buffer is full\n");
}
