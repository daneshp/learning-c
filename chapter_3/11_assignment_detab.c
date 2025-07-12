#include <stdio.h>

#define TABSIZE 4
#define MAXLENGTH 1000

int main() {
    char c;
    int count = 0;
    int group_count = 0;
    int spaces = 0;
    char result[MAXLENGTH];

    while((c = getchar()) != EOF) {
        if (c != '\t') {
            result[count] = c;
            group_count++;
            count++;
        }
        if (c == '\t') {
            spaces = TABSIZE - (group_count % TABSIZE);
            group_count = 0;

            for(int i = 0; i < spaces; i++) {
                result[count] = ' ';
                count++;
            }
        }
    }
    result[count] = '\0'; // Without this is end you reading random bytes in memory
    printf("\nTabed Line: |%s|\n", result);
}