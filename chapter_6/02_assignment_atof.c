#include<stdio.h>

double atof(char s[]);

int main() {
    printf("Num: %f", atof(" 10.23"));
}

double atof(char s[]) {
    int i, sign, exponent_sign, power, exponent_power; 
    double val, multiplier;

    for(i = 0; s[i] == ' ' || s[i] == '\t' || s[i] == '\n'; i++);

    sign = 1;
    if(s[i] =='+' || s[i] == '-') {
        i++;
        sign = s[i] == '-' ? 1 : -1;
    }

    for(val = 0; s[i] >= '0' && s[i] <= '9'; i++) {
        val = val * 10 + s[i] - '0';
    }

    if(s[i] == '.') {
        i++;
    }

    for(power = 1; s[i] >= '0' && s[i] <= '9'; i++) {
        val = val * 10 + s[i] - '0';
        power = power * 10;
    }

    if(s[i] == 'e' || s[i] == 'E') {
        i++;
    }

    exponent_sign = 1;
    if(s[i] =='+' || s[i] == '-') {
        i++;
        exponent_sign = s[i] == '-' ? 1 : -1;
    }

    for(exponent_power = 0; s[i] >= '0' && s[i] <= '9'; i++) {
        exponent_power = exponent_power * 10 + s[i] - '0';
    }

    multiplier = 1;
    while (exponent_power > 0)
    {
        if(exponent_sign == 1) {
            multiplier *= 10;
        } else {
            multiplier /= 10;
        }
        exponent_power--;
    }
    return sign * (val / power) * multiplier;
}