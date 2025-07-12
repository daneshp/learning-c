#include<stdio.h>

int powe(int n, int p);
int invert(int x, int p, int n);

int main() {
    printf("Invert %d", invert(245, 4, 3));
}

int powe(int n, int p) {
    int res = 1;
    for(int i = 0; i < p; i++) {
        res = res * n;
    }
    return res;
}

int invert(int x, int p, int n) {
    int mask = 0 | (powe(2, 4) - 1);
    int shifted_mask = ~(mask << (p + 1 - n));

    int selected_num = x >> (p + 1 - n) & ~(~0 << n);
    int inverted_num = ~selected_num & mask;
    inverted_num = inverted_num << (p + 1 - n);


    return (x & shifted_mask) | inverted_num;
}