/*********************************************************************************************
 * Developers: Nick Martin (martinn6)

 * Date: 20160403
 * Project: Project 01
 * Description: Fibonacci recusive program
 * *******************************************************************************************/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/**********************************************************************\
This will take in an int array and output time.
\***********************************************************************/

struct lines {
	int numArray[50];
	char words[100];
	int maxLinesAllowed = 20;
    int maxLineLength = 100;
	int noOfLines = 0;
}


int enumeration1(int n)
{
	return 0;
} 


int main()
{
	//Declare Variables
	struct lines line[20];
	const char* filename;
	clock_t timer;
	FILE *fileptr;
	
	//aloc memory//
    if (words==NULL)
    {
        fprintf(stderr,"Out of memory!\n");
        exit(1);
    }
	
	//Load file
	char buffer[100];
	filename = "MSS_Problems.txt";
	printf("opening file: %s\n", filename);
	fileptr = fopen(filename, "r");
	if(fileptr == NULL)
		perror("error opening file");
	else {
		while(fgets(buffer,maxLineLength-1,fileptr) != NULL)
		{
			printf("%s", buffer);
			strncpy(line[noOfLines].words, buffer, 99);
			noOfLines++;
		}
	}
	
	int j = 0;
	for (int i = 0; i < noOfLines; i++)
	{
		j = 0;
		printf("Words[%d]=%s\n", i, line[i].words);
		char *pt;
		pt = strtok(line[i].words,",");
		while (pt != NULL) {
			if (pt[0] == '[')
				pt[0] = ' ';
			numArray[i][j] = atoi(pt);
			pt = strtok (NULL, ",");
			j++;
		}
	}
	
	
	// for (int i = 0; i < 50; i++)
	// {
		// printf("numArray[%d] = %d ", i, numArray[i]);
	// }
	
	 fclose(fileptr);
	
	//Run Test 1
	enumeration1(0);
	//Run Test 2
	//Run Test 3
	//Run Test 4
	//Close File
	//Exit
	printf("\nHave a nice day.\n");
	return 0;
}

