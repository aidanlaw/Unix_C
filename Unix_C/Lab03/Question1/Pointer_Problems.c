//
//  main.c
//  Question1
//
//  Created by Aidan Law on 26/08/2015.
//
//

//There is an error in the following. What is it?

//  a)
    int value = NULL;
// cannot set to NULL

//  b)
    int* pointer;
    pointer = 42;
// setting location to point to address 42

//  c)
    int* pointer;
    *pointer = 42;
// no way of checking to see if another program has used this address for storage

//  d)
char ch;
char** pointer;
pointer = &ch;
// trying to put a pointer into a double pointer

//  e)
double value = 42.0;
void* pointer = (void*)&value;
*pointer = 84.0;
// cannot follow the address if it has no idea whatis on the otherside

//  f)
void (*pointer)(int, int);
(
// function pointer that takes two ints and returns nothing
// similar to c) where it doesn't now what it is pointing to

//  g)

// the function itself does not return anything of value
