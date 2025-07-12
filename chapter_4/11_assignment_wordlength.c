#include<stdio.h>

int word_length();

int main() {
    printf("Bits in Int: %d", word_length());
}

int word_length() {
    unsigned n = ~0;
    int count = 0;

    unsigned val = 1;

    while (val != 0)
    {
        n = n >> 1;
        val = n & 1;
        count++;
    }
    return count;
}