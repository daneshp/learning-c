#include <stdio.h>

int main() {
    char line[10];
    printf("Enter line: \n");
    // scanf("%[^\n]10s", line);
    fgets(line, 10, stderr);
    printf("Line: %s\n", line);
}