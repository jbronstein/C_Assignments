#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum type{CHAR, INT, FLOAT, DOUBLE} Type;

typedef struct array{
	void *vals;          /* pointer to your data*/
	Type type;           /* type of data being stored*/
	int rank;            /* number of dimensions (must support 1, 2, and 3)*/
	int dims[3];         /* x, y, z dimensions of the array*/
} Array;

Array * array_init (int rank, int dims[], Type type); /*init new Array*/

int get_bytes(Array *arr);
int get_length(Array *arr);
void  array_print(Array * arr); /* prints Array*/
void  arr_fill(Array * arr, void *fill_value); /*sets all values to fill_value*/
void* arr_sum(Array * arr); /* sum of all elements in the Array*/
void* arr_min(Array * arr); /* minimum element in the Array*/
void* arr_max(Array * arr); /* maximum element in the Array*/
void* arr_get(Array * arr, int coords[3] ); 
void arr_set(Array * arr, int coords[3], void * val ); 

/*properly malloc based on all three dimensions, total length of the array, and type of data*/
Array * array_init (int rank, int dims[], Type type){ /*init new Array*/
	Array * arr = malloc(sizeof(Array));	
	arr -> rank = rank;
	arr -> type = type;
	arr -> dims[0] = dims[0];
	arr -> dims [1] = dims[1];
	arr -> dims [2] = dims[2];
	int numBytes = get_bytes(arr);
	int totSize = get_length(arr);
	arr -> vals = malloc(numBytes * totSize);
	return arr;
}

/*Find out which data type we are dealing with, return number of bytes*/
int get_bytes(Array *arr){

	int bytes;
	bytes = 0;
	if (arr->type == CHAR){
		bytes = sizeof(char);
	}
	else if (arr->type == INT){
		bytes = sizeof(int);
	}
	else if (arr->type == FLOAT){
		bytes = sizeof(float);
	}
	else/* if (arr->type == DOUBLE){*/
		bytes = sizeof(double);

	return bytes;
}

/*Find total length of array based on number of dimensions*/
int get_length(Array *arr){

	int length;

	if (arr -> rank == 1){
		length = arr->dims[0];
	}

	else if (arr -> rank == 2){
		length = (arr->dims[0]) * (arr->dims[1]);
	}

	else {
		length = (arr ->dims[0]) * (arr->dims[1]) * (arr ->dims[2]);
	}

	return length;
}
/*Print out array, run into problems with 2D*/
void  array_print(Array * arr){
	int i;	
	int j;
	int lengthOne;
	int lengthTwo;

	lengthOne = arr->dims[0];
	if (arr->rank == 1){
		if (arr->type == CHAR){

			for (i = 0; i<lengthOne; i++){
				printf("%c ", ((char *)arr -> vals)[i]);
			}
		}

		if (arr->type == INT){

			for (i = 0; i<lengthOne; i++){
				printf("%d ", ((int *)arr -> vals)[i]);
			}
		}
		if (arr->type == FLOAT){

			for (i = 0; i<lengthOne; i++){
				printf("%.2f ", ((float *)arr -> vals)[i]);
			}
		}
		if (arr->type == DOUBLE){

			for (i = 0; i<lengthOne; i++){
				printf("%.2f ", ((double *)arr -> vals)[i]);
			}
		}
	}
	/*I thought it made sense to jump to the next row for each dim[1] increment*/
	if (arr->rank == 2){
		lengthTwo = arr->dims[1];
		if (arr->type == DOUBLE){
			for (j = 0; j <lengthTwo; j++){
				for (i = 0; i<lengthOne; i++){	
					printf("%.2f ", ((double *)arr -> vals)[i]);
				}
				printf("\n");
			}
		}
	}
}

