#include <stdio.h>

int power(int m, int n);

int main() {
    for(int i = 0; i<10;i++) {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }
}

int power(int m, int n) {
    int p = 1;
    for(int i = 0; n>0; n--) { // So C creates a copy of i and passes it to the function call stack so we dont alter i but a copy of i
        p = p * m; // But it doesnt behave this way for all data types
    }
    return p;
}