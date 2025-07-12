#include <stdio.h>

int main() {
    int c, nl;

    printf("%d", nl);
    while ((c = getchar()) != EOF)
    {
        if(c=='\n')
            ++nl;
    }
    printf("New Line count %d", nl);
}