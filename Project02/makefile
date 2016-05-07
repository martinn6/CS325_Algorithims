default: project02 changedp changeslow

project02: Project02.c
	gcc -std=c99 -o project02 Project02.c
	
changedp: changedp.c
	gcc -std=c99 -o changedp changedp.c
	
changeslow: changeslow.c
	gcc -std=c99 -o runtest changeslow.c

all: project02 changedp changeslow

clean:
	rm -f *.o project02 changedp
