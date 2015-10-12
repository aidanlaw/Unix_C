
# include <stdio.h> /*required for the code to have any use where STDIO = "Standard Input Output"*/
# include <stdlib.h> /*required for malloc to function*/

# define LENGTH 5 /*sets the total length of the array to be used*/

/*
 First creat the sum, max, and reverse functions.
 Doing this before the "main" code removes the need for forward declarations
 */

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

/*the following "main" code is required to call upon the functions set above*/

int main(void)
{
    int i; /*declaring a variable for counting*/
    int sumReturn; /*create an integer variable to store the number which is the total sum of all integer inputs of the array*/
    int maxReturn; /*create an integer variable to store the column number where the highest integer value is located in the array*/
    
    int originalArray[LENGTH] = {3, 15, 6, 500, 9}; /*this is the original array which the above functions will use to process*/
    
    /*print the original array to the terminal*/
    printf("\nInput array: [ ");
    for(i=0; i<LENGTH-1; i++)
    {
        printf("%d, ", originalArray[i]); /*prints all values of the array with a trailing comma except for the final value which is printed later*/
    }
    printf("%d ]\n", originalArray[LENGTH-1]); /*prints the last value in the array and the ending square bracket "]" */
    
    /*call the functions for sum, max, and reverse*/
    sumReturn = sum(originalArray, LENGTH); /*calls the sum function and sends the name of the array and the amount of values stored in the array*/
    maxReturn = max(originalArray, LENGTH); /*calls the max function and sends the name of the array and the amount of values stored in the array*/
    reverse(originalArray, LENGTH); /*allows the reverse function to run which replaces the original array with an updated version*/
    
    /*print the sum and max to the terminal*/
    printf("Sum of values is: %d\n", sumReturn);
    printf("Location of maximum value is: %d\n", maxReturn);
    
    /*print the reversed array in the same way as the original as the originl has since been replaced*/
    printf("Original array in reverse order: [ ");
    for(i=0; i<LENGTH-1; i++)
    {
        printf("%d, ", originalArray[i]); /*prints all values of the array with a trailing comma except for the final value which is printed later*/
    }
    printf("%d ]\n\n", originalArray[LENGTH-1]); /*prints the last value in the array and the ending square bracket "]" */
    return 0;
}
