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
#include <unistd.h>

/**********************************************************************\
This will take in an int array and output time.
\***********************************************************************/

struct lines {
	int num[50];
	int subArray[50];
	int subArray2[50];
	int subArrayLength;
	int subArray2Length;
	char words[100];
	int noOfLines;
	int noOfnums;
	int maxArraySum;
	int maxArrayLength;
	long double time;
};


int algoThreeMaxSubArray(struct lines *line, int lineNum, int a[], int lo, int hi) 
{ 	//int a[], int lo, int hi
	// base case: there's only one element present in the array
	// return only element in the array
	int combinedMax = 0;
	// int tempArrayFirst[100];
	// int tempArraySecond[100];
	// int tempArrayFirstLen = 0, 
		// tempArraySecondLen = 0;
	
	//array test
	printf("lo = %d, hi = %d\n", lo, hi);
	printf("a[] = ");
	for (int i = 0; i < hi; i++)
		printf("%d ", a[i]);
	printf("\n");	
	
	if (lo==hi) {
		printf("low = hi: a[hi]=%d\n", a[hi]);
		return(0);
	}
	else
	{			
		// if the array contains more than one element, find the midpoint
		int midpoint = (lo + hi)/2;
		printf("lo = %d, hi = %d, midpoint = %d\n", lo, hi, midpoint);
		 
		// recursive call that will calculate the sum of the left half
		int firstHalfMax = algoThreeMaxSubArray(&line, lineNum, a, lo, midpoint);
		// recursive call that will calculate the sum of the right half
		int secondHalfMax = algoThreeMaxSubArray(&line, lineNum, a, midpoint+1, hi);

		// get the max in the first half
		int maxFirst = 0;
		int sum = 0;
		for (int i = midpoint - 1; i >=0; i-- )
		{
			sum += a[i];
			
			if (sum > maxFirst)
			{
				maxFirst = sum;
				//get sub-array
				line[lineNum].subArrayLength = 0; //reset array back to zero position
				printf("subarray[]=");
				int n = 0;
				for (int b = i; b >= 0; b--)
				{
					line[lineNum].subArray[line[lineNum].subArrayLength] = a[b]; //subArray[position] = a[b]
					line[lineNum].subArrayLength++; //increaes subArray length
				}
				printf("\n");
				printf("subArrayLength=%d", line[lineNum].subArrayLength);
				printf("subArrayFirst = ");
				for (int i = 0; i < line[lineNum].subArrayLength; i++)
					printf("%d ", line[lineNum].subArray[i]);
				printf("\n");
			}
			
		}
		// printf("maxFirst=%d\n", maxFirst); 
		//find max in the second half
		int maxSecond = 0;
		sum = 0;
		for (int i = midpoint; i < hi; i++ )
		{
			sum += a[i];
			if (sum > maxSecond)
				maxSecond = sum;
			//printf("maxSecond=%d\n", maxSecond);
		}
		// printf("maxSecond=%d\n", maxSecond);  
		//combine the max sum
		combinedMax = maxSecond + maxFirst;
		
	}
	// printf("combinedMax=%d\n", combinedMax);
	// printf("subArrayFirst = ");
	// for (int i = 0; i < line[lineNum].subArrayLength; i++)
		//printf("%d ", line[lineNum].subArray[i]);
	// printf("\n");
	return 0;
	//return fmax(combinedMax, fmax(firstHalfMax, secondHalfMax));
}

int algoOneMaxSubarray(struct lines *line)
{
	int cur; // possition of the current element in the subarray
	int curArrayLen; // holds the length of the current subarray
	int maxArrayLen;
	int sum = 0; // holds the sum
	int maxSum = 0; // holds the max sum of the subarray
	clock_t start_t, end_t;
	//int len = 0;
	
	
	for(int a = 0; a < line[0].noOfLines; a++)
	{
		start_t = clock();
		printf("t=%ld\n", start_t);
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
						//int c = 0;
						line[a].subArray[line[a].subArrayLength] = line[a].num[b];
						line[a].subArrayLength++;
					}
				}
			}
		}
		end_t = clock();
		printf("t2=%ld\n",end_t);
		line[a].time = (long double)(end_t-start_t)/(1.0*CLOCKS_PER_SEC);
	}
	
	
	return 0;
} 

int algoTwoMaxSubarray(struct lines *line)
{
	int sum;
	for (int a = 0; a < line[0].noOfLines; a++)
	{
		line[a].maxArraySum  = line[a].num[0]; // initialize maxSum
		for(int i = 0; i < line[a].noOfnums; i++)
		{
			sum = 0; // initialize sume
			for (int j = i; j < line[a].noOfnums; j++)
			{
				sum += line[a].num[j]; // add the values together
				if(sum > line[a].maxArraySum)
				{
					// if the value in sum is greater than maxSum, then replace maxSum with sum
					line[a].maxArraySum = sum;
					
					//get the subarray
					line[a].subArrayLength = 0;
					for (int b = i; b <= j; b++)
					{
						//int c = 0;
						line[a].subArray[line[a].subArrayLength] = line[a].num[b];
						line[a].subArrayLength++;
					}
				}
			}
		}
	}
	return 0;
}



int outputResults(struct lines *line)
{
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
		printf("max sum = %d\n", line[i].maxArraySum);
		printf("No. of Rows: %d Time taken: %f\n\n", line[i].noOfnums, line[i].time);
	}
	return 0;
}


int main()
{
	//Declare Variables
	struct lines line[20];
	const char* filename;
	FILE *fileptr;
	char *userInput = (char*) malloc(100);
	
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
	
	scanf ("%[^\n]%*c", userInput);
	
	if (strcmp(userInput,"1") == 0)
	{
		//Run First Algorithim
		algoOneMaxSubarray(&line);
		outputResults(&line);
	}
	else if (strcmp(userInput,"2") == 0)
	{
		//Run Test 2
		algoTwoMaxSubarray(&line);
		outputResults(&line);
	}
	else if (strcmp(userInput,"3") == 0)
	{
		//Run Test 3
		//for (int a = 0; a <= line[0].noOfLines; a++)
			int a = 0;
		//{
			algoThreeMaxSubArray(&line, a, line[a].num, 0, line[a].noOfnums); //struct, lineNum, numArray, lo, hi
		//}
	}
	else if (strcmp(userInput,"4") == 0)
	{
		//Run Test 4
		printf("Algorithm 4: Linear-time");
	}
	else
	{
		printf("Invalid Input.");
	}

	//Exit
	printf("\nHave a nice day.\n");
	return 0;
}

