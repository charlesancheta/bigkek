/*
 ============================================================================
 Name        : lecture-02.c
 Author      : mr
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void)
{

	// this part "tests" the concept of signed/unsigned numbers
/*
	int i;
	//char test = 0;
	// or
    unsigned char test = 0;

	for (i = 0; i<256; i++) {
		printf("i = %d, test = %d, testChar = %c\n", i, test, test);
		test = test +1;
	}
*/
	unsigned int un = 3000000000;
	short end  = 200;
	long big = 65537;
	long long verybig = 12345678908642;

	printf("un = %u and not %d\n", un, un);

	printf("end = %hd and %lld\n", end, end);

	printf("big = %ld and not %hd\n", big, big);

	printf("verybig = %lld and not %ld\n", verybig, verybig);

	return 0;
}


