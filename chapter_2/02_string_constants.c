#include <stdio.h>

int main() {
    // Single and double quotes hold different meaning in C

    char x[3] = "Hi";
    char y[3] = { 'H', 'i'};

    printf("%s \n", x);
    printf("%s \n", y);
    printf("%s \n", "Hi");
    printf("%c%c \n", 'H', 'i');

}