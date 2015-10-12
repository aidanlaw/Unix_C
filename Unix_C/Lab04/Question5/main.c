
/*MALLOC'D ARRAYS*/
/*
Same as question 4 but using malloc'd arrays instead of fixed arrays
 input in terminal must take the form of
 
 ./prog function numberOfInputs arrayinputs
 
 EXAMPLE
 
 ./prog sum 5 1 2 3 4 5
 
 where the first 5 designates the size of the array
 prints
 
 Sum of values is: 15
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int array[], int length)
{
    int i;
    int result = 0;
    
    for(i=0; i<length; i++)
    {
        result += array[i];

    }
    return result;
}

int max(int array[], int length)
{
    int i;
    int numValue = array[0];
    int maxpos = 0;
    
    for(i=0; i<length; i++)
    {
        if(numValue < array[i])
        {
            numValue = array[i];
            maxpos = i;
        }
       
    }
    return maxpos;
}

int reverse(int array[], int length)
{
    int i;
    int *tempArray = (int*)malloc(length * sizeof(int));

    for(i=0; i<length; i++)
    {
        tempArray[i] = array[i];
    }
    
    for(i=0; i<length; i++)
    {
        array[i] = tempArray[length-1-i];
    }
    return 0;
}


int main(int argc, char* argv[])
{
    int i;
    int sumResult = 0;
    int maxReturn = 0;
    int LENGTH = atoi(argv[2]);
    int *array;
    array = (int*)malloc((LENGTH) * sizeof(int)); /*creates the memory needed for the storage array*/
    
    if (argv[4] == NULL)
    {
        printf("No array integer input\n");
    }
    
    else
    {
        for (i=0; i<LENGTH; i++)
        {
            array[i] = atoi(argv[i+3]);
        }
        
        printf("The array is: \n\t{");
        for (i=0; i<LENGTH-1; i++)
        {
            printf("%3d,", array[i]);
        }
        printf("%3d}\n\n", array[LENGTH-1]);
        
        if (strcmp(argv[1], "sum") == 0)
        {
            sumResult = sum(array, LENGTH);
            printf("Sum of values is: %d\n", sumResult);
        }
        
        else if (strcmp(argv[1], "max") == 0)
        {
            maxReturn = max(array, LENGTH);
            printf("Location of maximum value is: %d\n", maxReturn);
        }
        
        else if (strcmp(argv[1], "reverse") == 0)
        {
            reverse(array, LENGTH);
            
            printf("Original array in reverse order: [ ");
            for(i=0; i<LENGTH-1; i++)
            {
                printf("%d, ", array[i]);
            }
            printf("%d ]\n\n", array[LENGTH-1]);
            
        }
        
        else
        {
            printf("Invalid argument was made\nLooking for the following inputs\n\tsum\n\tmax\n\treverse\n\n");
        }
    }
    free(array); /*required to free the memory bits after malloc was used and the program is complete*/
    return 0;
}
