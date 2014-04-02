#include <stdio.h>
#include <stdlib.h>

double **dmatrix(size_t m, size_t n);

int main (int argc, char **argv){

	int i, j, count;

	double input;
	double **display;

	count = 0;
	input = atof(argv[1]);

	/*run function to malloc pointers*/
	display = dmatrix(input, input);
	
	/*print out the matrix*/
	for (i = 0; i < input; i++){
		for (j = 0; j < input; j++){
			*(*(display + j)) = count;
			printf("%.0f ", *(*(display + j)));
			count++;	
		}
		printf("\n");
	}

	return 0;
}

double **dmatrix(size_t m, size_t n){

	int i;
	double **dmat;

	/*malloc the pointers based on size n*/
	dmat = (double**)malloc(sizeof(double*)*m);
	for (i = 0; i < n; i++){
		*(dmat + i) = (double*)malloc(sizeof(double)*n); 
	}

	return dmat;
}
