//
//  Question1a
//  Conditions
//
//  Created by Aidan Law on 11/08/2015.
//

#include <stdio.h>                  //required for input and output
int main(void)
{
    int number;                     //set variable "number" as an integer
    scanf("%d", &number);           //wait for user input and saves input as "number"
    
    if(number < 0 || number > 10)   //if number less than 0 or greater than 10...
        printf("Out of range\n");   //output text and begin a new line
    
    else if(number != 5)            //if number is not equal to 5...
        printf("Wrong\n");          //output text and begin a new line
    
    else                            //if previous statements are not fulfilled...
        printf("Correct\n");        //output text and begin a new line
    
    return 0;                       //end program
}