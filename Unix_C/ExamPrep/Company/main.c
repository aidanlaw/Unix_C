
/*ComSSA Help Session*/
/*Question 7*/
/*FILE IO*/
/*	This section requires:
 1. Write suitable C datatypes/data structures representing various pieces of information
 2. Write a function that reads files into these datatype/data structures
 3. Write a function that calculates values from the data structures
 4. Write main function that will call the above functions and output/write the results to a file
 
	You may refer to the following C function prototypes:
 1. FILE *fopen(const char *path, const char *mode);
 2. int fclose(FILE *fp);
 3. int fscanf(FILE *stream, const char *format, ...);
 4. char *fgets(char *s, int size, FILE *stream);
 5. int feof(FILE *stream);
 6. int strcmp(const char *s1, const char *s2);
 7. char *strcpy(char *dest, const char *src);
 */

/*	Nested structs need to be freed more efficiently.
	Here is the code for freeing so far.
 
		 for (i=0; i<reg->nCore+reg->nAss; i++)
		 {
			free(&reg->com[i]);
		 }
		free(reg);
*/
/*Get the basics out of the way first*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define FALSE 0
#define TRUE !FALSE

#ifndef DEBUG
#define DEBUG FALSE
#endif



/*This is the start of the actual answers*/
/*BEGIN QUESTION 1*/
typedef struct {
	char code[4];
	float price;
	int nShares;
	double value;
	double debt;
} Company;

typedef struct {
	Company* com;
	int nCore;
	int nAss;
} Register;
/*END QUESTION 1*/

/*BEGIN QUESTION 2*/
Register* readConsortium(char* filename)
{
	int i,count;
	Register* retval;
	FILE* file;
	retval = NULL;
	count = 0;
	file = fopen(filename, "r");
	if(file != NULL)
	{
		retval = (Register*)malloc(sizeof(Register));
		retval->com = (Company*)malloc(sizeof(Company));
		fscanf(file, "%d", &retval->nCore);
		fscanf(file, "%d", &retval->nAss);
		count = retval->nCore + retval->nAss;
		if(DEBUG == TRUE)
		{
			printf("\n\tCore#: %d\n", retval->nCore);
			printf("\tAssociate#: %d\n", retval->nAss);
		}
		for (i=0; i<count; i++)
		{
			Company* c = &retval->com[i];
			fscanf(file, "%s", c->code);
			fscanf(file, "%f", &c->price);
			fscanf(file, "%d", &c->nShares);
			fscanf(file, "%lf", &c->value);
			fscanf(file, "%lf", &c->debt);
			if(DEBUG == TRUE)
			{
				printf("\n\t   Code: \t%s\n", c->code);
				printf("\t  Price: \t%.2f\n", c->price);
				printf("\t#Shares: \t%d\n", c->nShares);
				printf("\t  Value: \t%.2lf\n", c->value);
				printf("\t   Debt: \t%.2lf\n", c->debt);
			}
		}
	}
	fclose(file);
	file = NULL;
	return retval;
}

/*END QUESTION 2*/

/*BEGIN QUESTION 3*/
void writeNetWorth(char* outputname, Register* reg)
{
	int i;
	double netWorth;
	FILE* write;
	netWorth = 0.0;
	write = NULL;
	write = fopen(outputname, "w+");
	if(write != NULL)
	{
		for( i = 0; i < reg->nAss+reg->nCore; i++)
		{
			netWorth = (reg->com[i].price * reg->com[i].nShares) + reg->com[i].value - reg->com[i].debt;
			fprintf(write, "%s:%12.2lf\n", reg->com[i].code, netWorth);
			netWorth = 0.0;
		}
	}
	else
	{
		perror("\n\t--ERROR CREATING WRITE FILE--\n\n");
	}
	fclose(write);
	write = NULL;
}
/*END QUESTION 3*/

/*BEGIN QUESTION 4*/

int main(int argc, char* argv[])
{
	char* inputname;
	char* outputname;
	int i,j;
	Register* reg;
	reg = NULL;
	i=j=0;
	inputname = NULL;
	inputname = argv[1];
	outputname = argv[2];
	if(DEBUG == TRUE)
	{
		printf("\n\tInput Name: %s\n", inputname);
		printf("\tOutput Name: %s\n", outputname);
	}
	reg = readConsortium(inputname);
	writeNetWorth(outputname, reg);
	free(&reg->com);
	printf("\n");
}

/*END QUESTION 4*/

/*BEGIN QUESTION 5*/
/*
int main(int argc, char* argv[])
{
	char* inputname;
	char outputname[51];
	int i,j;
	Register* reg;
	reg = NULL;
	i=j=0;
	inputname = NULL;
	inputname = argv[1];
	strcpy(outputname, argv[1]);
	strcat(outputname, ".out");
	if(DEBUG == TRUE)
	{
		printf("\n\tInput Name: %s\n", inputname);
		printf("\tOutput Name: %s\n", outputname);
	}
	reg = readConsortium(inputname);
	writeNetWorth(outputname, reg);

	free(&reg->com);
	printf("\n");
}
 */
/*END QUESTION 5*/






























