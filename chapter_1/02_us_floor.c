#include <stdio.h>

int main() {
    int usf, inf;
    printf("Enter US Floor value: ");
    scanf("%d", &usf);
    inf = usf - 1;
    printf("IND Floor: %d\n", inf);
}