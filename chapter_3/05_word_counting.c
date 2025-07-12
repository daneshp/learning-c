#include <stdio.h>

#define YES 1
#define NO 0

int main() {

    int c, wc, inword;

    wc = 0;
    inword = NO;

    while ((c = getchar()) != EOF)
    {   
        if(c == '\n' || c == ' ' || c == '\t')
            inword = NO;
        else if (inword == NO) {
            inword = YES;
            wc++;
        }

    }
    printf("Word Count: %d", wc);
}