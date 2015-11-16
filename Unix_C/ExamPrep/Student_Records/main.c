
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

/*Get the basics out of the way first*/
#include <stdio.h>
#include <stdlib.h>

#ifndef DEBUG
#define DEBUG 0
#endif

/*This is the start of the actual answers*/
/*BEGIN QUESTION1*/
/*A*/
typedef struct {
	char code[4];
	float mark;
} Unit;

/*B*/
typedef struct {
	Unit *unitList;
	int nUnits;
	char studFirstName[51];
	char studLastName[51];
} Student;

/*C*/
typedef struct {
	Student* students;
	int nStudents;
} fullRecord;
/*END QUESTION 1*/

/*BEGIN QUESTION 2*/
/*	Write a function called loadRecords to read in student records from a text file.
	See Text.txt for the layout of the records to be read in.
*/
fullRecord* loadRecords(char* filename)
{
	int i, j;
	fullRecord* retval;
	FILE* file;
	i = j = 0;
	retval = NULL;
	file = fopen(filename, "r");
	
	if(file != NULL)
	{
		retval = (fullRecord*)malloc(sizeof(fullRecord));
		fscanf(file, "%d", &retval->nStudents);
		retval->students = (Student*)malloc((retval->nStudents) * sizeof(Student));
		if(DEBUG == 1)
		{
			printf("\tNumber of Students: %d\n", retval->nStudents);
			printf("\t--Student records list shown below--\n");
		}
		
		for (i=0; i<retval->nStudents; i++)
		{
			Student* s = &retval->students[i];
			fscanf(file, "%d", &s->nUnits);
			fscanf(file, "%s", s->studFirstName);
			fscanf(file, "%s", s->studLastName);
			s->unitList = (Unit*)malloc(s->nUnits*sizeof(Unit));
			if (DEBUG == 1)
			{
				printf("\n\t  Student#: %d\n", i+1);
				printf("\t     Units: %d\n", s->nUnits);
				printf("\t      Name: %s %s\n", s->studFirstName, s->studLastName);
			}
			
			for (j=0; j<(s->nUnits); j++)
			{
				Unit *u = &s->unitList[j];
				fscanf(file, "%3s %f", u->code, &u->mark);
				if (DEBUG == 1)
				{
					printf("\t Unit Code: %s", u->code);
					printf("\t\t   Mark: %3.1f\n", u->mark);
				}
			}
		}
	}
	else
	{
		printf("\n\tERROR: THE FILE \"%s\" NOT FOUND\n\n", filename);
	}
	
	fclose(file);
	return retval;
}
/*END QUESTION 2*/

/*BEGIN QUESTION 3*/
void calculateCWA(Student* s)
{
	int i;
	float cwa;
	cwa = 0.0;
	printf("\t%s ", s->studFirstName);
	printf("%s:", s->studLastName);
	for (i=0; i<s->nUnits; i++)
	{
		cwa += s->unitList[i].mark;
	}
	cwa /= s->nUnits;
	printf("\t%3.1f\n", cwa);
}
/*END QUESTION 3*/

/*BEGIN QUESTION 4*/
void processStudents(void (*funcPtr)(Student*), fullRecord* retval)
{
	int i;
	i = 0;
	printf("\n\t--Course Weighted Averages--\n");
	for (i=0; i<retval->nStudents; i++)
	{
		(*funcPtr)(&retval->students[i]);
	}
	printf("\n");
	
}
/*END QUESTION 4*/

/*BEGIN QUESTION 5*/
int main(int argc, char* argv[])
{
	int i;
	char* filename;
	fullRecord* record;
	
	filename = NULL;
	filename = argv[1];
	if(DEBUG == 1)
		printf("\n\tFilename: %s\n", filename);
	record = loadRecords(filename);
	if(record != NULL)
	{
		void (*funcPtr)(Student*);
		funcPtr = &calculateCWA;
		processStudents(funcPtr, record);
		
		/*Following not asked for in question but is necessary code*/
		for (i=0; i>record->nStudents; i++)
		 {
			free(record->students[0].unitList);
			free(record->students[1].unitList);
		 }
		free(&record->students);
	}
}
/*END QUESTION 5*/




