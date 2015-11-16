#include <stdio.h>

int main (void)
{
	int base = 3;
	int exponent = 19;
	int result = 1;
	int i;

	for( i = 0; i < exponent; i++)
	{
		result = result * base;
	}
	printf("Results of base 3, exponent 19 is = %d\n", result);
}

