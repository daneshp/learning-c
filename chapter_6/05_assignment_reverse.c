#include <stdio.h>

int get_len(char str[]);
void reverse(char str[]);
void reverse_range(char str[], int p, int length);

int main() {
    printf("tp");
    char input[] = "My name is Danesh";
    reverse(input);
    printf("Reversed str: %s", input);
}


void reverse(char str[]) {
    printf("test");
    int length = get_len(str);
    printf("Len %d", length);
    reverse_range(str, 0, length);
}

void reverse_range(char str[], int p, int length) {
    if(p >= length / 2) {
        return;
    }
    char temp = str[p];
    str[p] = str[length - p - 1];
    str[length - p - 1] = temp;

    reverse_range(str, ++p, length);
}

int get_len(char str[]) {
    int i = 0;
    while(str[i] != '\0') {
        i++;
    }
    return i;
}
