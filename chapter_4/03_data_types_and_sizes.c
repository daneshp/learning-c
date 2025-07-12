#include <stdio.h>

int main() {
    printf("Size in bytes\n");
    printf("Char %zu\n", sizeof(char)); // sizeof is an operator like + - && || and not a function so it is intepreted at compile time
    printf("Int %zu\n", sizeof(int));
    printf("Short Int %zu\n", sizeof(short int));
    printf("Long Int %zu\n", sizeof(long int));
    printf("Float %zu\n", sizeof(float));
    printf("Double %zu\n", sizeof(double));
}
