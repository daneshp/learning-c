#include <stdio.h>

int atoi(char s[]);
char lower(char c);

int main() {
    int n = atoi("8973");
    
    char c;
    int is_digit = c >= '0' && c <= '9'; // Even here logical operations are designed to have 1 if true and 0 is false

    printf("Number: %d\n", n);
    printf("Lower of C is %c\n", lower('C'));
}

int atoi(char s[]) {
    int n = 0;
    for(int i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}

char lower(char c) {
    if(c >= 'A' && c <= 'Z') {
        return c + 'a' - 'A';
    }
    return c;
}