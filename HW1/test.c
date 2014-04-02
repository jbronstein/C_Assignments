#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){


	/*        */
	char a [100] = "Hey There";

	char * b = a;
	int i, j;

	b = "FINE and DANDY";

	i = sizeof(b);
	j = sizeof(a);	

	char str[100];

	strcpy(str, "Both A and B: ");
	strcat(str, a);
	strcat(str, b);

	printf("A %s	%d\n", a, j);

	printf("B %s	%d\n", b, i);

	printf("String:  %s\n", str);
	return 0;
}
