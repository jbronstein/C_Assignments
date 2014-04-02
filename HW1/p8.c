#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

	int *p; 
	int x, j;
	float i; 
	x = 0;
	i = atof(argv[1]);
	p =(int *) &i;
	
	for (j = 0; j<32; j++){ /*continually compare first values to determine if 1 or 0 through bitshift every loop*/

		if (j == 1 || j == 9){ /*makes spaces at given indices to achieve SEF form for bit pattern*/
			printf(" ");
		}
		x = !((*p & 1 << 31) == 0); /*sloppy comparison but it does the trick*/
		*p <<= 1;
		printf("%i", x); /*print bit value after comparison*/ 
}
printf("\n");
return 0;
}
