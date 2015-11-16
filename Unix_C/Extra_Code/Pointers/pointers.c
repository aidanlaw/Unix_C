#include <stdio.h>



int main (void)
{
    float **white;
    float **blue;
    float *purple;
    float *yellow;
    float *orange;
    float green = 10.0;
    float red = 20.0;
    
purple = &red;
orange = &green;
yellow = purple;
blue = &yellow;
white = &orange;
purple = *white;
*white = yellow;
*purple = *yellow + **blue;
**white += *orange;

printf("%f\n", *purple);
printf("%f\n", **white);
}