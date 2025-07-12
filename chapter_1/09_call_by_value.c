#include <stdio.h>

// Function Prototype
int multiply(int a, int b);

int main() {   
    // In older versions of C (before C99) if you called a function
    // before declaring it the compiler assument implicit declaration
    // return int and taking unspecified arguments
    // int multiply();

    int retValue = multiply(6, 7);
    printf("Answer %d\n", retValue);
}

int multiply(int a, int b)
{
    int c = a*b;
    return c;
}