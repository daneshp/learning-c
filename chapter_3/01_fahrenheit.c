#include <stdio.h>

#define LOWER 0 /* This whole line is directly substituted so semicolon is not required here */
#define UPPER 300
#define STEP 20

int main()
{
    int fahr = LOWER;
    float celcius;
    
    printf("Fahrenheit | Celcius\n");
    while (fahr <= UPPER)
    {
        celcius = (5.0 / 9.0) * (fahr - 32.0); // Since 5 and 9 are both int c performs integer division that way atleast one value must be 5.0 to get the accurate value
        printf("%10d | %4.4f \n", fahr, celcius); // .0d and .0f mean different things play
        fahr = fahr + STEP;
    }
}