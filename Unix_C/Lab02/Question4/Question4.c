//
//  Question4
//
//  Created by Aidan Law on 14/08/2015.
//
//

// Compile dependencies

// a) Which files does the main.c include?
database.h

// b) Which files include util.h?
util.c
interface.c
database.h

// c) What .o files would be created during compilation?
main.o
database.o
util.o
interface.o
// essentially anything with a ".c" extension

// d) If database.h is modified, which .o files would need to be recompiled?
main.o
database.c

// e) If util.h is modified, which .o files would need to be recompiled?
all files

// f) If util.c is modified, which .o files would need to be recompiled?
util.c
