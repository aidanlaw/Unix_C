
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	
	if (argc < 2)
	{
		printf("No logfile name specified\n");
	}
	else
	{
		int i; /*for character counting*/
		FILE* log; /*pointer to the memory location of the log file*/
		log = fopen(argv[1], "r"); /*open file*/
		
		/*check to see if there is data within logfile and print error if empty*/
		if (log == NULL)
		{
			perror("\n\n\tAn error occured opening the logfile or the logfile is empty\n\n");
			return 0; /*terminates the program here*/
		}
		
		/*if logfile opened succesfully do the following*/
		
		
		
		
		
		
		
		

	}
	return 0;
}

	else /** logfile was succesfully opened **/
	{
		/*initialise variables to hold the known length of date and times*/
		char month[4]; /* long enough for 3 character month names*/
		int day;
		int hour;
		int min;
		int sec;
		
		/*set maximum length of text strings*/
		int processMax = 50;
		int messageMax = 500;
		
		/*set integer to compare end of string later on*/
		int zero = 0;

		/*allocate memory to the strings for "process" and "message"*/
		char* process = (char*)malloc(processMax * sizeof(char));
		char* message = (char*)malloc(messageMax * sizeof(char));
		
		/*flush all data blocks within the created memory to zero so end of file can be found using "0"*/
		for ( i = 0; i < processMax; i++)
		{
			process[i] = 0;
		}
		
		for ( i = 0; i < messageMax; i++)
		{
			message[i] = 0;
		}
		
		do
		{
			int characterCheck;
			char* temp;
			
			int rowEnd = 0;
			int i = 0;
			fscanf( log, "%s %d %d:%d:%d %s", month, &day, &hour, &min, &sec, process );
			
			/** Read message**/
			do {
				characterCheck = fgetc(log); /*saves a single character from the log into characterCheck*/
				message[i] = (char)characterCheck; /*saves each character from characterCheck into the message string*/
				i++; /*counts up each character saved to the string*/
				
				/*
				 The following checks are required to find the end of the message string.
				 The string could end with a newline character "\n" or an "End Of File" statement.
				 The input is checked for the EOF statement first and then failing that, the newline character.
				 */
				
				if (characterCheck == EOF)
				{
					rowEnd = 1; /*changes the integer from FALSE to TRUE for the newline do while loop to understand*/
					done = 1; /*ensures that the larger "do while" loop is ended*/
				}
				if (characterCheck == '\n') /*looks for new line characters*/
				{
					rowEnd = 1; /*changes the integer from FALSE to TRUE for the newline do while loop to understand*/
				}
				
			} while ( !rowEnd ); /*will continue with the next character until the newline character is met*/
			
			
			if ( (temp=strstr( message, "fail" )) != NULL)
			{
				int seconds = time[2] + time[1]*60 + time[0] * 60*60;
				
				message[i] = '\0'; /** add null terminator to string **/
				
				
				
				printf("%d %s: %s %s; %d seconds from midnight \n", day, month, process_name, message, seconds);
				
			}
		} while ( !done );
		
		
		/** deallocate all memory, close files **/
		free(process);
		free(message);
		fclose(log);
		return 1;
		
	}
}
