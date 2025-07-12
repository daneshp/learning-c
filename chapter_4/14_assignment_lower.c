#include<stdio.h>

void lower(char s[]);

int main() {
    char input[] = "DaneSH";
    lower(input);

    printf("Lower: %s", input);
}

void lower(char s[]) {
    for(int i = 0; s[i]; i++) {
        s[i] = s[i] >= 'A' && s[i] <= 'Z' ? (s[i] - 'A') + 'a' : s[i]; 
    }
}