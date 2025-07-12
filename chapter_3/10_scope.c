#include <stdio.h>

#define MAXLENGTH 1000

char line[MAXLENGTH];
char save[MAXLENGTH];
int max;

int get_line();
void copy();

int main() {
    int len;
    extern int max;
    extern char save[MAXLENGTH];

    max = 0;
    while((len = get_line()) > 0 ){
        if(len > max) {
            max = len;
            copy();
        }
    }
    printf("Longest line: %s\n", save);
}

int get_line() {
    char c;
    int i;
    extern char line[MAXLENGTH];

    for(i = 0; i < MAXLENGTH-1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }
    return i;
}

void copy() {
    int i = 0;
    while((save[i] = line[i]) != '\0') {
        i++;
    }
}