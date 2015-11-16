
#include <stdio.h>
#include "calc.h"

int main(void)
{
    double result;
    double input;
    
    printf("Enter a number to invoke the square function: ");
    scanf("%lf\n", &input);
    result = square(input);
    printf("Result is: %lf\n", result);
}
