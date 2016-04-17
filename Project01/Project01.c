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
	int userInput;
	
	//Load lines into line[n].words
	line[0].noOfLines = 0;
	char buffer[100];
	filename = "MSS_Problems.txt";
	printf("opening file: %s...\n", filename);
	fileptr = fopen(filename, "r");
	if(fileptr == NULL)
		perror("error opening file");
	else {
		printf ("File Opened. Retreving Data.\n");
		while(fgets(buffer,99,fileptr) != NULL)
		{
			//printf("%s", buffer); //test buffer
			strncpy(line[line[0].noOfLines].words, buffer, 99);
			line[0].noOfLines++;
		}
	}
	
    //parse numbers from lines into array
	for (int i = 0; i < line[0].noOfLines; i++)
	{
		line[i].noOfnums = 0;
		//printf("Words[%d]=%s\n", i, line[i].words); //Test Only
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
	
	//close file
	fclose(fileptr);
	 
	//ask user for which algorithm to run
	printf("Choose which algorithim to run:\n");
	printf("1) Algorithm 1: Enumeration\n");
	printf("2) Algorithm 2: Better Enumeration\n");
	printf("3) Algorithm 3: Divide and Conquer\n");
	printf("4) Algorithm 4: Linear-time\n");
	 
	scanf("%d", &userInput); 
	 
	 
	switch(userInput) {
		case '1':
			//Run First Algorithim
			algoOneMaxSubarray(&line);
			break;
		case '2':
			//Run Test 2
			printf("Algorithm 2: Better Enumeration");
			break;
		case '3':
			//Run Test 3
			printf("Algorithm 3: Divide and Conquer");
			break;
		case '4':
			//Run Test 4
			printf("Algorithm 4: Linear-time");
			break;
		default:
			printf("Invalid Input.");
			break;
	}
	

	//Test Output
	printf("Results:\n\n");
	for (int i = 0; i < line[0].noOfLines; i++)
	{
		printf("[");
		for (int j = 0; j < line[i].noOfnums; j++)
		{
			printf("%i", line[i].num[j]);
			if(j != line[i].noOfnums - 1)
				printf(", ");
		}
		printf("]\n");
		printf("[");
		for (int j = 0; j < line[i].subArrayLength; j++)
		{
			printf("%i", line[i].subArray[j]);
			if(j != line[i].subArrayLength - 1)
				printf(", ");
		}
		printf("]\n");
		printf("max sum = %d\n\n", line[i].maxArraySum);
	}
	
	//Exit
	printf("\nHave a nice day.\n");
	return 0;
}

