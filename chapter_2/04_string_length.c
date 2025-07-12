#include <stdio.h>

int py_len(char string[]);

int main() {
    char x[] = "Danesh";
    printf("%s %d", x, py_len(x));
}

int py_len(char string[]) {
    int i;
    for(i=0; string[i];i++);
    return i;
}