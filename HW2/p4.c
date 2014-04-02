#include<stdio.h>
#include<stdlib.h>

void moveThroughTree(int *array, int start, int end);

void heapify(int *f, int n)
{
	int start, end;
	/*zero based array, so subtract two and find middle of array*/
	start = (n - 2)/2;
	end = n;
	/*move start from  middle of array to the beginning*/
	while (start >= 0){
		moveThroughTree (f, start, end);
		start = start - 1;
	}
}
/*here I actually heap the array*/
void moveThroughTree(int *f, int start, int end){

	int child, temp, swap, root;
	root = start;

	/*check to make sure root is in the array*/
	while (root * 2 + 1 <= end){
			child = root * 2 + 1;
			swap = root;	

			/*Check the left child value with the swap value and switch based on value*/
			if (f[swap] < f[child]){
				swap = child;
			}
			/*Then check the right child value*/
			if (f[child + 1] <= end && f[swap] < f[child+1]){
				swap = child + 1;
			}
			/*if swap and root are not equal, switch them*/
			if (swap != root){
				temp = f[root];
				f[root] = f[swap];
				f[swap] = temp;
				root = swap;
				}
			else return;
		}
}

int * allocate_array( int argc, char * argv[])
{
	int i;
	int *arr;
	arr = (int*) malloc(sizeof(int) * argc);
	/*populate array*/
	for (i = 1; i < argc; i++){
		*(arr + i - 1) = atoi(argv[i]);  
	}

	return arr;
}

int test_heap( int * f, int n)
{
	int i;
	int child_A, child_B;

	for( i = 0; i < n; i++ )
	{
		child_A = ( 2 * i ) + 1;
		child_B = ( 2 * i ) + 2;

		if( child_A < n )
			if( f[i] < f[child_A] )
				return -1;

		if( child_B < n )
			if( f[i] < f[child_B] )
				return -1;
	}

	return 1;
}

int main(int argc, char * argv[])
{
	int result;
	int i;
	int n = argc - 1;
	int * arr = allocate_array( argc, argv );
	heapify( arr, n );

	result = test_heap( arr, n );

	for( i = 0; i < n; i++ )
		printf("%d ", arr[i]);
		printf("\n");

	if( result == 1 )
		printf("Heap test success!\n");
	else
		printf("Heap test failed.\n");
	free(arr);

	return 0;
}


