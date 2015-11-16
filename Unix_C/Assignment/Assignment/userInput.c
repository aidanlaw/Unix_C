


#include "dictionary.h"
#include "Settings.h"
#include "userInput.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


int listToArrayDynamicInput(int inputrowa, Directory* InputList, Dict* inputcurrent, char** inputArray)
{
	/*
	 The following section takes each entry from the linked list created above and
	 transfers it to a dynamically allocated array. It is in my hopes that it will
	 function by count each single character of the word until it reaches the
	 "\n" (newline cahracter), and allocates the count as the amount of spaces
	 to allocate in that row of the array. The amount of array rows is designated
	 by the complete dictionary length stored in the head linked list struct. This
	 will not be a rectangular array but will instead be an array of a known amount
	 of rows with varying amounts of columns. This process should save on the amount
	 of memory needed to construct the array.
	 */
	/*create the variables required for entry from the linked list into the array*/
	int i;
	
	if(DEBUG ==1)
		printf("\n\tInput Array length to create: %d\n", InputList->listCount);
	
	inputcurrent = InputList->head;
	
	for(i = 0; i < inputrowa; i++)
	{
		inputArray[i] = (char*)malloc(sizeof(char)*(LONGEST_WORD_LENGTH));
		strcpy(inputArray[i], inputcurrent->string);
		inputcurrent = inputcurrent->next;
		
		if(DEBUG ==1)
			printf("\tInput Array [%06d]:\t%s\n", i, inputArray[i]);
	}
	
	if(DEBUG ==1)
	{
		printf("\n\tInput Array Entry 3 is: %s", inputArray[2]);
	}
	return i;
}



void inputRead( char* inputName, int* inputrow,
					Directory* InputList, Dict* current)
{
	/*allocate storage for words to stay temporarily before being transferred to the linked list
	 (like a cheap motel you stay at which is close to the airport so you don't have to waste money
	 on half a night in a nice hotel. You can put up with bars on the windows for the 6 hours you
	 will be there, but if you stay it would ruin the tropical holiday you looked forward to for
	 6 months as your monotonous job slowly eats away at your soul.)
	 */
	char inputTemp[LONGEST_WORD_LENGTH];
	
	
	/*create a file pointer and open the dictionary file set by the spellrc file*/
	FILE *inputFile;
	inputFile = fopen(inputName, "r");
	
	/*check if the dictionary file exists and has entries inside*/
	if(inputFile == NULL)
	{
		printf("The input file is empty\n");
	}
	
	/*
	 If the dictionary file specified by spellrc exists and has valid entries then the following will happen:
	 Create the head of the linked list as well as the first struct/list entry.
	 Allocate memory for the head file and set entries to NULL.
	 Scan the dictionary file
	 */
	else
	{
		while(fscanf(inputFile, "%s ", inputTemp) > 0)
		{
			current = (Dict*)malloc(sizeof(Dict));
			
			current->string = (char*)malloc(sizeof(char)*LONGEST_WORD_LENGTH);
			
			strcpy(current->string,inputTemp);
			InputList->listCount = InputList->listCount+1;
			
			if(DEBUG ==1)
				printf("\n\tInput Linked List Entry %06d:\t%s", InputList->listCount, current->string);
			
			if(InputList->head == NULL)
			{
				InputList->head = current;
				InputList->tail = current;
			}
			
			else
			{
				InputList->tail->next = current;
				InputList->tail = current;
			}
			
		}
		/*saves the length of the dictionary to a variable known by main to be called upon later*/
		*inputrow = InputList->listCount;
		if(DEBUG ==1)
		{
			printf("\n\tInput length is %d and %d\n", InputList->listCount, *inputrow);
		}
		
	}
	fclose(inputFile);
}


/*
 This function calls another function which produces the 2D array from the linked list.
 The link list is then freed as it is no longer required.
 This step was not necessary but it is how my mind imagined it at the time.
 */
int inputArrayCaller(int inputrow, Directory* InputList,
					  Dict* current, char** inputArray)
{
	int inputrowb;
	inputrowb = 0;
	inputrowb = listToArrayDynamicInput(inputrow, InputList, current, inputArray);
	
	if(DEBUG ==1)
		printf("\n\tMaximum Amount of Rows:%d\n", inputrowb);
	
	/*call function to free linked list of dictionary entries as not required once in array*/
	printf("\n\t\tSEGFAULT BEFORE\n");
	/*
	 This is where the segfault occurs I try to free it like the dictionary was freed
	 I spent way too much time on this part alone
	 */
	/*freeLinkedList(InputList);*/
	printf("\n\t\tSEGFAULT AFETR\n");
	if(DEBUG ==1)
		printf("\n\tLinked List Freed Successfully\n");
	return inputrowb;
}
