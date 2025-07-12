#include<stdio.h>

int bitcount(int n);

int main() {
    printf("Bitcount: %d", bitcount(23));
}

// Brian Kernighan's algorithm
int bitcount(int n) {
    int count = 0;
    while(n != 0) { 
        n &= (n-1);
        count++;
    }
    return count;
}