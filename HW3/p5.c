#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct array{

	int *data; /*pointer to actual data*/
	int num; /*how many elements are in the array*/
	int aSize; /*how many elements the array can hold*/

	int (*append)(struct array*, int val);
	int (*print)(struct array*);
	int (*set)(struct array*, int val, int index);
	int (*insert)(struct array*, int val, int index);
	int (*destroy)(struct array*);
	int (*valueOf)(struct array*, int element);
	int (*size)(struct array*);
	int (*capacity)(struct array*);

} ArrayList;

/* BASIC API 

   ArrayList list = NULL;
   list = ArrayList_Init(n); // init a new list with capacity n
   stat = list->append(list,val) ; // add val to end of the list
   stat = list->print(list); // simple display of list contents
   stat = list->set(list,val, index) ;// put val into index
   stat = list->insert(list, vali, index); // insert val into index (increasing ArrayList size by one, and bumping all values over)
   stat = list->destroy(list) ;//free list memory
   val = list->valueOf(list,element) ;//return value of specified element
   size = list->size(list); // return the size of the list
   capacity = list->capacity(list); // return the number of elements currently allocated by list

   FUNCTION PROTOTYPES */

ArrayList * ArrayList_Init(int n);
int append(ArrayList *list,int val);
int print(ArrayList *list);
int set(ArrayList *list, int val, int index);
int insert(ArrayList *list, int val, int index);
int destroy(ArrayList *list);
int valueOf(ArrayList *list, int element);
int size(ArrayList *list);
int capacity(ArrayList *list);


ArrayList * ArrayList_Init(int n){
	/* Dynamically allocates a new ArrayList structure with n elements */
	/* Elements do not need to be initialized to any particular value */
	/* (don't forget to assign function pointers!) */
	/* Both the size and capacity of ArrayList at this point should be n */

	/*Have to check to see if n == 0, or else I get a malloc error durring efficiency test.
	I could have probably just tested this in append rather than recopying everything twice*/
	if (n == 0){
		ArrayList *list = malloc(sizeof(ArrayList));
		list->data = malloc(sizeof(int));
		list->num = n;
		list->aSize = 1;
		list->append = append;
		list->print = print;
		list->set = set;
		list->insert = insert;
		list->destroy = destroy;
		list->valueOf = valueOf;
		list->size = size;
		list->capacity = capacity;
		return list;
		}	
	/*actual setup of array*/	
	else{
		ArrayList *list = malloc(sizeof(ArrayList));
		list->data = malloc(sizeof(int)*n); 
		list->num = n;
		list->aSize = n;
		list->append = append;
		list->print = print;
		list->set = set;
		list->insert = insert;
		list->destroy = destroy;
		list->valueOf = valueOf;
		list->size = size;
		list->capacity = capacity;
		return list;
		}
	}

int append(ArrayList *list, int val)
{
	/* increases size of list by one, and appends val to last element in
	   newly resized list */
	/* return 0 if success */
	/* return 1 if memory is not available from malloc */

	/*Check to see if we need to realloc memory, then append given value*/
	if (list->num >= list->aSize){
		list->data = realloc(list->data, 2 * list->capacity(list)*sizeof(int));
		if ((list->data) != NULL){
			list->data[list->num] = val;
			list->num++;
			list->aSize = 2 * list->aSize;
			return 0;
		}
		else {
			return 1;
		}
	}

	/*if no need to realloc, then append val to list*/
	else {
		list->data[list->num] = val;
		list->num++;
		return 0;
	}
}

int print( ArrayList *list )
{
	/* return 0 for success */
	/* return 1 if trying to print an empty list (i.e., list initialized
	   to size 0 )*/
	int i;

	if(list->num == 0){
		return 1;
	}
	
	else{
		for (i = 0; i < list->num; i++){
			printf("%i ", list->data[i]);
		}		
		printf("\n");
		return 0;
	}
}

int set( ArrayList *list, int val, int index )
{
	/* sets the value at index 'index' to 'val'. */
	/* return 0 for success */
	/* return 1 if index out-of bounds, i.e.,: index < 0 or index >= size */

	if(index < 0 || index >= list->size(list)){
		return 1;
	}
	else{
		list->data[index] = val;
		return val;
	}
}

