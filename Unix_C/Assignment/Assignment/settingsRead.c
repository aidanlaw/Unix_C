
#include "settingsRead.h"
#include <string.h>
#include <errno.h>
#include <stdlib.h>

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