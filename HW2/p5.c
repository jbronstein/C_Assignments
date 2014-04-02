#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void alphabetize(char *text[], int nlines);


int main (){

	int i, f, j, count;
	
	/*malloc all pointers*/
	char **input = (char **) malloc (sizeof(char*) * 10000);
	for ( i = 0; i< 10000; i++){
		*(input+i) = (char*) malloc (sizeof(char) * 10000);
	}

	j = 0;
	i = 0;
	/*take in each char until '\n' and then move to next pointer*/
	while ((f = getchar()) != EOF){
		if ((f != '\n')){
			*(*(input + j) + i) = f;
			i++;	
		}

		else{
			*(*(input + j) + i) = '\0';				
			i = 0;
			j++;
			count++; 
		}
	}
	/*have to add termination at last string */
	*(*(input + j) + i) = '\0';
	
	alphabetize (input, count + 1);
	
	free (input);
	
	return 0;
}

void alphabetize(char *text[], int nlines){
	int i;
	int j;
	int check;
	char *swap;
	
	/*bubble sort the array, then print*/
	for (i = 0; i < nlines; i++){
		check = 0;
		for (j = 0; j < nlines - 1; j++){
			check = (strcmp(text[j],text[j+1]));
				if (check > 0){
				swap = *(text + j + 1);
				*(text + j + 1) = *(text + j);
				*(text + j) = swap;	
			}
		}
	}
	for (i = 0; i< nlines; i ++){
		printf("%s\n", *(text + i));
	}
}

