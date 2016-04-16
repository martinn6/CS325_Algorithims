CFLAGS = -Wall -fpic -coverage -lm -std=c99

Project01: Project01.c
	gcc -c Project01.c -g  $(CFLAGS)

all: Project01
clean:
	rm -f *.o Project01.exe