/*fill the array using memcpy with the fill_value provided and need to jump by the data type(bytes)*/
void  arr_fill(Array * arr, void *fill_value){
	int i;
	int length;
	int bytes;

	bytes = get_bytes(arr);
	length = get_length(arr);

	for (i = 0; i < length; i++){
		memcpy(&(arr->vals[i * bytes]), fill_value, bytes);
	}
}
/*Find sum by traversing array*/
void* arr_sum(Array * arr){
	int i;
	int length = get_length(arr);
	double *sum = malloc(sizeof(double));

	if (arr->rank == 1){
		if (arr->type == CHAR){
			int *csum = malloc(sizeof(char));
			for (i = 0; i < length; i++){
				*csum = *csum + ((char*)arr->vals)[i];
			}
			return csum;
		}
		if (arr->type == INT){
			double *isum = malloc(sizeof(int));
			for (i = 0; i < length; i++){
				*isum = *isum + ((int*)arr->vals)[i];
			}
			return isum;
		}
		if (arr->type == FLOAT){
			float *fsum = malloc(sizeof(float));
			for (i = 0; i < length; i++){
				*fsum = *fsum + ((float*)arr->vals)[i];
			}
			return fsum;
		}
		if (arr->type == DOUBLE){
			double *dsum = malloc(sizeof(double));
			for (i = 0; i < length; i++){
				*dsum = *dsum + ((double*)arr->vals)[i];
			}
			return dsum;
		}

	}
	return sum;
}
/*Find Min value by traversing array, exact same thing as arr_max)*/
void* arr_min(Array * arr){
	int i;
	int length = get_length(arr);
	double *min = malloc(sizeof(double));
	
	if (arr->rank == 1){
		if (arr->type == CHAR){
			char *cmin = malloc(sizeof(char)); 
			*cmin = 200;
			char *ctemp = malloc(sizeof(char));
			for (i = 0; i < length; i ++){
				*ctemp = ((char*)arr->vals)[i];
				if (*ctemp < *cmin){
					*cmin = *ctemp;
				}
			}
			return cmin;
		}
		if (arr->type == INT){
			int *imin = malloc(sizeof(int));
			*imin = 1000000;
			int *itemp = malloc(sizeof(int));
			for (i = 0; i < length; i ++){
				*itemp = ((int*)arr->vals)[i];
				if (*itemp < *imin){
					*imin = *itemp;
				}
			}
			return imin;
		}
		if (arr->type == FLOAT){
			float *fmin = malloc(sizeof(float));
			*fmin = 1000000;
			float *ftemp = malloc(sizeof(float));
			for (i = 0; i < length; i ++){
				*ftemp = ((float*)arr->vals)[i];
				if (*ftemp < *fmin){
					*fmin = *ftemp;
				}
			}
			return fmin;
		}

		if (arr->type == DOUBLE){
			double *dmin = malloc(sizeof(double));
			*min = 1000000;
			double *dtemp = malloc(sizeof(double));
			for (i = 0; i < length; i ++){
				*dtemp = ((double*)arr->vals)[i];
				if (*dtemp < *dmin){
					*dmin = *dtemp;
				}
			}
			return dmin;
		}
	}
	return min;
}
/*Find Max value by traversing the array, just like min*/
void* arr_max(Array * arr){ 
	double *max = malloc(sizeof(double));
	
	if(arr->rank == 1){
		int i;
		int length = get_length(arr);

		if (arr->type == CHAR){
			char *cmax = malloc(sizeof(char));
			*cmax = 0;
			char *ctemp = malloc(sizeof(char));   
			for (i = 0; i < length; i ++){
				*ctemp = ((char*)arr->vals)[i];
				if (*ctemp > *cmax){
					*cmax = *ctemp;
				}
			}
			return cmax;
		}
		if (arr->type == INT){
			int *imax = malloc(sizeof(int));
			*imax = -1000000;
			int *itemp = malloc(sizeof(int));   
			for (i = 0; i < length; i ++){
				*itemp = ((int*)arr->vals)[i];
				if (*itemp > *imax){
					*imax = *itemp;
				}
			}
			return imax;
		}
		if (arr->type == FLOAT){
			float *fmax = malloc(sizeof(float));
			*fmax = -1000000;
			float *ftemp = malloc(sizeof(float));   
			for (i = 0; i < length; i ++){
				*ftemp = ((float*)arr->vals)[i];
				if (*ftemp > *fmax){
					*fmax = *ftemp;
				}
			}
			return fmax;
		}
		if (arr->type == DOUBLE){
			double *dmax = malloc(sizeof(double));
			*dmax = -1000000;
			double *dtemp = malloc(sizeof(double));
			for (i = 0; i < length; i ++){
				*dtemp = ((double*)arr->vals)[i];
				if (*dtemp > *dmax){
					*dmax = *dtemp;
				}
			}
			return dmax;
		}
	}

	return max;
}
/*Get arr value at the coords provided*/
void* arr_get(Array * arr, int coords[3] ){
	double *ptr = malloc(sizeof(double));

	if (arr->rank == 1){
		if (arr->type == CHAR)
		{
			char *cptr = malloc(sizeof(char));
			*cptr = ((char*)arr->vals)[coords[0]];
			return cptr;
		}
		if (arr->type == INT)
		{
			int *iptr = malloc(sizeof(int));
			*iptr = ((int*)arr->vals)[coords[0]];
			return iptr;
		}
		if (arr->type == FLOAT)
		{
			float *fptr = malloc(sizeof(float));
			*fptr = ((float*)arr->vals)[coords[0]];
			return fptr;
		}
		if (arr->type == DOUBLE)
		{
			double *dptr = malloc(sizeof(double));
			*dptr = ((double*)arr->vals)[coords[0]];
			return dptr;
		}
	}

	return ptr;
}
/*set value of coords provided to the value provided*/
/*For rank 2, I believe I'm doing this correctly, but doesn't work as expected when printed*/
void arr_set(Array * arr, int coords[3], void * val ){
	int bytes = get_bytes(arr);

	if (arr->rank == 1){
		memcpy(&(arr->vals[coords[0]* bytes]), val, bytes);
	}
	if (arr->rank == 2){
		memcpy(&(arr->vals[(arr->dims[0] * coords[1] + coords[0]) * bytes]), val, bytes);
	}
}


