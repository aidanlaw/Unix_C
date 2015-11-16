
CFLAGS = -Wall -ansi -pedantic
OBJ = main.o
TARGET = prog

$(TARGET):$(OBJ)
	gcc $(OBJ) -o $(TARGET)

main.o:main.c
	gcc $(CFLAGS) -c main.c

clean:
	rm -f $(OBJ) $(TARGET)
