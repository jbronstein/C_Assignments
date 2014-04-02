#include <stdio.h>
#include <stdlib.h>

int main (){

int next; /* int place holder to see each char from file*/

while ((next = getchar()) != EOF){	/* get next char until EOF*/
		if (next == '\t'){
			putchar(' '); /*put space where tabs are*/
			putchar(' '); 
		}
		else {
			putchar(next);
		}		
	}

return 0;
}
