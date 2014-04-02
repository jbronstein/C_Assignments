#include <stdio.h>
#include <stdlib.h>

char* my_strcat (char *cat, char *src);
char* my_strncpy (char *s1, char *s2, int n);
char* my_strncat (char *endWord, char *add, int n);
int my_strncmp (char *first, char *second, int n);
 
int main(void)
{
	char * A = "Hello!";
	char * B = "Hello from Chicago";
	char * C = " Excellent. Perfect.";

	char result[1024] = "Hi ";

	printf("Test 1: ");
	printf("%s\n", my_strcat(result, A));
	   
	   printf("Test 2: ");
	   printf("%s\n", my_strncpy(result, B, 2));

	   printf("Test 3: ");
	   printf("%s\n", my_strncpy(result, B, 100));

	   printf("Test 4: ");
	   printf("%s\n", my_strncat(result, C, 10));

	   printf("Test 5: ");
	   printf("%d\n", my_strncmp(A, B, 5));

	   printf("Test 6: ");
	   printf("%d\n", my_strncmp(A, B, 10));

	return 0;
}

/*copy the cat array directly, then append the src array to the end */
char* my_strcat(char *cat, char *src){
	int i;
	i = 0;
	while (*cat != '\0'){
	cat++;
	i++;
	}
	while((*cat = *src) != '\0'){
	cat++;
	src++;
	i++;		
	}	
	return (cat - i); /*must subtract by i to return to start memory address*/
}

/*copy over the s2 array to s1 for n characters*/
char* my_strncpy(char* s1, char* s2, int n){
	int i;
	i = 0;
	while ((*s1 = *s2) != '\0' && n>1){
		s1++;
		s2++;
		i++;
		n--;
	}

return s1 - i; 
}
/*start with endWord, then append the add array for n characters */
char* my_strncat(char* endWord, char* add, int n){
	int j;
	j = 0;
	while (*endWord != '\0'){
		endWord++;
		j++;
	}

	while ((*endWord = *add) != '\0' && n > 1) {
		endWord++;
		add++;
		j++;
		n--;
	}

return endWord - j;
}

/*keep comparing each character n times. If they don't match return 1, else return 0 */
int my_strncmp(char *first, char *second, int n){
	int i;
	for (i = 0; i < n; i++){
		if(*first != *second){
			return 1;
		}
		else{
			first++;
			second++;
		}						
	}
return 0;
}

