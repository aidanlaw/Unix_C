

#include <stdio.h>
#include <string.h>
#include "Settings.h"


void writeFile(int inputrow, char* inputArray[], char* inputName)
{
	int i;
	unsigned long str;
	FILE* write;
	str = 0;
	
	write = fopen(inputName, "w+");
	
	if(write == NULL)
	{
		perror("\n\t\tError opening file\n\n");
	}
	
	else
	{
		for( i = 0; i < inputrow; i++)
		{
			fprintf(write, "%s ", inputArray[i]);
		}
		
	}
	
	
}
