#include <stdio.h>

#define MAXLENGTH 1000

int get_line(char s[], int len);
void copy(char s1[], char s2[]);

int main() {

    int len;
    int max = 0;
    char line[MAXLENGTH];
    char save[MAXLENGTH];

    while ((len = get_line(line, MAXLENGTH)) > 0) {
        if(len > max) {
            max = len;
            copy(line, save);
        }
    }
    printf("Longest line: %s", save);
}

int get_line(char s[], int len) {
    char c;
    int i;
    for(i = 0; i < len-1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    return i;
}

void copy(char s1[], char s2[]) {
    int i = 0;
    while ((s2[i] = s1[i]) != '\0') // Assignment also returns the value being assigned
    {
        i++;
    }
}