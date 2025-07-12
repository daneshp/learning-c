#include<stdio.h>

#define MAXLENGTH 1000

void itoa(int n, char s[]); // itoa is integer to ASCII
void reverse(char s[]);
int py_len(char s[]);

int main() {
    char s[MAXLENGTH];
    itoa(-1256, s);
    printf("String %s", s);

}

void itoa(int n, char s[]) {
    
    int i = 0;
    int is_positive = 0;
    if(n < 0) {
        is_positive = 1;
    }

    if(is_positive == 0) {
        do {
            s[i++] = n % 10 + '0';
        } while ((n /= 10) > 0);
    }

    if(is_positive == 1) {
        do {
            s[i++] = -1 * (n%10) + '0'; /*
                Something cool % works differently in python and C
                in python division is floor division where it rounds towards negative infinity so the remainder is always positive
                while in c it rounds towards 0 so the remainder is always negative

                C: -7 % 3 = -1
                Python: -7 % 3 = 2
                
                WHY??
                no clue but there are so many ways to do modulo its insane
                https://en.wikipedia.org/wiki/Modulo#In_programming_languages
                
            */ 
        } while ((n /= 10) < 0);
        s[i++] = '-';
    }
    s[i++] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    char temp;
    int length = py_len(s) - 1;

    for(int i = 0; i <= length / 2; i++) {
        temp = s[length - i];
        s[length - i] = s[i];
        s[i] = temp;
    }
}

int py_len(char s[]) {
    int i;
    for(i = 0; s[i]; i++);
    return i;
}

// So in signed integers we all know 1 bit is kept for the sign
// so in a simple 3 bit system you can only represent numbers -4 to 3
// unlike unsigned which is 8

// So if the input to the itoa func is -4 if the code make it a positive number to fnd the 
// string value itll overflow

// But whats more intresting is how negative numbers are represented
// There are 3 ways
// For the number 3 - 0011
// In signed magnitude -3 is 1011 
// In ones compliment -3 is 1100 flip all the bits
// in twos compliment -3 is 1101 flip all the bits and add one

// 2s compliment is the most popular because:

// 1. Its the only one with 1 represnetation of 0
//      So in signed bits 0000 and 1000 are both zero
//      and in ones compliment 0000 1111 are also zero
//      but in 2s 0000 and is complement 1111 + 1 is 0000

// 2. Calculations is simpler

// Lets take and example 3 + -1
// in Signed Magnitude
//  0011
// +1001
//  ----
//  1100 = -4

// in 1s compliment (3 + -1)
//  0011
// +1110
//  ----
//  0001 plus one bit carry
// So in 1s to get the right answer we need to add the carried bit back to
// 0001 + 1 = 0010 which is called end-arround carry

// in 2s compliment
//  0011
// +1111
//  ----
//  0010 = -2 even here we have a carry bit but in 2s we can discard all carries

// 3. Storing 4bit numbers in a 8bit register is much easier
//      For 2s compliment number we just need to know the most significant bit and diplicate it
//      1101 -> 1111 1101
//      For signed magnitude well would need to shift
//      1011 -> 1000 0011

// 4. You can represent more numbers in 2s
//      So all the possible numbers in 4bits is 2^4 = 16
//      But in 1s compliment 0 usses 2 representations so it can show only 15 -7 to +7
//      While in 2s we can show all 16 but what is the last outlier - 1000
//      and what is 1000??
//      -7 is 1001 and adding 1000 + 0001 gives us -7 so 1000 is -8
//      So in 2s our range is -2^n to 2^n-1 (-8 to 7)