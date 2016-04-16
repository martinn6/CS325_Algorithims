CFLAGS = -Wall -fpic -coverage -lm -std=c99

project01: Project01.c
	gcc -o Project01 Project01.c $(CFLAGS)

all: project01

clean:
	rm -f *.o Project01.exe
