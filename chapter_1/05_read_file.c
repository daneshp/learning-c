#include <stdio.h>

int main() {
    char line[1000];
    FILE *handler;
    handler = fopen("test.txt", "r");
    while (fgets(line, 1000, handler) != NULL) {
        printf("%s", line);
    }
}