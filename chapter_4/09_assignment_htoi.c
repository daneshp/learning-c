#include<stdio.h>

#define MAXLINE 1000

unsigned int htoi(char hex[]);

int main() {
    char c;
    int i = 0;
    char hex[MAXLINE];
    
    while ((c = getchar()) != EOF)
    {   
        hex[i++] = c;
    }
    hex[i++] = '\0';
    printf("Integer is: %u\n", htoi(hex)); // According to c99 Standard: 7.19.6.1 having a different formatter type compared to the variable results in undefined behaviour 
}

unsigned int htoi(char hex[]) {
    unsigned int hexint = 0;

    for(int i = 0; hex[i]; i++) {
        if(hex[i] >= '0' && hex[i] <= '9') {
            hexint = hexint * 16 + (hex[i] - '0');
        }
        if(hex[i] >= 'A' && hex[i] <= 'F') {
            hexint = hexint * 16 + (hex[i] - 'A' + 10);
        }
    }
    return hexint;
}