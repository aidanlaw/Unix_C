
/*COMMAND LINE ARGUMENTS*/

/*
 Requires multiple arguments when executing the program
 
 The first argument should be what you want done with the following numbers
 An input of "sum", "max", or "reverse" as the first argument will allow the functions to execute
 
 The following numbers will be inserted into an array to be analysed
 
 EXAMPLE EXECUTING CODE
 =====================
 ./program sum 1 2 3 4
 =====================
 
 would print the input array and the sum = 10

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 7

int sum(int array[], int length)
{
    int i;	/*declaring a variable for counting*/
    int result = 0; /*declaring a variable to store the sum of numbers and sets it to 0*/
    
    for(i=0; i<length; i++) /*creating a loop which is bounded to the length of the input array*/
    {
        result += array[i];
        /*
         Adds each recurring value in the array to the running total "result".
         Initially i=0, therefore array[0] would recall the first integer of the array.
         As "i" counts higher and higher, each array value would be added to the running total.
         This loop will continue until every value of the fixed size array is accounted for.
         */
    }
    return result; /*function returns a single integer value back to the main program*/
}

int max(int array[], int length)
{
    int i; /*declaring a variable for counting*/
    int numValue = array[0];
    int maxpos = 0; /*create variable to hold the placement column of the maximum number in the array*/
    
    for(i=0; i<length; i++) /*creating a loop which is bounded to the length of the input array*/
    {
        if(numValue < array[i]) /*compare the current maximum number of the array with the next number in the array*/
        {
            numValue = array[i]; /*changes the maximum known value if a larger integer is found*/
            maxpos = i; /*updates the known location of the largest integer of the array*/
        }
        /*NOTE: no "else" statement is required as nothing would change if the next value was not larger than the compare value*/
    }
    return maxpos; /*function returns the position of the maximum integer of the array back to the main program*/
}

int reverse(int array[], int length)
{
    int i; /*declaring a variable for counting*/
    int *tempArray = (int*)malloc(length * sizeof(int));
    /*
     Creates an array called "tempArray" using malloc (memory allocation)
     "sizeof(int)" suggests that we would like to allocate the necessary amount of memory bits for a single integer value to be stored.
     By multiplying "sizeof(int)" by a number we can say we would like a certain amount of memory allocated for this specific application.
     In the case above, we want to allocate the same amount of memory as there are integer values in the previously created array.
     So when length == 5, we allocate enough integer memory slots to store 5 values.
     This is a useful workaround in C89 when we don't know the exact size of an array required during the compilation process.
     */
    for(i=0; i<length; i++)
    {
        tempArray[i] = array[i]; /*copy the original array values into the temporary store location*/
    }
    
    for(i=0; i<length; i++)
    {
        array[i] = tempArray[length-1-i];
        /*
         Replaces the values in the original array with the reversed values in the temporary array.
         To recall each value in reverse we can utilise the "i" variable and work our way from the end value to the start value of the array.
         The variable "length" is used to give the amount of integers stored in the array.
         We use this to set the maximum position of the array and can subtract the "i" value with each loop.
         We must also subtract 1 from the position value as the length of the array does not take into account that the first position in the array is [0].
         So in an array of length == 5, the positions of the array would be [0, 1, 2, 3, 4] and we must subtract the 1 to recall the value in the 5th position.
         */
    }
    /*there is no need to return anything to the main program as the original array was updated with the new values*/
    return 0;
}












int main(int argc, char* argv[])
{
    int i;
    int array[LENGTH];
    int sumReturn;
    int maxReturn;
    
    if (argv[3] == NULL) /*checking if there are two or more arguments*/
    {
        printf("No second integer input\n");
    }
    
    else
    {
        for (i=2; i<LENGTH; i++)
        {
            array[i-2] = atoi(argv[i]); /*convert strings input from the terminal at runtime into integers*/
        }
        
        printf("The array is: \n\t{");
        for (i=0; i<LENGTH-3; i++)
        {
            printf("%3d,", array[i]);
        }
        printf("%3d}\n\n", array[LENGTH-3]);
        
        if (strcmp(argv[1], "sum") == 0)
        {
            sumReturn = sum(array, LENGTH-2);
            printf("Sum of values is: %d\n", sumReturn);
        }
        
        else if (strcmp(argv[1], "max") == 0)
        {
            maxReturn = max(array, LENGTH-2);
            printf("Location of maximum value is: %d\n", maxReturn);
        }
        
        else if (strcmp(argv[1], "reverse") == 0)
        {
            reverse(array, LENGTH-2);
            
            printf("Original array in reverse order: [ ");
            for(i=0; i<LENGTH-3; i++)
            {
                printf("%d, ", array[i]); /*prints all values of the array with a trailing comma except for the final value which is printed later*/
            }
            printf("%d ]\n\n", array[LENGTH-3]); /*prints the last value in the array and the ending square bracket "]" */

        }

        else /*run this if enough arguments*/
        {
            printf("Invalid argument was made\nLooking for the following inputs\n\tsum\n\tmax\n\treverse\n\n");
        }
    }
    
    return 0;
}
