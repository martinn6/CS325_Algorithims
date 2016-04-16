/*********************************************************************************************
 * Student: Nick Martin
 * ONID: martinn6
 * Date: 20160403
 * Project: week 01
 * Description: Fibonacci recusive program
 * *******************************************************************************************/

#include<stdio.h>
#include <time.h>
 
int FibRecursive(int);
 
main()
{
	clock_t t;
	int n = 47, 
		a = 0,
		b = 0,
		calc = 0;
 
	for (b = 1 ; b <= n ; b++ )
	{
		t = clock();
		calc = FibRecursive(a);
		t = clock() - t;
		printf("%d\t%d\t%f\n", b, calc, ((float)t)/CLOCKS_PER_SEC);
		a++; 
	}
 
	return 0;
}
 
int FibRecursive(int n)
{
	//if zero then return zero.
	if ( n == 0 )
		return 0;
	//if only 1, then return 1.
	else if ( n == 1 )
		return 1;
	else
	//recursively calculate fib sequence.
		return ( FibRecursive(n-1) + FibRecursive(n-2) );
} 