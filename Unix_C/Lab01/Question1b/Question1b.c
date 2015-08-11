//
//
//  Question1b
//  Loops
//
//  Created by Aidan Law on 11/08/2015.
//
//

/*
 
 The following program takes an integer input from the user and displays every whole number from 0 to the number chosen.
 
 How could you replace the While loop in the following?
 
 #include <stdio.h>
 int main(void)
 {
    int count, i;
    scanf("%d", &count);
    i = 0;
    while(i < count)
    {
        printf("%d ", i);
        i++;
    }
    ￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼return 0;
 }
*/

#include <stdio.h>          //needed for standard input and output
int main(void)
{
    int count, i;           //create variables of type integer
    scanf("%d", &count);    //store user input as an integer into "count"
    
    for (i=0; i<count; i++) //for loop where "i" increments by 1 with every loop until variable "i" is equal to "count"
    {
        printf("%d ", i);   //displays the variable "i"
    }
    return 0;               //end of program
}