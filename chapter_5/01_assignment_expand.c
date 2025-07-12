#include<stdio.h>

#define MAXLINE 1000

void expand(char s[], char t[]);

int main() {
    char s[MAXLINE]; 
    char t[MAXLINE];
    char c;
    int i = 0;

    while((c = getchar()) != EOF) {
        s[i++] = c;
    }
    s[i] = '\0';

    expand(s, t);
    printf("Expanded: %s", t);
}

void expand(char s[], char t[]) {

    int j = 0;
    for(int i = 0; s[i]; i++) {
    switch (s[i])
        {
        case '\t':
            t[j++] = '\\';
            t[j++] = 't';
            break;
        case '\n':
            t[j++] = '\\';
            t[j++] = 'n';
            break;
        default:
            t[j++] = s[i];
            break;
        }
    }
}

