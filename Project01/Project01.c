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
	
	//Load file
	filename = "MSS_Problems.txt";
	printf("opening file: %s\n", filename);
	fileptr = fopen(filename, "r");
	
	if(fileptr)
	{
		printf("\nOpened file.");
		char *pt;
		char str[] ="1,2,3,4,5";
		//for (int i = 0; i < 50; i++)
		//{
			pt = strtok(str,",");
			while (pt != NULL) {
				int a = atoi(pt);
				printf("%d\n", a);
				pt = strtok (NULL, ",");
			}
		//}
	}
	else
	{
		printf("Error opening %s\n", filename);
	}
	
	for (int i = 0; i < 50; i++)
	{
		printf("numArray[%d] = %d ", i, numArray[i]);
	}
	
	
	
	//Run Test 1
	enumeration1(0);
	//Run Test 2
	//Run Test 3
	//Run Test 4
	//Close File
	//Exit
	
	return 0;
}

