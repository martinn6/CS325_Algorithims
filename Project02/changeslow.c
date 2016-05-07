/* -----------------------------------------------------------------------
 * CS325 Project 2
 * Author: Xisheng Wang
 * Implementation of algorithm 1, brute force
 * compile with following line with: gcc changeslow.c -o runtest
 * to run the program pass the filename.txt from command argument. 
 * -----------------------------------------------------------------------
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#define CORRECTNESS 0 //change to 1 to print out run time on screen

struct CoinChanges {
	int *coins;   //array hold the number of coins for each type of coins
	int arrSize;     //number of coin types
	int amount;      //minimal total amount of coins
};


void findChanges(struct CoinChanges *myChanges, int arrLength, int *coinsArr, int *coinCount, int startIndex, int targetAmount)
{
	int i;
	if (startIndex < 0) {		
		int totalCoins = 0;
		for (i = 0; i < arrLength; i++) {
			totalCoins += coinCount[i];
		}
		if (myChanges->amount > totalCoins){
			myChanges->amount = totalCoins;
			for (i = 0; i < arrLength; i++) {
				myChanges->coins[i] = coinCount[i];
			}
		}
		return;
	}
	if (startIndex == 0) {
		coinCount[startIndex] = targetAmount/coinsArr[startIndex];
		findChanges(myChanges, arrLength, coinsArr, coinCount, startIndex - 1, 0);
	}
	else {
		for (i = 0; i <= targetAmount/coinsArr[startIndex]; i++){
			coinCount[startIndex] = i;
			findChanges(myChanges, arrLength, coinsArr, coinCount, startIndex - 1, targetAmount - i * coinsArr[startIndex]);
		}
	}
}

void writeToFile(struct CoinChanges *myChanges, char inputFile[]) {
	int i = 0;
	char outputFileName[100];
	while (inputFile[i] != '.'){
		outputFileName[i] = inputFile[i];
		i++;
	}
	char fileName[] = "change.txt";
	int j = 0;
	while (fileName[j] != '\0') {
		outputFileName[i] = fileName[j];
		i++;
		j++;
	}
	outputFileName[i] = '\0';
	FILE *fp;
	fp = fopen(outputFileName, "a");

	if (fp == NULL) {
		printf("Error to open file");
		exit(0);
	}
	fprintf(fp, "%s\n", "Alorithm changeslow:");
	fprintf(fp, "%s", "[");
	for (i = 0; i < myChanges->arrSize; i++) {
		if (i == myChanges->arrSize - 1) {
			fprintf(fp, "%u", myChanges->coins[i]);
		} else {
			fprintf(fp, "%u, ", myChanges->coins[i]);
		}
	}
	fprintf(fp, "%s\n", "]");
	
	fprintf(fp, "%u\n\n", myChanges->amount);
	fclose(fp); 
}

void testProgram(char arr1[1000], char arr2[1000], char inputFile[]){
	char temp[1000];
	int i = 1;
	int intArr[100];
	int index = 0;
	while (arr1[i] != ']') {
		int j = 0;
		while (arr1[i] != ',' && arr1[i] != ']') {
			temp[j] = arr1[i];
			j++;
			i++;
		}
		temp[j] = '\0';
		intArr[index] = atoi(temp);
		index++;
		if (arr1[i] != ']') {
			if (arr1[i] == ' ')
				i = i + 2;
			else
				i++;
		}
	}
	int target = atoi(arr2);
	struct CoinChanges newChanges;
	newChanges.amount = INT_MAX;
	newChanges.arrSize = index;
	int *coinCount;
	coinCount = (int *)malloc(index * sizeof(int));
	newChanges.coins = (int *)malloc(index * sizeof(int));
	for (i = 0; i < index; i++) {
		newChanges.coins[i] = 0;
		coinCount[i] = 0;
	}
	double total;
	clock_t start_t, end_t, tatal_t;
	start_t = clock();
	findChanges(&newChanges, index, intArr, coinCount, index - 1, target);
	end_t = clock();
	total =  (double)(end_t - start_t)/CLOCKS_PER_SEC;
	if (CORRECTNESS == 1)	{
		printf("Run time is: %f sec\n", (double)(end_t - start_t)/CLOCKS_PER_SEC);
	}
	writeToFile(&newChanges, inputFile);
	free(newChanges.coins);
	free(coinCount);
	return;
} 

int main (int argc, char **argv) 
{
	FILE *fp;
	int buffer_size = 1024;
	if (argc < 1) {
		printf("missing command line arg\n");
		exit(0);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("File not found");
		exit(0);
	}
	int i = 0;
	char buff1[buffer_size];
	char buff2[buffer_size];
	while (!feof(fp)) {
		fgets(buff1, buffer_size, fp);
		fgets(buff2, buffer_size, fp);
		testProgram(buff1, buff2, argv[1]);
	}
	fclose(fp);
	return 0;
}