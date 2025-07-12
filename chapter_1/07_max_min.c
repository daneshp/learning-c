#include <stdio.h>

int main() {
    int val, maxValue, minValue;
    
    while(scanf("%d", &val) != EOF) {
        
        if(val > maxValue) {
            maxValue = val;
        }

        if(val < maxValue) {
            minValue = val;
        }
    }

    printf("Max Value %d\n", maxValue);
    printf("Min Value %d\n", minValue);
}