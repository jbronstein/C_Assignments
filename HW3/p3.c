#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MaxIterations 10000

/*Compute NR*/
double NR( double x0, void (*function)(double, double*, double*), double precision){
	/* If no root can be found, print "NO ROOT FOUND" to stdout, return -1 */
	/* If root found, return root */
	int i;
	double *ptr1 = (double *)malloc(sizeof(double));
	double *ptr2 = (double *)malloc(sizeof(double));
	double denom;
	double newtonX;	
	
	/*Run the for loop up 10000 times, if no root found by that point return NO ROOT FOUND*/
	for (i = 0; i < MaxIterations; i++){

		function(x0, ptr1, ptr2);
	
		denom = *ptr2;

		newtonX = x0 - (*ptr1)/denom;

		/*keep checking newtonX with precision*/
		if (fabs(newtonX - x0) < precision){
			return newtonX;
		}
		/*update guess each iteration*/
		x0 = newtonX;
	}
	printf("NO ROOT FOUND\n");
	return -1;
}

