#include <stdio.h>

#define MAXLENGTH 1000
#define TRUE 1
#define FALSE 0

void mcomment();
void scomment();

int main() {
    char c;
    char d;
    char code[MAXLENGTH];
    int count = 0;

    while ((c = getchar()) != EOF)
    {
        if(c == '/') {
            if((d = getchar()) == '*') {
                mcomment();
            }
            else if(d == '/') {
                scomment();
                code[count++] = '\n';
            } else {
                code[count++] = d;
            }
        } else {
            code[count++] = c;
        }
    }
    code[count] = '\0';
    printf("Code:\n%s", code);
}



void mcomment() {
    char c = getchar();
    char d = getchar();

    while (c != '*' || d != '/')
    {
        c = d;
        d = getchar();
    }
}

void scomment() {
    char c = getchar();

    while (c != '\n')
    {
        c = getchar();
    }
}