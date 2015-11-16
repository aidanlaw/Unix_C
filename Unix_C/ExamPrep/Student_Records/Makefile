
CFLAGS = -Wall -ansi -pedantic
PROGRAMNAME = prog
CODENAME = main
OBJ = $(CODENAME).o

$(PROGRAMNAME):$(OBJ)
	gcc $(OBJ) -o $(PROGRAMNAME)

$(CODE).o:$(CODENAME).c
	gcc $(CFLAGS) -c $(CODENAME).c

debug:$(CODENAME).c
	gcc $(CFLAGS) -c -g $(CODENAME).c -DDEBUG=1;
	gcc $(OBJ) -o $(PROGRAMNAME)

clean:
	rm -f $(OBJ) $(PROGRAMNAME)

rundebug:$(CODENAME).c
	gcc $(CFLAGS) -c -g $(CODENAME).c -DDEBUG=1;
	gcc $(OBJ) -o $(PROGRAMNAME);
	./prog input.txt;
	make clean

run:$(CODENAME).c
	gcc $(CFLAGS) -c -g $(CODENAME).c;
	gcc $(OBJ) -o $(PROGRAMNAME);
	./prog input.txt;
	make clean