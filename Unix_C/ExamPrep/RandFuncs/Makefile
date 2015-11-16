
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

run:$(CODENAME).c
	gcc $(CFLAGS) -c -g $(CODENAME).c -DDEBUG=1;
	gcc $(OBJ) -o $(PROGRAMNAME);
	./prog;
	make clean