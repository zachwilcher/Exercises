
VPATH = src

SHELL = /bin/sh

.SUFFIXES: .c .h .o


objects = main.o cipher.o 

cipher: $(objects)
	cc -o cipher $(objects)

main.o: main.c rotlib.h

cipher.o: cipher.c rotlib.h



.PHONY: clean

clean:
	rm cipher $(objects)

