#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void extrema(float *arr, int arr_size, float* mean, float* stdev);

int main (int argc, char **argv){

int i, size;
float total, dev;
float *arr = (float *) malloc((argc - 1)*(sizeof(float)));
total = dev = 0;
size = argc - 1;
/*populate array with argv*/
for(i = 1; i < argc; i++){
	*(arr + (i - 1)) = atof(argv[i]);
	total = total + arr[i-1];
}
/*compute mean and sd*/
extrema (arr, size, &total, &dev);

printf("Mean : %.2f\n", total);
printf("Standard Deviation : %.2f\n", dev);

free(arr);

return 0;
}

void extrema(float *arr, int arr_size, float* mean, float* stdev){

int i;
float j, devTotal;
devTotal = 0;

/*find mean*/
*mean = *mean/arr_size;

/*run through array and calculate sd through math*/
for (i = 0; i < arr_size; i++){
	j = 0;
	j = *(arr+i) - *mean;
	devTotal = devTotal + j*j;
}
/*find sd*/
*stdev = sqrt(devTotal/arr_size);

}
