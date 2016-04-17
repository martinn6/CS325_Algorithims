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

int enumeration1(int n)
{
	return 0;
} 


int main()
{
	//Declare Variables
	const char* filename;
	clock_t timer;
	FILE *fileptr;
	int numArray[50];
	int maxLinesAllowed = 20;
    int maxLineLength = 100;
	int noOfLines = 0;
	
	//aloc memory//
	char **words = (char **)malloc(sizeof(char*)*maxLinesAllowed);
    if (words==NULL)
    {
        fprintf(stderr,"Out of memory!\n");
        exit(1);
    }
	
	//Load file
	char mystring [100];
	filename = "MSS_Problems.txt";
	printf("opening file: %s\n", filename);
	fileptr = fopen(filename, "r");
	if(fileptr == NULL)
		perror("error opening file");
	else {
		for (int i = 0; i <maxLinesAllowed; i++)
		{
			words[i] = malloc(maxLineLength);
			if (words[i]==NULL)
			{
				fprintf(stderr,"Out of memory (3).\n");
				exit(4);
            }
        if(fgets(words[i],maxLineLength-1,fileptr) == NULL)
			break;
		
	}
	 printf("Words=%s\n", words[0]);
	
	
	if(fileptr)
	{
		printf("\nOpened file.\n");
		char *pt;
		char str[] ="[1, 4, -9, 8, 1, 3, 3, 1, -1, -4, -6, 2, 8, 19, -10, -11] ";
		pt = strtok(str,",");
		int i = 0;
		while (pt != NULL) {
			if (pt[0] == '[')
				pt[0] = ' ';
			int a = atoi(pt);
			
			printf("%d\n", a);
			pt = strtok (NULL, ",");
		}
	}
	else
	{
		printf("Error opening %s\n", filename);
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

