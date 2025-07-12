#include <stdio.h>

int some_var; //global
static int some_static_var; //static

int main() {
    int some_local_var; // local

    printf("Global: %d\n", some_var);
    printf("Static: %d\n", some_static_var);
    printf("local: %d\n", some_local_var);

    // Automatic variables are stored on the stack unlike global or static variables
    // Which are stored in the data segment
    // So because these variables are initialized before even calling main they are set to 0
    // But when a func is called space is allocated for variables on the stack
    // And the vairable references any garbage value that was there before it
    // It does not zero it for performance reasons
}