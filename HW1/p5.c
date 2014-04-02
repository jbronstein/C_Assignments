#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD 1000
#define MAX_CHAR_PER_WORD 1000

FILE *fh;
char text[MAX_WORD][MAX_CHAR_PER_WORD];
char word[MAX_WORD][MAX_CHAR_PER_WORD]; 
void compareTo(int count);

int main(int argc, char **argv){
int count,i,j,f,x;
count = i  = j = f = x = 0;
fh = fopen(argv[1], "r");
/*use while loop to read through file and assign text string to word array*/
while ((f = fgetc(fh)) != EOF){
	
	if((f != ' ') && (f != '\n')){
		text[i][j] = f;
		j++;
	}

	else{
		text[i][j] = '\0';
		strcpy(word[x], text[i]);
		i = 0;
		j = 0;
		x++;
		count++;
	}
}
/*run function to compare char then words and output*/
	compareTo(count);

	return 0;
}

/* huge nest loop function to check if char next is same then to check # word matches*/
void compareTo(int count){
	int i, j, len, matches, check;
	i  = j = len = matches = check = 0;

	for (i = 0; i < count; i++){
		int newStart; /* dont want to recount initial words*/
		len = strlen(word[i]); /*length of word*/
		
		for (j = 0; j < (len - 1); j++){ 
			newStart = i;
			
			if (word[i][j] == word[i][j+1]){ /*now compare words*/
				printf("%s : ", word[i]);
				
				for (check = newStart; check < count; check++){
					
					if ((strcmp(word[i], word[check+1])) == 0){
						matches++;
						word[check+1][0] = '\0';
					}
				}
				printf("%i\n", matches+1);
			}
		}
	}
}
