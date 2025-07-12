#include <stdio.h>

int main() {
    int guess;

    while(scanf("%d", &guess) != EOF) {
        if(guess == 50) {
            printf("Spot on\n");
            break;
        }
        else if(guess > 50)
            printf("Toooo high\n");
        else
            printf("Toooo low\n");
    }
}