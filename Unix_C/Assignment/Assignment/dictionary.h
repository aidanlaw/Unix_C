
/*
 This header file allows the other .c files to use the functions within dictionary.c
 
 dictionary.c is used to read from the dictionary file set by the settings file "spellrc"
 and stores each word into a linked list.
 
 The linked list can then be called upon later to spell check the words given in a users text file.
 */

#ifndef dictionary_h
#define dictionary_h

#ifndef DEBUG
#define DEBUG 0
#endif

/*sets a maximum allocation for characters stored within a single string of the linked list*/
#define LONGEST_WORD_LENGTH 51

/*States what is within the linked list itself*/
typedef struct Dict {
	char *string;
	struct Dict *next;
} Dict;

/*struct to store the head and tail of the linked list as well as the amount of lists created*/
typedef struct Directory{
	Dict *head;
	Dict *tail;
	int listCount;
}Directory;

/*declaration of the function called by the main.c*/
void dictionaryRead(char* dictionaryName, int* row,
					Directory* DictionaryList, Dict* current);

void dictArrayFunc(int completeDictLength);

int arrayCaller(int row, Directory* DictionaryList, Dict* current, char** dictArray);

/*probably not required as only the dictionary.c calls these functions and they are before the main function anyway*/
void freeNode(Dict* current);
void freeLinkedList(Directory* DictionaryList);
void freeArrayFixed(int row, char* dictArray[]);
int listToArrayDynamic(int row, Directory* DictionaryList, Dict* current, char* dictArray[]);
void freeLinkedListi(Directory* ListInput);

#endif /* dictionary_h */
