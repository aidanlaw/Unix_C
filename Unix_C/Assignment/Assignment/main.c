
/*
 This program is a function to perform a spell check on a user input file and possibly autocorrect the words.
 
 Author:		Aidan David Law
 Student ID:	17426855
 Unit:			Unix and C Programming (COMP1000)
 Institution:	Curtin University
 
 Required Files:
 Makefile					-for easy compiling
 main.c						-main function to call everything
 Settings.h					-Settings print stores the spellrc debugging print function
 settingsPrint.c			-actual debugging print function
 dictionary.c				-dictionary file read in with linked lists, arrays, and frees
 dictionary.h				-acts like forward declarations of the functions inside dictionary.c
 <user input file>			-document that will be checked for spelling
 spellrc					-settings of the autocorrect stored in here
 <dictionary word list>		-actaul dictionary list of words
 writeFile.c				-function for overwriting user file with corrections (if required)
 
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

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "Settings.h" /*for printing spellrc when debugging*/
#include "dictionary.h" /*for dictionary linked list, linked list free, array free, and array*/
#include "userInput.h" /*for user input file linked list and array functions*/
#include "check.h" /*did not touch this but required for correcting and checking words*/


/*Functions for the ACTIONFUNC Callback*/
/*autocorrect no function*/

/*
 when autocorrect is No the function is used.
 sees if there is a suggestion for correction
 if not then the function will state that it cannot do it
 if there is a suggestion the function allows the user to choose what to do
 (yes/no) is accepted
 */
int aNo(char* word, char* suggestion)
{
	int returned = 0;
	char option[4];
	
	
	if(suggestion == NULL)
	{
		printf("\n\tThe word \"%s\" could not be corrected\n", word);
		returned = FALSE;
	}
	
	else
	{
		printf("Enter (yes/no) if you would like to correct:\n\t\t%s to\n\t\t%s\n", word, suggestion);
		
		scanf("%s", option);
		
		if(strcmp(option, "yes") == 0)
		{
			returned = TRUE;
		}
		
		else if(strcmp(option, "no") == 0)
		{
			returned = FALSE;
		}
	}
	
	return returned;
}


/*autocorrect yes function*/
/*
 when autocorrect is Yees the function is used.
 sees if there is a suggestion for correction
 if not then the function will state that it cannot do it
 if there is a suggestion the function changes the word without user input
 */
int aYes(char* word, char* suggestion)
{
	int returned =0;
	if(suggestion == NULL)
	{
		printf("\n\tThe word \"%s\" could not be corrected\n", word);
		returned = FALSE;
	}
	else
	{
		returned = TRUE;
		printf("\n\tThe word \"%s\" had been autocorrected to \"%s\"\n", word, suggestion);
	}
	return returned;
}

/*====================================================================================*/
/*====================================================================================*/
/*====================================================================================*/
/*====================================================================================*/
/*====================================================================================*/
/*====================================================================================*/
/*====================================================================================*/
/*====================================================================================*/

int main(int argc, char* argv[]) /*allows the main function to intake arguments when executing the program*/
{
	/*declare variables used in the main function here*/
	char spellrcLine[51];
	char typeRead[51];
	int typeReadnum = 0;
	char autocorrectChoice[4];
	int maxCorrectionChoice;
	int row;
	int dictRow;
	char** dictArray;
	int inputrow;
	int inputrowa;
	char** inputArray;
	char InputName[LONGEST_WORD_LENGTH];
	
	
	
	/*create a file and struct pointer and open the settings file to the file pointer*/
	FILE* spellrc;
	Settings* set;
	Directory *DictionaryList;
	Dict *current;
	Directory *InputList;
	ActionFunc action;
	spellrc = fopen("spellrc", "r");
	
	/*allocate memory to the settings struct and fields*/
	set = (Settings*)malloc(sizeof(Settings));
	set->autocorrect = (char*)malloc(sizeof(char)*51);
	set->dictionaryName = (char*)malloc(sizeof(char)*51);
	
	/*check to see if spellrc exists*/
	if (spellrc == NULL)
	{
		printf("The file \"spellrc\" does not exist int the current folder.\n");
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
		
		

		/*
		 The following sends the name of the dictionary file into an external
		 function located in "dictionary.c" which saves each line of the
		 dictionary and places the words into a linked list
		 */
		DictionaryList = NULL;
		current = NULL;
		
		DictionaryList = (Directory*)malloc(sizeof(Directory));
		DictionaryList->head = NULL;
		DictionaryList->tail = NULL;
		DictionaryList->listCount = 0;
		
		dictArray = NULL;
		row = 0;
		
		/*
		 calls function to read in the values from a dictionary and put it into a linked list
		 */
		dictionaryRead(set->dictionaryName, &row, DictionaryList, current);
		
		dictArray = (char**)malloc((row)*sizeof(char*));
		dictRow = 0;
		/*
		 calls function to change a linked list into an array which also frees the linked list
		 returns the amount of array rows
		 */
		dictRow = arrayCaller(row, DictionaryList, current, dictArray);
		
		if(DEBUG == 1)
		{
			printf("\n\tRow Number max chosen to print is: %d\n", row);
		}
		
		/*
		 The following sends the name of the input file into an external
		 function located in "userInput.c" which saves each line of the
		 input file and places the words into a linked list
		 */
		InputList = NULL;
		
		InputList = (Directory*)malloc(sizeof(Directory));
		InputList->head = NULL;
		InputList->tail = NULL;
		InputList->listCount = 0;
		
		inputArray = NULL;
		inputrow = 0;
		inputrowa = 0;
		
		/*
		 save a copy of the input file name to be used later (and also for safe keeping)
		 */
		strcpy(InputName, argv[1]);
		
		/*
		 calls function to read in the values from a input file and put it into a linked list
		 */
		inputRead(InputName, &inputrow, InputList, current);
		
		inputArray = (char**)malloc(sizeof(char*)*(inputrow));
		/*
		 calls function to change a linked list into an array which also frees the linked list
		 returns the amount of array rows
		 */
		inputrowa = inputArrayCaller(inputrow, InputList, current, inputArray);

		
		if(DEBUG == 1)
		{
			printf("\n\tInput Row Number max chosen to print is: %d\n", inputrowa);
		}
		
		
		 /*Calling the Check Function*/
		if (strcmp(set->autocorrect, "yes") == 0)
		{
			action = &aYes;
			check(inputArray, inputrowa, dictArray, dictRow, maxCorrectionChoice, action);
		}
		else
		{
			action = &aNo;
			check(inputArray, inputrowa, dictArray, dictRow, maxCorrectionChoice, action);
		}

		writeFile( inputrow, inputArray, InputName);
		
		
		/*call function to free Dict the 2D array*/
		freeArrayFixed(row, dictArray);
		if(DEBUG ==1)
		{
			printf("\n\tDictionary Array is Free\n");
			printf("\n\tDictionary Array Freed Successfully\n");
		}
		/*call function to free the Input 2D array*/
		freeArrayFixed(inputrow, inputArray);
		if(DEBUG ==1)
		{
			printf("\n\tInput Array is Free\n");
			printf("\n\tInput Array Freed Successfully\n");
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
