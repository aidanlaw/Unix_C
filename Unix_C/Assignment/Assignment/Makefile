#The following is the makefile for the UCP assignment.
#Written by Aidan Law - 17426855
#<make debug> can be used to turn on debugging for the main code otherwise use <make>
#It was used in the initial stages to ensure that files were being read correctly
#Debug mode currently prints out the "spellrc" settings defined in a file aptly name "spellrc"

CC = gcc
CFLAGS = -Wall -ansi -pedantic
OBJ = main.o settingsPrint.o dictionary.o userInput.o check.o writeFile.o
TARGET = prog

$(TARGET):$(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

main.o:main.c Settings.h dictionary.h userInput.h
	$(CC) $(CFLAGS) -c main.c

#This was created when the settings printer was introduced
settingsPrint.o:settingsPrint.c Settings.h
	$(CC) $(CFLAGS) -c settingsPrint.c

#This was created when the dictionary linked list was introduced
dictionary.o:dictionary.c dictionary.h
	$(CC) $(CFLAGS) -c dictionary.c

#This was created when the input linked list was introduced
userInput.o:userInput.c userInput.h dictionary.h Settings.h
	$(CC) $(CFLAGS) -c userInput.c

#This was created when the input linked list was introduced
check.o:check.h check.c
	$(CC) $(CFLAGS) -c check.c

#This was created when the input linked list was introduced
writeFile.o:Settings.h writeFile.c
	$(CC) $(CFLAGS) -c writeFile.c


# Call with "make debug" to print out what is going on in the main code
debug:main.c settingsPrint.c dictionary.c userInput.c userInput.h dictionary.h Settings.h
	$(CC) $(CFLAGS) -c -g settingsPrint.c -DDEBUG=1;
	$(CC) $(CFLAGS) -c -g dictionary.c -DDEBUG=1;
	$(CC) $(CFLAGS) -c -g userInput.c -DDEBUG=1;
	$(CC) $(CFLAGS) -c -g check.c;
	$(CC) $(CFLAGS) -c writeFile.c;
	$(CC) $(CFLAGS) -c -g main.c -DDEBUG=1;
	$(CC) $(OBJ) -o $(TARGET)

# Call with "make debug" to print out what is going on in the main code
make:main.c settingsPrint.c dictionary.c userInput.c userInput.h dictionary.h Settings.h
	$(CC) $(CFLAGS) -c -g settingsPrint.c -DDEBUG=0;
	$(CC) $(CFLAGS) -c -g dictionary.c -DDEBUG=0;
	$(CC) $(CFLAGS) -c -g userInput.c -DDEBUG=0;
	$(CC) $(CFLAGS) -c -g check.c;
	$(CC) $(CFLAGS) -c writeFile.c;
	$(CC) $(CFLAGS) -c -g main.c -DDEBUG=0;
	$(CC) $(OBJ) -o $(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
