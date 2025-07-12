#include<stdio.h>

void itoh(int n, char s[]); // itob is integer to HEX representation
int get_size();

int main() {
    char hex[get_size()/4 + 1];
    itoh(-23566, hex);
    printf("Hex is %s", hex);
}

void itoh(int n, char s[]) {
    int hex_size = get_size() / 4;
    for(int i = 0; i < hex_size; i++) {
        int num = (n >> 4*i) & 15;        
        if(num >= 10) {
            s[hex_size -1 -i] = 'A' + num - 10;
            continue;
        }
        s[hex_size -1 -i] = '0' + num;
    }
    s[hex_size] = '\0';
}
/*
So i had a thought how HEX represents negative number because in decimal we have - sign
and in binary we can store then in 2s complement

So in a 8 bit system the largest and smallest number possible is -128 to 127
And we know hex represents 4 bit so 127 0111 1111 is 7F

AND -1 is 1111 1111 FF
and -128 1000 0000 is 80

See a pattern??
The range of HEX is 0 to 7F - 80 to FF

Where the first have represent positive numbers and the rest negative
But what represents the bondary??

Well if you notice the left most bit is the sign
0 for postive and 1 for negative so in 8bit system
and the first four bits in a positive number can at max be 0111 which is 7 in HEX
and for negative 1000 is 8

So by looking at any hex number you can immediately say if its positive or negative

SO COOL

Plus not you can quickly figure out decimal to hex and hex tot decimal

Q. -42 HEX?

42 is 0010 1010
its 2s compliment is 1101 0110
and this to Hex is just looking at 4 bits at a time
which is D6

and alternative is you know -1 is FF which is basically 15*16 + 15 = 255
so 255 -41 is 214 which you can now convert to hex

Q. A3F2 Binary?
Looking at it i know its negative
and in binary it looks like 1010 0011 1111 0010

its 2s compliment is 0101 1100 0000 1110
which in hex is 5C0D = 5*16^3 + 12*16^2 + 0 + 14 = 23,566

So A3F2 = -23,566
*/


int get_size() {
    int unsigned num = ~0;
    int i = 0;
    while(num != 0) {
        num = num >> 1;
        i++;
    }
    return i;
}