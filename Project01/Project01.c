/*********************************************************************************************
 * Developers: Nick Martin (martinn6)

 * Date: 20160403
 * Project: Project 01
 * Description: Fibonacci recusive program
 * *******************************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**********************************************************************\
This will take in an int array and output time.
\***********************************************************************/

int enumeration1(int n)
{
	return 0;
} 


main()
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
		for (int i = 0; i < 50; i++)
		{
			fscanf(fileptr, "%d", &numArray[i]);
		}
	}
	else
	{
		printf("Error opening %s\n", filename);
	}
	
	for (int i = 0; i < 50; i++)
	{
		printf("numArray[%d] = %d", i, numArray[i]);
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

