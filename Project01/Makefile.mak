CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: project01 

project01: Project01.c
	gcc $(CFLAGS) -o project01 Project01.c

all: project01

clean:
	rm -f *.o project01.exe
