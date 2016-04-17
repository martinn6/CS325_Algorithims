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


int algoOneMaxSubarray(int a[], int len)
{
	int  {
	int cur; // possition of the current element in the subarray
	int curArrayLen; // holds the length of the current subarray
	int maxArrayLen;
	int sum = 0; // holds the sum
	int maxSum = 0; // holds the max sum of the subarray
 
	for(int i = 0; i < len; i++)
	{
		for(int j = i; j < len; j++) 
		{
			sum = 0; 
			curArrayLen = 0; // reset the subarray length
			for(cur = i; cur <= j; cur++) 
			{
				sum += a[cur]; // add the current element to the sum
				curArrayLen++; // increment the current subarray length
			}
			if(sum > maxSum) { // if the current sum is greater than the current max sum, replace it
				maxSum = sum; // reset the max subarray sum
				maxArrayLen = curArrayLen; // reset the max subarray length
			}
		}
	}
	printf("maxArrayLen = %d", maxArrayLen);
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
			printf("line[%d].num[%d]=%d\n", i, j, line[i].num[j]);
		}
	}
	
	 fclose(fileptr);
	 
	 
	
	//Run Test 1
	for (int i = 0; i < line[0].noOfLines; i++)
	{
		enumeration1(line[i].num, line[i].noOfnums);
	}
	
	//Run Test 2
	//Run Test 3
	//Run Test 4
	//Close File
	//Exit
	printf("\nHave a nice day.\n");
	return 0;
}

