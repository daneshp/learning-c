#include <stdio.h>
#include <termios.h>

int main() {
    int count = 0;
    int character;

    while((character = getchar()) !=  EOF) {
        count++;
    }

    printf("Character count %d", count-1);
    printf("Exit worked");
}