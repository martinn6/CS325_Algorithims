/*********************************************************************************************
 * Student: Nick Martin
 * ONID: martinn6
 * Date: 20160403
 * Project: week 01
 * Description: Fibonacci iterative program
 * *******************************************************************************************/

#include<stdio.h>
#include <time.h>
 
main()
{
	clock_t t;
	int n = 1000, 
		a = 0;
		
	unsigned long long	x = 0,
					y = 1,
					z = 0;
 
	for (a = 0; a < n; a++)
	{
		t = clock();
		if (a <= 1)
			z = a;
		else
		{
			z = x + y;
			x = y;
			y = z;
		}
		t = clock() - t;
		printf("%d\t%d\t%f\n",a+1,z,((float)t)/CLOCKS_PER_SEC);
   }
 
   return 0;
}
 