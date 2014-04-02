#include <stdio.h>
#include <stdlib.h>
#define MAX_LINES 1000
#define MAX_CHAR_PER_LINE 1000

char text [MAX_LINES][MAX_CHAR_PER_LINE]; /*array of array of char of fixed length*/
void read_file(char text[MAX_LINES][MAX_CHAR_PER_LINE]); /*function to read text array*/
FILE *fh;		

int main (int argc, char **argv){
int f;
f = 0;

fh = fopen(argv[1], "r"); /*need to open and read the file*/

while ((f = fgetc(fh)) != EOF){ /*read each char into f*/
		ungetc(f, fh);
		read_file(text); /*run function to read char by char*/
	}
fclose(fh);
return 0;
}

void read_file(char text[MAX_LINES][MAX_CHAR_PER_LINE]){

	int i; /*read in the string char by char*/
	for(i = 0; i < MAX_LINES || i == EOF; i++){
		fgets(text[i], MAX_CHAR_PER_LINE, fh);
		printf("%s", text[i]);
    }
}
