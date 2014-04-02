#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv){
	
	int i, a, b, c, d, sum;
	i = sum = a = b = c = d = 0;

	i = atoi(argv[1]); /*need to get the integer value*/
	/*below we know 255 is all "1" in binary in 4th byte, use this fact to flip all values then shift accordingly*/
	a = i & 255; /*a is the original 4th byte, flipped, then shifted to the first byte*/
	a = a << 24;
	b = i & (255 << 8);
	b = b << 8; /*b is 3rd byte flipped and moved to 2nd byte position*/
	c = i & (255 << 16);
	c = c >> 8; /*c is 2nd byte flipped and moved to 3rd byte position*/
	d = i & (255 << 24); 
	d = d >> 24; /*d is 1st byte flipped and moved to 4th byte position*/

	sum = a + b + c + d; /*add all four bytes after determining values*/

	printf("%i\n", sum); /*print out the sum*/
	
	return 0;
}
