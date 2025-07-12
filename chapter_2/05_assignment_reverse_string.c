#include <stdio.h>
#include <string.h>

int py_len(char string[]);

int main() {
    char input[100];
    int string_length;
    int loop_till;

    printf("Enter string to reverse: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;

    string_length = py_len(input);

    printf("Length %d\n", string_length);

    if(string_length%2 == 0) {
        loop_till = string_length/2;
    }
    else {
        loop_till = (string_length - 1)/2;
    } // THIS IS UNNECESARY JUST I < J WILL WORK OUT

    int i;
    int j = string_length - 1;
    for(i = 0;i<loop_till;i++) {
        char temp;
        temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        j = j-1;
    }
    printf("Reversed string: %s", input);

}

int py_len(char string[]) {
    int i;
    for(i=0; string[i];i++);
    return i;
}
