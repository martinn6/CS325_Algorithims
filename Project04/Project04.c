/*********************************************************************************************
 * Developers: Nick Martin (martinn6)
 *             Xisheng
 * 			   
 * Date: 20160422
 * Project: Project 04
 * Description: Implement a greedy algorithm.
 * *******************************************************************************************/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct cities {
	int id;
	int x;
	int y;
};


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
	printf("\nmaxNumOfCoins=%d\n", maxNumOfCoins);
	printf("maxCoinValue=%d\n", maxCoinValue);
	printf("maxValue=%d\n", maxValue);
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
		//slowDown();	//slowing down the function so I can track its time.
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

/**********************************************************
Name: printResults()
Description: outputs the results to screen in the format:
	[ArrayName] = [n0, n1, ... n[Array.Length]]
**********************************************************/
int printResults(int c[], int length, int m, char arrayName, char filename[])
{
	int p;
	FILE *fp;
	char outfilename[99];
	char *pch;
		
	strcpy(outfilename, filename);
	pch=strchr(outfilename,'.');
	p = pch-outfilename;
	if(p)
	{
		outfilename[p]='c';
		outfilename[p+1]='h';
		outfilename[p+2]='a';
		outfilename[p+3]='n';
		outfilename[p+4]='g';
		outfilename[p+5]='e';
		outfilename[p+6]='.';
		outfilename[p+7]='t';
		outfilename[p+8]='x';
		outfilename[p+9]='t';
		outfilename[p+10]='\0';
	}
	else
	{
		p = 0;
		outfilename[p]='c';
		outfilename[p+1]='h';
		outfilename[p+2]='a';
		outfilename[p+3]='n';
		outfilename[p+4]='g';
		outfilename[p+5]='e';
		outfilename[p+6]='.';
		outfilename[p+7]='t';
		outfilename[p+8]='x';
		outfilename[p+9]='t';
		outfilename[p+10]='\0';
	}

	printf("outfilename=%s\n", outfilename);
	fp = fopen(outfilename, "w");
	fprintf(fp, "%c", arrayName);
	fprintf(fp, "%s","=[");
	for (int x = 0; x < length; x++)
	{
		fprintf(fp, "%d", c[x]);
		if(x != length-1)
			fprintf(fp, "%s", ", ");
	}
	fprintf(fp, "%s", "]\n");
	fprintf(fp, "%d %s",m, "\n");
	fclose(fp);
	return 0;
}

/**********************************************************
Name: parseNumLine()
Description: outputs the results to a file in the format:
	[ArrayName] = [n0, n1, ... n[Array.Length]]
**********************************************************/
int parseLine(struct cities *city, char line[1024])
{
	int x = 0;
	
	//parse numbers from lines into array
	char *pt;
	pt = strtok(line,",");
	while (pt != NULL) {
		if (pt[0] == '[')
			pt[0] = ' ';
		v[x] = atoi(pt);
		printf("v[x]=%d",v[x]);
		pt = strtok (NULL, ",");
		x++;
	}

	return(0);
}


int main()
{
	//Declare Variables
	cities city[1000];
	FILE *fp;
	char *line;
    size_t len = 0;
    ssize_t read;
	char filename[99];
	char numLine[1024];
	char *userInput = (char*) malloc(100);
	int value;
	int n = 0;

	//ask user for file or random generator
	printf("Enter filename: ");
	fgets(filename, 99, stdin);
	char *p = strchr(filename, '\n'); // p will point to the newline in filename
	if(p) *p = 0; // if p is not null, terminate filename at p
	
	fp = fopen(filename, "r");
	
	if(!fp)
		perror("File not found");
	else
	{
		size_t len = 0;
		ssize_t read;

		printf("opening file: %s...\n", filename);
		int n = 0;
		while ((read = getline(&line, &len, fp)) != -1) {
			parseLine(&city, line);
			printf("line=%s", line);
			n++;
		}
			
		//close file
		fclose(fp);
		//a = atoi(valueLine);
		//parseNumLine(numLine, &v, &maxNumOfCoins);
	}
	

	
	
	//start = clock();
	// runGreedyAlgorithm(v, a, &c, &m, maxNumOfCoins);
	//end = clock();
	//elapsed_time = (float)(end - start) / (1.0*CLOCKS_PER_SEC);
	//printf("%d\n", a);
	//fprintf(fp,"%d %s %f %s",a, "\t", elapsed_time ,"\n");
	// printf("\nStarting array / value:\n");
	// outputResults(v, maxNumOfCoins, a, 'V');
	//printf("Elapsed time: %f seconds\n", elapsed_time);
	// printf("\nResult array count / number of coins used:\n");
	// outputResults(c, maxNumOfCoins, m, 'C');
	// printResults(c,maxNumOfCoins, m, 'C', filename);

	
	
	
	//Exit
	printf("\nHave a nice day.\n");
	return 0;
}

