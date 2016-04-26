/*********************************************************************************************
 * Developers: Nick Martin (martinn6)
 * Date: 20160422
 * Project: Project 02
 * Description: Implement a greedy algorithm.
 * *******************************************************************************************/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/**********************************************************
Name: randomNum()
Description: Used for testing the greedy function. It will
	populate the array V with random coin values to 
	maxNumOfCoins with the larget coin size of  maxCoinValue.
	It will also calculate a random maxValue.
**********************************************************/
int randomNum(int *v, int *a, int maxNumOfCoins, int maxCoinValue, int maxValue)
{
	int temp;
	
	//random select value
	*a = rand() % (maxValue-1) + 1;
	
	//fill coins (make sure not to have two coins with same value)
	int x = 0, numFound;
	while(x < maxNumOfCoins)
	{
		numFound = 0;
		temp = rand() % (maxCoinValue-1) + 1;
		for(int y = 0; y < maxNumOfCoins; y++)
		{
			if(temp == v[y])
				numFound = 1;
		}
		if (numFound == 0)
		{
			v[x] = temp;
			x++;
		}
	}	
	
	//sort coins in accending order (bubble sort)
	 for (int i = 0; i < maxNumOfCoins; i++) {
        for (int j = 0; j < maxNumOfCoins-i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
	
	return(0);
}

/**********************************************************
Name: runGreedyAlgorithm()
Description: Finds the least amount of coins needed by 
	starting with the largest coin value and progressing
	to the smallest coin value. It will calculate:
		1) # of each coin used
		2) Total # of coins used.
**********************************************************/
int runGreedyAlgorithm(int v[], int a, int *c, int *m, int length)
{
	int value = a,
		tempValue = 0,
		n = 1;
	
	*m = 0; //Set # of coins to zero
		
	while(value > 0 && (length - n) >= 0)
	{
		slowDown();	//slowing down the function so I can track its time.
		tempValue = value - v[length-n];
		if (tempValue >= 0)
		{		
			value = tempValue; 
			c[length-n] = c[length-n]+1; 				//increment count array for coin used
			*m = *m+1;									//increment number of coins used.
			/* FOR TESTING ONLY
			printf("Coin Used = %d\n", v[length-n]);	
			printf("New Value: %d\n", value);
			printf("Total Coins Used: %d\n", *m);
			*/
			
		}
		else
		{
			n++;
		}
	}
	
	/*print out c test
	for(int x = 0; x < length; x++)
	{
		printf("c[%d] = %d; ", x, c[x]);
	}
	*/
	
	return 0;
}

int slowDown()
{
	int n = 0;
	
	for(int x=0; x< 1000000; x++)
		n = x;
}

/**********************************************************
Name: outputResults()
Description: outputs the results to screen in the format:
	[ArrayName] = [n0, n1, ... n[Array.Length]]
**********************************************************/
int outputResults(int c[], int length, int m, char arrayName)
{
	//Test Output
	printf("%c=[", arrayName);
	for (int x = 0; x < length; x++)
	{
		printf("%d", c[x]);
		if(x != length-1)
			printf(", ");
	}
	printf("]\n");
	printf("%d\n", m);

	return 0;
}


int main()
{
	srand(time(NULL));
	//Declare Variables
	FILE *fp;
	char *line = NULL;
    size_t len = 0;
    ssize_t read;
	char filename[99];
	char *numLine;
	char *userInput = (char*) malloc(100);
	char *valueLine;
	char buffer[100];
	int n = 0;
	clock_t start, end;
	float elapsed_time;

	//For random generation
	int maxValue = 10000;
	int maxNumOfCoins = 5;
	int maxCoinValue = 50;
	
	//regular variables
	int v[maxNumOfCoins];
	int c[maxNumOfCoins];
	int a, m;	//start value
	
	//prep arrays
	for(int x = 0; x < maxNumOfCoins; x++)
	{
		c[x] = 0;
		v[x] = 0;
	}

	//ask user for file or random generator
	printf("What do you want to run:\n");
	printf("1) Load from File\n");
	printf("2) Random Generator\n");
	
	//Get user input
	scanf ("%[^\n]%*c", userInput);
	
	if (strcmp(userInput,"1") == 0)
	{
		//Run LoadFile
	}
	else if (strcmp(userInput,"2") == 0)
	{
		//Run Random Generator
		randomNum(&v, &a, maxNumOfCoins, maxCoinValue, maxValue);
	}
	
	//run Greedy
	v[0] = 1;
	v[1] = 5;
	v[2] = 10;
	v[3] = 25;
	v[4] = 50;


	
	const char* outfilename;
	outfilename = "vt2Results.txt";
	fp = fopen(outfilename, "w");
	for (a = 2000; a <= 2200; a++)
	{
		start = clock();
		runGreedyAlgorithm(v, a, &c, &m, maxNumOfCoins);
		end = clock();
		elapsed_time = (float)(end - start) / (1.0*CLOCKS_PER_SEC);
		printf("%d\n", a);
		fprintf(fp,"%d %s %f %s",a, "\t", elapsed_time ,"\n");
		//printf("\nmaxNumOfCoins=%d\n", maxNumOfCoins);
		//printf("maxCoinValue=%d\n", maxCoinValue);
		//printf("maxValue=%d\n", maxValue);
		//outputResults(v, maxNumOfCoins, a, 'V');
		//printf("Elapsed time: %f seconds\n", elapsed_time);
		//printf("\nResults:\n");
		//outputResults(c, maxNumOfCoins, m, 'C');
	}
	// printf("Enter filename: ");
	// fgets(filename, 99, stdin);
	// char *p = strchr(filename, '\n'); // p will point to the newline in filename
	// if(p) *p = 0; // if p is not null, terminate filename at p
	
	// fp = fopen(filename, "r");
	
	// if(!fp)
		// perror("File not found");
	// else
	// {
		// printf("opening file: %s...\n", filename);
		// while ((read = getline(&line, &len, fp)) != -1) {
			// if (n == 1)
			// {
				// numLine = (char *) realloc (numLine, strlen(line)+1);
				// strncpy(numLine, line, strlen(line));
				// *p = strchr(numLine, '\n'); // p will point to the newline in filename
				// if(p) *p = 0; // if p is not null, terminate filename at p
				
			// }
			// if (n == 2)
			// {
				// printf("n=2\n");
				// printf("strlen=%d\n",strlen(line));
				// valueLine = (char *) realloc (valueLine, strlen(line)+1);
				//strncpy(valueLine, line, strlen(line));
			// }
			// n++;
		// }
    // }
 
	// printf("numLine=%s\n", numLine);
	// printf("valueLine=%s\n", valueLine);

 
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
	//fclose(fp);
	
	//Exit
	printf("\nHave a nice day.\n");
	return 0;
}

