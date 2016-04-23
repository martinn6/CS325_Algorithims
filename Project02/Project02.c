/*********************************************************************************************
 * Developers: Nick Martin (martinn6)
	Elizabeth 

 * Date: 20160422
 * Project: Project 02
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

int Greedy(int v[], int c[], int a, int m)
{
	
	return 0;
}


int outputResults(struct lines *line)
{
	//Test Output
	/*
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
	*/
	return 0;
}


int outputResultsToFile(struct lines *line)
{
	//Test Output
	/*
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
	*/
	return 0;
}


int main()
{
	//Declare Variables
	FILE *fp;
	char *line = NULL;
    size_t len = 0;
    ssize_t read;
	char filename[99];
	char numLine[99];
	char valueLine[99];
	char buffer[100];

	
	printf("Enter filename: ");
	fgets(filename, 99, stdin);
	char *p = strchr(filename, '\n'); // p will point to the newline in filename
	if(p) *p = 0; // if p is not null, terminate filename at p
	
	fp = fopen(filename, "r");
	
	if(!fp)
		perror("File not found");
	else
	{
		printf("opening file: %s...\n", filename);
		while ((read = getline(&line, &len, fp)) != -1) {
			printf("line=%s, len=%d, read=%d\n", line, len, read);
		}
    }
 
	printf("numLine=%s\n", numLine);
	printf("valueLine=%s\n", valueLine);

 
	/*
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
	*/
	//close file
	fclose(fp);
	
	/* random number generator for tests

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
	
	clock_t start, end;
	float elapsed_time;
	start = clock();
	for(int x = 0; x< 100000; x++)
		x = x;
	end = clock();
	elapsed_time = (float)(end - start) / (float)CLOCKS_PER_SEC;
	printf("Elapsed time: %f seconds\n", elapsed_time);
	

	for (int i = 0; i < 9; i++){

		algoOneMaxSubarray(&line); 

	}	
    */
	 
	//ask user for which algorithm to run
	/*
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
		algoFourLinearTime(&line, line[0].num, line[0].noOfnums); 
		outputResults(&line);
		outputResultsToFile(&line);
	}
	else
	{
		printf("Invalid Input.");
	}
	*/
	//Exit
	printf("\nHave a nice day.\n");
	return 0;
}

