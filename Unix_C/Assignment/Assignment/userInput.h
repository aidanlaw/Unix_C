
#ifndef userInput_h
#define userInput_h

#ifndef DEBUG
#define DEBUG 0
#endif

/*sets a maximum allocation for characters stored within a single string of the linked list*/
#define LONGEST_WORD_LENGTH 51

/*declaration of the function called by the main.c*/
void inputRead(char* inputName, int* inputrow,
					Directory* InputList, Dict* current);

int inputArrayCaller(int inputrow, Directory* InputList, Dict* current, char** inputArray);

/*probably not required as only the dictionary.c calls these functions and they are before the main function anyway*/
int listToArrayDynamicInput(int inputrowa, Directory* InputList, Dict* current, char* inputArray[]);

#endif /* userInput_h */
