//
//  Question1
//
//  Created by Aidan Law on 14/08/2015.
//
//

// Prelab

// 1. Preprocessor Directives
// explain the effect of the following

#include <Marvellous.h> 
// Includes a standard header file like math.h

#include "marvellous.h"
// Includes a header file that is in the current directory that was created by the user

#define LENGTH 100
// Every time LENGTH is in the code, it is replaced with 100

#define CUBE(x) ((x) * (x) * (x))
// Every time CUBE(x) is in the code (where x is a number), the function that follows is used to find the cube

#define CALC(x,y,z) ((x) + CUBE(y) + CUBE(CUBE(z)))
// Same as above except it includes the numbers for x, y, and z

#ifdef LENGTH
    printf("%d", LENGTH);
#endif
// If LENGTH has been previously defined, then it will print the LENGTH tp terminal

#ifndef THEFILE
#define THEFILE
void f(void)
{
    printf("Hello world\n");
}
#endif
// if THEFILE hasn't been defined, then it defines it and performs the function