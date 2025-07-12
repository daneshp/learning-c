#include <stdio.h>

int main() {
    int c, nwhite, nother;
    int ndigits[10];

    nwhite = nother = 0;
    for(int i = 0; i<10; i++) {
        ndigits[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if(c >= '0' && c <= '9') {
            ++ndigits[c - '0'];
            continue;
        }

        if(c == ' ') {
            nwhite++;
            continue;
        }

        nother++;
    }

    for(int i = 0; i<10; i++) {
        printf("%d: %d\n", i ,ndigits[i]);
    }
    
}