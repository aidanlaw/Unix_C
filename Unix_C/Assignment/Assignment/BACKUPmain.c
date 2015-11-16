
/*
 This program is a function to perform a spell check on a user input file and possibly autocorrect the words.
 
 Author:		Aidan David Law
 Student ID:	17426855
 Unit:			Unix and C Programming (COMP1000)
 Institution:	Curtin University
 
 Required Files:
 Makefile
 main.c
 Settings.h
 settingsPrint.c
 dictionary.c
 dictionary.h
 <user input file>
 spellrc
 <dictionary word list>
 
 Required File Notes:
	Makefile:
 run "make" in terminal to only compile the necessary code.
 run "make debug" in terminal to print out each completed section.
 run "make clean" to remove all the .o files and the program.
 
	spellrc:
 "spellrc" defines the following parameters:
 =====================================
 dictionary = <filename and extension>
 maxcorrection = <integer>
 autocorrect = <yes or no>
 =====================================
 Example entries can be:
 =====================================
 dictionary = testDict.txt
 maxcorrection = 2
 autocorrect = no
 =====================================
 It is possible to have multiple entries of each type as long as they are on separate lines.
 The program will read in the last known settings of each type from the "spellrc" file.
 
	<user input file>
 Must be read in when the program is executed:
 ================
 ./prog input.txt
 ================
 Must only be strings seperated by whitespace.
 Each string is compared with an entry in the dictionary set by the "spellrc" file.
 
 
 Curtin University
 
 Written by Aidan Law
 
 */

#include <stdio.h> /*required for standard inputs and outputs*/
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "Settings.h"
#include "dictionary.h"

#define FALSE 0
#define TRUE !FALSE





int main(int argc, char* argv[]) /*allows the main function to intake arguments when executing the program*/
{
	/*declare variables used in the main function here*/
	char spellrcLine[51];
	char typeRead[51];
	int typeReadnum = 0;
	char autocorrectChoice[4];
	int maxCorrectionChoice;
	unsigned int row;
	unsigned int completeDictLength;
	char** dictArray;
	
	
	/*create a file and struct pointer and open the settings file to the file pointer*/
	FILE* spellrc;
	Settings* set;
	Directory *DictionaryList;
	Dict *current;
	spellrc = fopen("spellrc", "r");
	
	/*allocate memory to the settings struct and fields*/
	set = (Settings*)malloc(sizeof(Settings));
	set->autocorrect = (char*)malloc(sizeof(char)*51);
	set->dictionaryName = (char*)malloc(sizeof(char)*51);
	
	/*check to see if spellrc exists*/
	if (spellrc == NULL)
	{
		printf("Filename %s does not exist int the current folder.\n", argv[1]);
	}
	
	/*
	 If spellrc exists, do the following:
	 Scan the initial string and save it to spellrcLine
	 Compare the string with required text inputs
	 Scan the expression on the same line to a variable
	 Save the expression into the struct
	 
	 While loop will repeat until there is no more lines
	 New inputs will overwrite old inputs
	 */
	else
	{
		while(fscanf(spellrc, "%s = ", spellrcLine) >0)
		{
			if ((strcmp(spellrcLine, "maxcorrection") == 0))
			{
				fscanf( spellrc, "%d\n", &typeReadnum);
				set->maxCorrection = typeReadnum;
			}
			else if ((strcmp(spellrcLine, "autocorrect") == 0))
			{
				fscanf( spellrc, "%s\n", typeRead);
				strcpy(set->autocorrect, typeRead);
				
			}
			else if ((strcmp(spellrcLine, "dictionary") == 0))
			{
				fscanf( spellrc, "%s\n", typeRead);
				strcpy(set->dictionaryName, typeRead);
			}
			else
			{
				printf("\n\n\tEntry in the settings file is not:\n");
				printf("\t\tautocorrect\n\t\tmaxcorrection\n\t\tdictionary\n\n");
			}
		}
		/*close the settings file and free the memory*/
		fclose(spellrc);
		
		
		/*only does the following when <make debug> is run in terminal and
		 prints out information that was useful during testing*/
		if(DEBUG == 1)
		{
			/*calls a function in settingsPrint.c which prints out the settings file in a crudely made table*/
			printSettings(set);
		}
		
		/*save settings struct to variables to make it easier to call later*/
		maxCorrectionChoice = set->maxCorrection;
		strcpy(autocorrectChoice, set->autocorrect);
		/*check to see if inputs were saved*/
		if(DEBUG == 1)
		{
			printf("\n\tMax Correction Saved: %d\n\tAutocorrect Option: %s\n", maxCorrectionChoice, autocorrectChoice);
		}
		
		
		
		
		DictionaryList = NULL;
		current = NULL;
		
		DictionaryList = (Directory*)malloc(sizeof(Directory));
		DictionaryList->head = NULL;
		DictionaryList->tail = NULL;
		DictionaryList->listCount = 0;
		
		/*
		 The following sends the name of the dictionary file into an external
		 function located in "dictionary.c" which saves each line of the
		 dictionary and places the words into a linked list
		 */
		
		
		dictArray = NULL;
		row = 0;
		completeDictLength = 0;
		
		dictionaryRead(set->dictionaryName, &row, &completeDictLength, DictionaryList, current);
		
		dictArray = (char**)malloc(sizeof(char*)*(completeDictLength));
		arrayCaller(&row, DictionaryList, current, dictArray);
		
		if(DEBUG == 1)
		{
			printf("\n\tRow Number max chosen to print is: %d\n", row);
			printf("\n\tDict Length entry chosen to print is: %d\n", completeDictLength);
			printf("\n\tArray entry chosen to print is: %p %s\n", &dictArray[0], dictArray[0]);
			printf("\n\tArray entry chosen to print is: %p %s\n", &dictArray[row-1], dictArray[row-1]);
		}
		
		/*call function to free the 2D array*/
		freeArrayFixed(row, dictArray);
		if(DEBUG ==1)
		{
			printf("\n\tArray is Free\n");
			printf("\n\tDictionary Array Freed Succesfully\n");
		}
		
	}
	free(set->dictionaryName);
	set->dictionaryName = NULL;
	free(set->autocorrect);
	set->autocorrect = NULL;
	free(set);
	set = NULL;
	if(DEBUG == 1)
	{
		printf("\n\n\t=====================\n\t  Program Completed\n\t=====================\n\n");
	}
	
	
	return 0;
}
