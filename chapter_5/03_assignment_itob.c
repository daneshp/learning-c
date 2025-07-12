#include<stdio.h>

void itob(int n, char s[]); // itob is integer to Binary representation
int get_size();

int main() {
    char binary[get_size() + 1];
    itob(356, binary);
    printf("Binary is %s", binary);
}

void itob(int n, char s[]) {
    int int_size = get_size();
    for(int i = 0; i < int_size; i++ ) {
        if(((n >> i) & 1) == 1) {
            s[int_size - 1 - i] = '1';
            continue;
        }
        s[int_size - 1 - i] = '0';
    }
    s[int_size] = '\0';
}

int get_size() {
    int unsigned num = ~0;
    int i = 0;
    while(num != 0) {
        num = num >> 1;
        i++;
    }
    return i;
}