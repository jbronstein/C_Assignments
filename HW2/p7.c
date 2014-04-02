#include <stdio.h>
#include <stdlib.h>

double **dmatrix(size_t m, size_t n);

int main (int argc, char **argv){

	int i, j;
	double input;
	double **display;

	input = atof(argv[1]);

	display = dmatrix(input, input);

	/*print 1D Array*/
	printf("Matrix with 1D indexing:\n");	
	for (i = 0; i < input*input; i++){
		if (i > 0 && i % (int)input == 0){
			printf("\n");
		}
		display[0][i] = i;
		printf("%.0f ", display[0][i]);
	}
	printf("\n");

	/*print 2D Array*/
	printf("Matrix with 2D indexing:\n");
	for (i = 0; i < input; i++){
		for (j = 0; j < input; j++){
			*(*(display+i) + j) = input*i + j;
			printf("%.0f ", *(*(display+i) + j));
		}
		printf("\n");
	}

	return 0;
}

double **dmatrix(size_t m, size_t n){

	int i;
	/*allocate memory for pointers based on size n and m (should be same)*/
	double *dmat = (double*)malloc(sizeof(double)*m*n);
	double **mat = (double**)malloc(sizeof(double*)*n);
	/*assign pointers*/
	for (i = 0; i < n; i++){
		*(mat+i) = (dmat + i*n);
	}
	return mat;
}
