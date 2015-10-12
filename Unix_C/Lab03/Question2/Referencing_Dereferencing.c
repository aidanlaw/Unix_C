//
//  main.c
//  Question2
//
//  Created by Aidan Law on 26/08/2015.
//
//

// Likely to be in test


//  Say we have these declarations
int a = 2;
int b = 10;
int* x = NULL;
int* y = NULL;
int** s = NULL;
int** t = NULL;

// What are the values of a and b after each of the folowing

//  (a)
x = &a;
*x = b;
//x points to a
//x is dereferencing b

// (b) ￼
s = &x;
x = &a;
y = &b;
t = s;
**t = **t * *y;
// value of s = address of x, so s points to x
// value of x = address of a, so x points to a
// value of y = address of b
// value of t = value of s, so t points to x
//
// if x address is 1000, s value is 1000
// dereference t and for each *, follow the next pointer

//  (c) ￼
int i;
x = &a;
y = &b;
for(i = 1; i <= *x; i++)
{
    *y = *y * 2;
}

/* 
    declare int called i
    value of x = address of a
    value of y = address of b
    start for loop 
    while i is less than or equal to 2, dereference x and follow down one pointer
 
 */
//  (d) ￼
x = &b; y = &a; t = &y; *t = x;
if(**t > 5) {
    s = t;
}
else {
    s = &x; }
**s = **s / *x;

// (e) ￼
x = (int*)malloc(sizeof(int));
y = (int*)malloc(sizeof(int));
*x = 8;

/*
 malloc is allocate memory
 allocate new memory for x specifically
 has initialised a new address memory slot
 x points to address with 8 stored inside
 y points to address with 8 stored inside
 
 if deref x is equal to deref y
    b becomes the deref of y (where y points to the 8)
 

*/