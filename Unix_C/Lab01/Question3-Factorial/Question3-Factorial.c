//
//  Question3-Factorial
//
//  Stolen by Aidan Law on 12/08/2015.
//
//

#include <stdio.h>

unsigned long int factorial(int);

int main(void)
{
    int input;
    
    printf("Input a number to calculate the corresponding factorial\n");
    scanf("%d", &input);
    
    if (input<0) {
        printf("The number entered is not within the range\n");
    }
    else if (input>=0){
    printf("%d! = %ld\n", input, factorial(input));
    }
    
    return 0;
}

unsigned long int factorial(int n)
{
    int count;
    unsigned long int result = 1;
    
    for (count = 1; count <= n; count++)
        result = result * count;
    
    return result;
}