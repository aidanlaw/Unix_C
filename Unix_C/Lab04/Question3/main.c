
/*ARRAY OUTPUT*/

#include <stdio.h>
#include <stdlib.h>

# define LENGTH 5

int print(int array[], int length)
{
    int i;
    printf("The array is: \n\t{");
    for (i=0; i<length-1; i++)
    {
        printf("%3d,", array[i]);
    }
    printf("%3d}\n\n", array[length-1]);
    
    return 0;
}

int main(void)
{
    int array[LENGTH] = {4, 14, 5, 8, 2};
    print(array, LENGTH);
    
    return 0;
}