int insert(ArrayList *list, int val, int index)
{
	/* insert val into index (increasing ArrayList size by one, and bumping all values over)*/
	/* return 0 for success */
	/* return 1 if index out-of bounds, i.e.,: index < 0 or index >= size */

	int i;
	/*check if out of bounds*/
	if(index < 0 || index >= list->num){
		return 1;
	}

	else{
		/*shift everything if don't need reallocate size and add in value at given index */
		if(list->num < list->aSize){
			for(i = list->num; i > index; i--){
				list->data[i] = list->data[i-1];
			}
			list->num++;
			list->data[index] = val;
			return 0;
		}

		/*else, check for NULL value and need to reallocate by 2 then insert value at given index*/
		else{
			if(list->data != NULL){
				list->aSize = 2 * list->aSize;
				for(i = list->num; i > index; i--){
					list->data[i] = list->data[i-1];
				}

				list->data[index] = val;
				list->num++;
				return 0;
			}
			else {
				return 1;
			}
		}
	}
}

/*Free memory*/
int destroy( ArrayList *list )
{
	free(list->data);
	free(list);
	return 0;
}

/*return  value at element index*/
int valueOf( ArrayList *list, int element )
{
	return list->data[element];
}

/*return current size of ArrayList*/
int size(ArrayList *list)
{
	return list->num;
}

/*return the total allocated array size(not all used)*/
int capacity(ArrayList *list)
{
	return list->aSize;
}

/* TEST MAIN */
int main(void)
{
	int n = 3;
	int i;
	int stat; /* Error code */
	int size;
	int val = 0;
	int capacity;


	// allocate list
	ArrayList *list = NULL;
	list = ArrayList_Init(n);
	printf("ArrayList initialized to %d elements\n", n);
	printf("Size of List = %d\n", list->size(list));
	printf("Capacity of List = %d\n", list->capacity(list));

	// Fill initial values

	list->set(list, val++, 0);
	list->set(list, val++, 1);
	list->set(list, val++, 2);

	// Print List
	stat = list->print(list); // simple display of list contents
	printf("Size of List = %d\n", list->size(list));
	printf("Capacity of List = %d\n", list->capacity(list));

	// Test append and auto-resize
	stat = list->append(list,val++) ; // add val to end of the list
	stat = list->print(list); // simple display of list contents
	printf("Size of List = %d\n", list->size(list));
	printf("Capacity of List = %d\n", list->capacity(list));

	// Some more appends
	stat = list->append(list,val++) ; // add val to end of the list
	stat = list->append(list,val++) ; // add val to end of the list
	stat = list->print(list); // simple display of list contents
	printf("Size of List = %d\n", list->size(list));
	printf("Capacity of List = %d\n", list->capacity(list));

	// Test insert
	stat = list->insert(list, val++, 1); // insert val into index (increasing ArrayList size by one, and bumping all values over)
	stat = list->print(list); // simple display of list contents
	printf("Size of List = %d\n", list->size(list));
	printf("Capacity of List = %d\n", list->capacity(list));

	// Test insert redux
	stat = list->insert(list, val++, 4); // insert val into index (increasing ArrayList size by one, and bumping all values over)
	stat = list->print(list); // simple display of list contents
	printf("Size of List = %d\n", list->size(list));
	printf("Capacity of List = %d\n", list->capacity(list));

	// Test valueOf
	stat = list->print(list); // simple display of list contents
	printf("list[0] = %d\n", list->valueOf(list,0)) ;//return value of specified element
	printf("list[1] = %d\n", list->valueOf(list,1)) ;//return value of specified element


	// Test error handling
	printf("insert error = %d\n", list->insert(list, val++, 1000));
	printf("insert error = %d\n", list->insert(list, val++, -1000));
	printf("set error = %d\n", list->set(list, val++, 1000));
	printf("set error = %d\n", list->set(list, val++, -1000));
	ArrayList *list2 = ArrayList_Init(0);
	stat = list2->print(list2);
	printf("bad print error = %d\n", stat);

	// Test efficiency
	// NOTE - grading script will kill your code if this takes > 3 seconds
	val = 0;
	printf("Efficiency test...\n");
	for( i = 0; i < 10000000; i++ )
		list2->append(list2, val++ );

	// test destroy
	stat = list->destroy(list); //free list memory
	stat = list2->destroy(list2); //free list memory

	return 0;
}




