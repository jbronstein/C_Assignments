#include <stdio.h>
#include <stdlib.h>

void abs_sort(int *f, int n);
int compare(const void *a, const void *b);

int main (int argc, char **argv){

	int i;
	int *input = (int*)malloc(sizeof(int)*(argc-1));
	
	/*make array*/
	for (i = 1; i < argc; i++){
		*(input + i - 1) = atoi(argv[i]);
	}
	/*run qsort*/
	abs_sort (input, argc - 1);
	
	/*print out sorted array*/
	for (i = 0; i < argc - 1; i++){
		printf("%d ", *(input + i));
	}

	free (input);

	return 0;
}

/*qsort the array using the comparison function*/
void abs_sort(int *f, int n){

	qsort(f, n, sizeof(int), compare);

}

/*compare by subtracting the difference between b and a */
int compare(const void *a, const void *b){

	int x, y;
	x  = *(int *)a;
	y = *(int *)b;

	return (abs(y) - abs(x));
}
