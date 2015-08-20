//
//  Practical1
//
//  Created by Aidan Law on 19/08/2015.
//
//

#include <stdio.h>
#include <unistd.h>

unsigned long int power();   //Forward declaration is needed, similar to a table of contents

int main(void)
{
    int input;
    
    printf("This program calculates the powers of two each time the function is called\n");
    printf("Input the amount of numbers you want as an output\n");
    
    scanf("%d", input);
    
    int i;
    for (i=0; i<=input; i++)
    {
        printf("%ld\n",power());
    }
    
    /*while (1)
    {
    printf("%ld\n",power());
        sleep(1);
    }*/
    
    return 0;
}

unsigned long int power(void)
{
    static unsigned long int result = 1;
    result *= 2;
    return result;
}