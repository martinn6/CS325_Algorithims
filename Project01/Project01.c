/*********************************************************************************************
 * Developers: Nick Martin (martinn6)
	Elizabeth 

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
	int num[1000];
	int subArray[500];
	int subArray2[500];
	int subArrayLength;
	int subArray2Length;
	char words[1000];
	int noOfLines;
	int noOfnums;
	int maxArraySum;
	int maxArrayLength;
	long double time;
};


int algoFourLinearTime(struct lines *line, int a[], int arrayLen)
{
	//need position of array (a-b)
	//need subarray sum SUM(A-b)
	//store final in finalSum
	int temp_sum = 0, 
		sum = 0,
		left = 0, 
		right = 0;
		
	for (int i = 0; i < arrayLen; i++)
	{
		if(temp_sum + a[i] > 0)
		{
			temp_sum = temp_sum + a[i];
		}
		else { 
			temp_sum = 0;
			left = i+1;
		}
		if (temp_sum > sum)
		{
			sum = temp_sum;
			right = i+1;
		}
	}
	// printf("left = %d", left);
	// printf("right = %d\n", right);

	//copy subarray to struct
	int n = 0;
	for(int i = left; i < right; i++)
	{
		line[0].subArray[n] = a[i];
		n++;
	}
	line[0].subArrayLength = n;
	//set result in struct
	line[0].maxArraySum = sum;
	
	return 0;
}



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
				printf("test=");
				int n = 0;
				for (int b = i; b >= 0; b--)
				{
					printf("%d, ",a[b]);
					//line[lineNum].subArray[n] = a[b];
					n++;
				}
				//line[lineNum].subArrayLength = n;
			}
		}
		printf("maxFirst=%d\n", maxFirst); 
		printf("subArrayLength=%d\n", line[lineNum].subArrayLength);
		//find max in the second half
		int maxSecond = 0;
		sum = 0;
		for (int i = midpoint; i < hi; i++ )
		{
			sum += a[i];
			if (sum > maxSecond)
				maxSecond = sum;
		}

		//combine the max sum
		combinedMax = maxSecond + maxFirst;
		
	}
	printf("combinedMax=%d\n", combinedMax);
	line[0].maxArraySum = combinedMax;
	printf("linenum=%d\n",line[lineNum].subArray[0]);
	
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

	for(int a = 0; a < line[0].noOfLines; a++)
	{
		for(int i = 0; i < line[0].noOfnums; i++)
		{
			for(int j = i; j < line[0].noOfnums; j++) 
			{
				sum = 0; 
				curArrayLen = 0; // reset the subarray length
				for(cur = i; cur <= j; cur++) 
				{
					sum += line[0].num[cur]; // add the current element to the sum
					curArrayLen++; // increment the current subarray length
				}
				if(sum > line[0].maxArraySum) { // if the current sum is greater than the current max sum, replace it
					line[0].maxArraySum = sum; // reset the max subarray sum
					line[0].maxArrayLength = curArrayLen; // reset the max subarray length
					//copy substring to subArray
					line[0].subArrayLength = 0;
					for (int b = i; b <= j; b++)
					{
						//int c = 0;
						line[0].subArray[line[0].subArrayLength] = line[0].num[b];
						line[0].subArrayLength++;
					}
				}
			}
		}
	}
	return 0;
} 

int algoTwoMaxSubarray(struct lines *line)
{
	int sum;
	
	line[0].maxArraySum  = line[0].num[0]; // initialize maxSum
	for(int i = 0; i < line[0].noOfnums; i++)
	{
		sum = 0; // initialize sume
		for (int j = i; j < line[0].noOfnums; j++)
		{
			sum += line[0].num[j]; // add the values together
			if(sum > line[0].maxArraySum)
			{
				// if the value in sum is greater than maxSum, then replace maxSum with sum
				line[0].maxArraySum = sum;
				
				//get the subarray
				line[0].subArrayLength = 0;
				for (int b = i; b <= j; b++)
				{
					//int c = 0;
					line[0].subArray[line[0].subArrayLength] = line[0].num[b];
					line[0].subArrayLength++;
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
	}
	return 0;
}


int outputResultsToFile(struct lines *line)
{
	//Test Output
	FILE *fp;
	const char* outfilename;
	outfilename = "MSS_Results.txt";
	fp = fopen(outfilename, "w");
	//printf("Results:\n\n");
	for (int i = 0; i < line[0].noOfLines; i++)
	{
		fprintf(fp,"%s","[");
		for (int j = 0; j < line[i].noOfnums; j++)
		{
			fprintf(fp,"%i", line[i].num[j]);
			if(j != line[i].noOfnums - 1)
				fprintf(fp,"%s",", ");
		}
		fprintf(fp,"%s","]\n");
		fprintf(fp,"%s","[");
		for (int j = 0; j < line[i].subArrayLength; j++)
		{
			fprintf(fp,"%i", line[i].subArray[j]);
			if(j != line[i].subArrayLength - 1)
				fprintf(fp,"%s",", ");
		}
		fprintf(fp,"%s","]\n");
		fprintf(fp,"%s %d %s","max sum = ", line[i].maxArraySum,"\n");
	}
	printf("Output results to file: %s", outfilename);
	//close file
	fclose(fp);
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
			line[0].noOfLines=1;
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
	
	/* random number generator for tests*/

	int len = 1000;
	int testArr[10][len];
	for(int i = 0; i < 10; i++) {
		for (int j = 0; j < len; j++) {
			testArr[i][j] = rand();
		}
	}
	
	for (int n = 0; n < 10; n++)
	{
		for (int i = 0; i < len; i++)
		{
			line[n].num[i] = testArr[n][i];
		}
	}
	
	clock_t start_t, end_t, total_t;
	for (int i = 0; i < 9; i++){
		start_t = clock();
		algoFourLinearTime(&line, line[0].num, line[0].noOfnums); 
		end_t = clock();
		//total_t = ((double) (end_t - start_t))/CLOCKS_PER_SEC;
		total_t = ((double) (end_t - start_t))/1000000;
		printf("\ntotal time = %lu\n\n",total_t);
	}	
   
	 
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
		outputResultsToFile(&line);
	}
	else if (strcmp(userInput,"2") == 0)
	{
		//Run Test 2
		algoTwoMaxSubarray(&line);
		outputResults(&line);
		outputResultsToFile(&line);
	}
	else if (strcmp(userInput,"3") == 0)
	{
		int a = 0;
		algoThreeMaxSubArray(&line, a, line[a].num, 0, line[a].noOfnums); //struct, lineNum, numArray, lo, hi
		outputResults(&line);
		outputResultsToFile(&line);
	}
	else if (strcmp(userInput,"4") == 0)
	{
		//Run Test 4
		line[0].noOfLines = 1;
		int result = algoFourLinearTime(&line, line[0].num, line[0].noOfnums); 
		outputResults(&line);
		outputResultsToFile(&line);
	}
	else
	{
		printf("Invalid Input.");
	}

	//Exit
	printf("\nHave a nice day.\n");
	return 0;
}

