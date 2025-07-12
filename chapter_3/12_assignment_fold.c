#include <stdio.h>

#define MAXLENGTH 1000
#define LINEBREAK 20

int main() {
    char c;
    char result[MAXLENGTH];
    int count = 0;
    int line = 0;
    int last_space = 0;

    while((c = getchar()) != EOF) {
        if(c == ' ') {
            last_space = count;
        }

        result[count] = c;
        count++;
        line++;

        if (line > LINEBREAK && last_space != 0) {
            result[last_space] = '\n';
            last_space = 0;
            line = 0;
        }
    }

    result[count] = '\0';
    printf("Formatted Text: \n%s", result);
}