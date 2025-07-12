#include <stdio.h>

#define MAXLENGTH 1000

void squeeze(char s[], char c);

int main() {
    char c;
    char input[MAXLENGTH];
    int length = 0;

    printf("Enter striing: \n");
    while((c = getchar()) != EOF) {
        input[length++] = c;
    }
    input[length] = '\0';

    clearerr(stdin); // This EOF remains in STDIN so the scanf also terminates

    printf("Enter char: ");
    scanf("%c", &c);

    squeeze(input, c);
    printf("\nFinal String: %s", input);
}

void squeeze(char s[], char c) {
    int j = 0;

    for(int i = 0; s[i]; i++) {
        if(s[i] == c) {
            continue;
        }
        
        s[j] = s[i];
        j++;
    }
    s[j] = '\0';
}