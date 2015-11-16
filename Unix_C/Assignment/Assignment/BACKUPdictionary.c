


#include "dictionary.h"
#include "Settings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/*
 Function called upon by another function called "freeLinkedList".
 Frees each field within the current struct whilst saving the address of the next struct.
 This is the recursive part of the freeing code.
 */
void freeNode(Dict* current)
{
	if(current != NULL)
	{
		freeNode(current->next);
		
		free(current->string);
		free(current);
	}
}

/*
 Function called upon by the "dictionaryRead" function (the central code in dictionary.c).
 Takes in the struct that acts as the head of the linked list.
 Calls upon the function above to free each section inside the linked lists.
 Finally frees the memory allocated to hold the head, tail, and number of lists connected.
 */
void freeLinkedList(Directory* DictionaryList)
{
	freeNode(DictionaryList->head);
	free(DictionaryList);
}

unsigned int listToArrayDynamic(unsigned int rowa, Directory* DictionaryList, Dict* current, char** dictArray)
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
	
	unsigned long completeLengthCount;
	
	printf("\n\n");
	rowa = 0;
	completeLengthCount = 0;
	
	if(DEBUG ==1)
		printf("\n\tArray length to create: %d\n", DictionaryList->listCount);
	
	current = DictionaryList->head;
	
	do
	{
		completeLengthCount = 0;
		completeLengthCount = strlen(current->string);
		dictArray[rowa] = (char*)malloc(sizeof(char)*(completeLengthCount));
		strcpy(dictArray[rowa], current->string);
		current = current->next;
		
		if(DEBUG ==1)
			printf("\tArray [%06d]:\t%s\n", rowa, dictArray[rowa]);
		rowa++;
	} while (current != NULL);
	
	if(DEBUG ==1)
	{
		printf("\n\tArray Entry 3 is: %s", dictArray[3]);
		printf("\n\tArray entry chosen to print is: %p\n", &dictArray[3]);
	}
	return rowa;
}

/*
 Function to free the dynamically allocated array created by the "listToArrayDynamic" function.
 Frees each row seperately and then frees the entire array.
 */
void freeArrayFixed(unsigned int row, char* dictArray[])
{
	unsigned int i;
	for(i = 0; i < row; i++)
	{
		free(dictArray[i]);
	}
	if(DEBUG ==1)
		printf("\n\tRows are Free\n");
	free(dictArray);
	if(DEBUG ==1)
		printf("\n\tTotal Dictionary Array is Free\n");
}


void dictionaryRead( char* dictionaryName, unsigned int* row, unsigned int *completeDictLength,
					Directory* DictionaryList, Dict* current)
{
	/*allocate storage for words to stay temporarily before being transferred to the linked list
	 (like a cheap motel you stay at which is close to the airport so you don't have to waste money
	 on half a night in a nice hotel. You can put up with bars on the windows for the 6 hours you
	 will be there, but if you stay it would ruin the tropical holiday you looked forward to for
	 6 months as your monotonous job slowly eats away at your soul.)
	 */
	char temp[LONGEST_WORD_LENGTH];
	
	
	/*create a file pointer and open the dictionary file set by the spellrc file*/
	FILE *dictionaryFile;
	dictionaryFile = fopen(dictionaryName, "r");
	
	/*check if the dictionary file exists and has entries inside*/
	if(dictionaryFile == NULL)
	{
		printf("The dictionary file is emtpy\n");
	}
	
	/*
	 If the dictionary file specified by spellrc exists and has valid entries then the following will happen:
	 Create the head of the linked list as well as the first struct/list entry.
	 Allocate memory for the head file and set entries to NULL.
	 Scan the dictionary file
	 */
	else
	{
		
		
		while(fscanf(dictionaryFile, "%s\n", temp) > 0)
		{
			
			current = (Dict*)malloc(sizeof(Dict));
			
			current->string = (char*)malloc(sizeof(char)*LONGEST_WORD_LENGTH);
			
			strcpy(current->string,temp);
			DictionaryList->listCount = DictionaryList->listCount + 1;
			
			if(DEBUG ==1)
				printf("\n\tLinked List Entry %06d:\t%s", DictionaryList->listCount, current->string);
			
			if(DictionaryList->head == NULL)
			{
				DictionaryList->head = current;
				DictionaryList->tail = current;
			}
			
			else
			{
				DictionaryList->tail->next = current;
				DictionaryList->tail = current;
			}
			
		}
		/*saves the length of the dictionary to a variable known by main to be called upon later*/
		*completeDictLength = DictionaryList->listCount;
		if(DEBUG ==1)
		{
			printf("\n\tDictionary length is %d and %d\n", DictionaryList->listCount, *completeDictLength);
		}
		
	}
	fclose(dictionaryFile);
}


/*
 This function calls another function which produces the 2D array from the linked list.
 The link list is then freed as it is no longer required.
 This step was not necessary but it is how my mind imagined it at the time.
 */
void arrayCaller(unsigned int* row, Directory* DictionaryList, Dict* current, char** dictArray)
{
	unsigned int rowa;
	*row = 0;
	rowa = *row;
	*row = listToArrayDynamic(rowa, DictionaryList, current, dictArray);
	
	if(DEBUG ==1)
		printf("\n\tMaximum Amount of Rows:%d\n", *row);
	
	/*call function to free linked list of dictionary entries as not required once in array*/
	freeLinkedList(DictionaryList);
	if(DEBUG ==1)
		printf("\n\tLinked List Freed Succesfully\n");
	
}
