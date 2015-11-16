#include <stdio.h>


int main(void)
{
    int i, result = 0;
    for (i=1; i<5; i++) {
        result += cube(i);
    }
    printf("Result is: %d\n", result);
    return result;
}

int cube(int x)
{
    return x * x * x;
}