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
	int subArray[50];
	int subArrayLength;
	char words[100];
	int noOfLines;
	int noOfnums;
	int maxArraySum;
	int maxArrayLength;
	int time;
};


int algoOneMaxSubarray(struct lines *line)
{
	int cur; // possition of the current element in the subarray
	int curArrayLen; // holds the length of the current subarray
	int maxArrayLen;
	int sum = 0; // holds the sum
	int maxSum = 0; // holds the max sum of the subarray
	//int len = 0;
	
	for(int a = 0; a < line[0].noOfLines; a++)
	{
		for(int i = 0; i < line[a].noOfnums; i++)
		{
			for(int j = i; j < line[a].noOfnums; j++) 
			{
				sum = 0; 
				curArrayLen = 0; // reset the subarray length
				for(cur = i; cur <= j; cur++) 
				{
					sum += line[a].num[cur]; // add the current element to the sum
					curArrayLen++; // increment the current subarray length
				}
				if(sum > line[a].maxArraySum) { // if the current sum is greater than the current max sum, replace it
					line[a].maxArraySum = sum; // reset the max subarray sum
					line[a].maxArrayLength = curArrayLen; // reset the max subarray length
					//copy substring to subArray
					line[a].subArrayLength = 0;
					for (int b = i; b <= j; b++)
					{
						int c = 0;
						line[a].subArray[line[a].subArrayLength] = line[a].num[b];
						line[a].subArrayLength++;
					}
				}
			}
		}
	}
	
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
	
	
	
	 fclose(fileptr);
	 
	 
	
	//Run Test 1
	// for (int i = 0; i < line[0].noOfLines; i++)
	// {
		// algoOneMaxSubarray(line[i].num, line[i].noOfnums);
	// }
	algoOneMaxSubarray(&line);
	
	//Run Test 2
	//Run Test 3
	//Run Test 4
	//Close File
	//Exit
	
	/* TEST OUTPUT */
	for (int i = 0; i < line[0].noOfLines; i++)
	{
		printf("[");
		for (int j = 0; j < line[i].noOfnums; j++)
		{
			printf("%i", line[i].num[j]);
			if(j != line[i].noOfnums - 1)
				printf(",");
		}
		printf("]\n");
		printf("[");
		for (int j = 0; j < line[i].subArrayLength; j++)
		{
			printf("%i", line[i].subArray[j]);
			if(j != line[i].noOfnums - 1)
				printf(", ");
		}
		printf("]\n");
		printf("max sum = %d\n\n", line[i].maxArraySum);
	}
	
	printf("\nHave a nice day.\n");
	return 0;
}

