
/*
 This header file was created to allow the settings struct to be used
 from any function no matter which ".c" the function was located.
 
 Note that the #ifndef statements are used to stop any duplicate entries
 */

#ifndef Settings_h
#define Settings_h

#ifndef DEBUG
#define DEBUG 0
#endif

typedef struct {
	int maxCorrection;
	char* dictionaryName;
	char* autocorrect;
} Settings;

void printSettings(Settings* set);

void writeFile(int inputrow, char* inputArray[], char* inputName);

#endif /* Settings_h */
