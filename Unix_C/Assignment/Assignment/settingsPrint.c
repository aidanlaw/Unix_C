
/*
 This was created to print out the values read from "spellrc" and 
 stored within the struct found within the "Settings.h" file.
 
 This function will only be used when the "make debug" command is
 used for compilation and the "./prog" program is executed.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Settings.h"

void printSettings(Settings* set)
{
	/*prints out the settings file in a crudely made table*/
	printf("\n\t+-------------------------------------------------------+");
	printf("\n\t|\t\tSETTINGS READ FROM SPELLRC\t\t|\n");
	printf("\t+-------------------------------------------------------+");
	printf("\n\t| Maximum Correction:\t%-d\t\t\t\t|\n", set->maxCorrection);
	printf("\t| Dictionary File:\t%-30s\t|\n", set->dictionaryName);
	printf("\t| Autocorrect On:\t%-4s\t\t\t\t|\n", set->autocorrect);
	printf("\t+-------------------------------------------------------+\n\n");
}

