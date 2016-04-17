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
	int num[50];
	char words[100];
    int maxLineLength;
	int noOfLines;
	int noOfnums;
};


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
	
	//Load file
	line[0].noOfLines = 0;
	char buffer[100];
	filename = "MSS_Problems.txt";
	printf("opening file: %s\n", filename);
	fileptr = fopen(filename, "r");
	if(fileptr == NULL)
		perror("error opening file");
	else {
		while(fgets(buffer,99,fileptr) != NULL)
		{
			printf("%s", buffer);
			strncpy(line[line[0].noOfLines].words, buffer, 99);
			line[0].noOfLines++;
		}
	}
	

	for (int i = 0; i < line[0].noOfLines; i++)
	{
		line[i].noOfnums = 0;
		printf("Words[%d]=%s\n", i, line[i].words);
		char *pt;
		pt = strtok(line[i].words,",");
		while (pt != NULL) {
			if (pt[0] == '[')
				pt[0] = ' ';
			line[i].num[line[i].noOfnums] = atoi(pt);
			pt = strtok (NULL, ",");
			line[i].noOfnums++;
		}
	}
	
	for (int i = 0; i < line[0].noOfLines; i++)
	{
		for (int j = 0; j < line[i].noOfnums; j++)
		{
			printf("line[%d].num[%d]=%d\n", i, line[i].noOfnums, line[i].num[line[i].noOfnums]);
		}
	}
	
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

