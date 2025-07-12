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
    int i, j, x, count;
    i = j = x = count = 0;

    while (s[i]) {

        if(s[i] >= 'a' && s[i] <= 'z' && s[i+1] =='-' && s[i+2] >= s[i] && s[i+2] <= 'z') {
            x = 0;
            count = s[i+2] - s[i] + 1;

            while(x < count) {
                t[j++] = s[i] + x;
                x++;
            }
            i+=3;
            continue;
        }
        
        if(s[i] >= '0' && s[i] <= '9' && s[i+1] =='-' && s[i+2] >= s[i] && s[i+2] <= '9') {
            x = 0;
            count = s[i+2] - s[i] + 1;

            while(x < count) {
                t[j++] = s[i] + x;
                x++;
            }
            i+=3;
            continue;
        }

        t[j++] = s[i++];
    }
    t[j++] = '\0';
}

