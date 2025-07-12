#include<stdio.h>

#define MAXLENGTH 1000

int r_index(char s[], char sub_string[]);

int main() {
    int i = 0;

    char input[MAXLENGTH];
    char c; 

    while((c = getchar()) != EOF) {
        input[i++] = c;
    }
    input[i++] = '\0';

    printf("Position is %d", r_index(input, "the"));
}

int r_index(char s[], char sub_string[]) { // In C79 functions didnt need to declare a return type and it was assumend to be int which works for char and many other types
    int index = -1;

    for(int i = 0; s[i]; i++) {
        
        int j , k;
        for(j = 0, k = i;sub_string[j] != '\0' && s[k] == sub_string[j]; j++, k++);

        if(sub_string[j] == '\0') {
            index = i;
        }
    }
    return index;
}