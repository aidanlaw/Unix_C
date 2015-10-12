
/* STRING CONVERSION */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>


# define LENGTH 5

int main (void)
{
    int i;
    int checkNum;
    int array[LENGTH];
    char* charArray[LENGTH] = {"7", "1", "14", "-5", "10"};
    
    /*loop for converting to integers*/
    for (i=0; i<LENGTH; i++)
    {
        array[i] = atoi(charArray[i]);
    }
    
    /*printing the integer array to terminal*/
    printf("\nInteger conversion of char array: [ ");
    for(i=0; i<LENGTH-1; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("%d ]\n", array[LENGTH-1]);
    
    checkNum = array[1] + array[2];
    printf("Sum of position 1 and 2 is: %d\n", checkNum);
    
    return 0;
}
