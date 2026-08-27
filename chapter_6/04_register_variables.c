#include <stdio.h>

int main() {
    int compute;
    register int iter; // The assembly generated with out without register is the same

    for(iter = 0; iter < 1000; iter++) {
        compute = (compute * 22) / 7;

        if(compute > 1000) {
            compute = compute % 1000;
        }
    }
    printf("%d", compute);
}
