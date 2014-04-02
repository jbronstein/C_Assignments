#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINES 1000

char dictionary[MAX_LINES];
char dict[10000][10000];
char tempDict[10000][10000];
char sortedWord[4];
char word[4];
FILE *fh;

void insertionSort(char str[]);

int main (int argc, char **argv){
	int i, words,a,z,x;
	int j;
	int count;
	char l;
	words = argc - 1; /*# of words provided by user*/
	i = j = a = z = count = 0;
	
	fh = fopen ("dictionary.txt", "r");
	/*create dict array of words*/		
	while ((fgets(dictionary, MAX_LINES, fh)) != NULL){	
		strcpy(dict[i], dictionary); 
		i++;
		count++;		
	}
	
	for (z = 1; z < words; z++){ /*first sort words provided by user*/
		word = atoc(argv[z]);			 	
		sortedWord[z] = insertionSort(word){ 				
		/*Now need to create temp dictionary array with sorted words*/
			for (a = 0; a < count; a++){
			tempDict[a] = insertionSort(dict[a]);
			/*need to store the memory address though of the word so it can be referenced later when outputting the actual word*/
			}
		/*Then compare sorted word to tempDict word */
		
		/*Finally, after going through dictionary, end this for loop to move on to next user word and repeat*/	
			}
		}
		
return 0;
}

/*basic pseudocode for the insertionsort, doesnt work for this program obviously*/
void insertionSort(char str[]){

	int i, j, key;
	int n = strlen(str);

	for (j = 0; j < n; j++){
		key = str[j];
		i = j - 1;
		while (i>=0 && str[i] > key){
			str[i+1] = str[i];
			i--;
		}
		str[i+1];
	}
	return str[];
}
