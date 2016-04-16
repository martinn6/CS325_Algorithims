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
	file thisfile;
	bool fileLoaded = 0;
	string inputFileName;
	string outputFileName;
	
	//Load file
	while(fileLoaded == 0)
	{
		//Get User Input
		cout << "\nEnter the name for the input file: ";
		getline(cin, inputFileName);
						
		//OPEN FILE 
		ifstream inputFile(inputFileName.c_str());
		//ERROR HANDELING
		if (inputFile)
		{
			cout << "\nOpening " << inputFileName << "...";
			fileLoaded=1;
			inputFile.close();
		}
		else
		{
			cout << "\nError 404: File " << inputFileName << " not found!";
		}	
	}
	
	//open inputfile	
	ifstream inputFile(inputFileName.c_str());
	
	
	
	
	//Run Test 1
	enumeration1(0);
	//Run Test 2
	//Run Test 3
	//Run Test 4
	//Close File
	//Exit
	
	return 0;
}

