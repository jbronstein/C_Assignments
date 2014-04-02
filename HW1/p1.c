#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv){

int i;
int j;
j = 0;

for (i = 1; i < argc; i++){ /*look at all values user inputs, convert to int*/
	j = atoi(argv[i]); /*math below to determine if learp year */
	if ((j % 4 == 0 && j % 100 != 0) || j % 400 == 0){
		printf("%d \n", j); /* print out year if it is a leap year*/
	}
}
	return 0;

}
