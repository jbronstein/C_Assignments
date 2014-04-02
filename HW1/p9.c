#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ascii[1000]; /*array of chars to keep track of each individual value inputted*/

int atoi2 (char ascii[]);

int main (int argc, char **argv){
	int i, j, sum;
	j = sum = 0;
	for (i = 1; i < argc; i++){ /*for loop that sends each char to my atoi2 function*/
		j = atoi2(argv[i]);			
		
		if(j == 0){  /*if atoi2 returns 0, that means its a normal unsigned integer*/
			j = atoi(argv[i]);
			sum = sum + j; /*add the value to determe total sum*/
		}
		else if(j == -1){ /* atoi2 returns -1, that means there was nonnumeric value*/
			printf("ERROR: -1\n");
			return 0;	
		}
		else if(j == -2){ /* atoi2 returns -2, the it found a decimal value*/
			printf("ERROR: -2\n");
			return 0;
		}
	}
	printf("%i\n", sum);
	return 0;
	
}

int atoi2 (char ascii[]){ /*check each char of the array from the given unsigned integer*/
	int a;
	a = 0;
	for (a = 0; a < strlen(ascii); a++){ /*use length of array for loop to find ascii value*/
		if (ascii[a] == 46){ /*start with most specific case, the decimal ascii value 46*/
			return -2;	
		} 
		else if(ascii[a] < 48 || ascii[a] > 57){ /*if char is not 0-9, then return nonnumeric value error*/
			return -1;			
		}
	}
	return 0; /*return 0 if it passes both tests*/
}
