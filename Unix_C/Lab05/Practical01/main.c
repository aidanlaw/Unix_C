
/*
 Lab05 - Practical01
 
 This program reads an existing file and copies it to a new file.
 
 The filenames must be passed in by the user when executing the program.
 
 An example would be:
 =========================
 ./prog read.txt write.txt
 =========================
 
 where read.txt was a file that already exists in the current folder
 and write.txt is a file that the program would create.
 
 To check the program works as intended, use the "diff" command in the terminal to check as follows:
 =========================
 diff read.txt write.txt
 =========================
 If no difference between the files exist then the terminal will remain silent.
 
 */

#include <stdio.h>

int main(int argc, char* argv[])
{
	/*create a pointer to the position along memory where the file WILL be*/
	FILE* fileRead;
	FILE* fileWrite;
	
	/*open the file and insert it into the memory pointer location stated above
	 fopen("name of file", "read and/or write mode")*/
	fileRead = fopen(argv[1], "r"); /*file to be read*/
	fileWrite = fopen(argv[2], "w"); /*file to be created*/
	
	/*check to see if file exists for copying*/
	if (fileRead == NULL)
	{
		printf("Filename %s does not exist int the current folder.\n", argv[1]);
	}
	
	/* only required if there is a problem creating a file to copy to which would be a very rare issue*/
	else if (fileWrite == NULL)
	{
		printf("There was an issue with %s being created by this program.\n\n", argv[2]);
		fclose(fileRead); /*close the read file as the program could not be completed in this case*/
	}
	
	
	else /*does the following if both files properly opened.*/
	{
		int tempChar; /*create a temporary store for each character in the read file before transferring to new file*/
		
		while ((tempChar = fgetc(fileRead)) != EOF)
		/*reads in every character from the read file until the "End Of File" is reached
		 and then saves each character in order into the new file*/
		{
			fputc( (char) tempChar, fileWrite );
		}
		
		/*files must be closed before terminating program*/
		fclose(fileRead);
		fclose(fileWrite);
	}
	return 0;
}
