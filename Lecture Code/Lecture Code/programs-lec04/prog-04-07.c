/*
 ============================================================================
 Name        : lecture-04.c
 Author      : mr
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int count, sum;			// declaration statement

	count = 0;				// assignment statement
	sum = 0;				// assignment statement

	while (++count < 3)	// while statement (structured statements)
	//while (count++ < 3)	// while statement (structured statements)
	{
		printf("counter is: %d\n", count);
		sum = sum + count;
	}
	printf("sum = %d\n", sum); // function statement
	printf("counter is: %d\n", count);
	return 0;
}
