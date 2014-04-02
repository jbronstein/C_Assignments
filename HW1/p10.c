#include <stdio.h>
#include <stdlib.h>

FILE *fh;
float array [1000];
int total = 0; /* total # of input values*/
int window = 0; /* window provided by user*/
int numZeroes = 0; /* total number of zeroes to start with for calculating average*/
void findAvg(float array[]); /* function to provide all averages in output*/

int main (int argc, char **argv){	
	int i, a;
	float v;
	window = atoi(argv[2]); 
	numZeroes = window - 1; /* total number of zeroes to start with is equivalent to window - 1 */
	i = 0;
	a = 1;
	fh = fopen(argv[1], "r");	
	while ((i = fscanf(fh, "%f", &v)) != EOF){ /*make array of floats from file, keep track of count*/
		array[a] = v;
		a++;
		total++;
	}
					
	findAvg(array); /*use array and function to find averages and print them*/

	return 0;
}

void findAvg(float array[]){ /*Broke this up into two parts based on window/ # of zeroes to use*/ 
	int diff, a, b;
	float i, j, z, avg;
	i = b = j = z = 0;
	a = 1;
 
	while (numZeroes > 0 && total > 0){ /*first part uses the proper amount of zeroes and given inputs*/
	for (diff = window - numZeroes; diff < window; diff++){
		i = i + array[diff]; /*i keeps track of total float value*/	
		avg = (i + (numZeroes * j))/window; /*compute avg*/
		numZeroes--;
		total--;
		printf("%.2f ", avg);
		}
	}
	while (total > 0){ /*Second part starts from the first element of the array and moves the window*/
		for (a = 1 + b; a < window + 1 + b; a++){
			j = j + array[a]; 	
			}
		avg = j/window;
		j = 0;/*reset j value*/
		total--;/*keep decrementing total outputs*/
		b++; /* need to keep going up the array within the window*/
		printf("%.2f ", avg);
		}
	}
