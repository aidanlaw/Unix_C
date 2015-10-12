/*
//
//  Practical1
//
//  Created by Aidan Law on 19/08/2015.
//
//
*/

#include <stdio.h>
#include <unistd.h> /*required for sleep function*/

int power();   /*Forward declaration is needed, similar to a table of contents*/

int main(void)
{
    int input;
    
    printf("This program calculates the powers of two each time the function is called\n");
    printf("Input the amount of rows you want as an output: ");
    
    scanf("%d\n", &input);
    
    int i;
    for (i=0; i<=input; i++)
    {
        printf("%d\n", power(input));
    }
    
    /*while (1)
    {
    printf("%ld\n",power());
        sleep(1);
    }*/
    
    return 0;
}

int power(void)
{
    static int result = 1;
    result *= 2;
    return result;
}