/*
 ============================================================================
 Name        : lecture-05.c
 Author      : mr
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void)
{
	long num;
	long sum = 0L;
	_Bool input_is_good;

	printf("Please enter an integer to be summed ");
	printf("(q to quit): ");
	input_is_good = (scanf("%ld", &num) == 1);

	while (input_is_good) {
		sum=sum+num;
		printf("Please enter next integer (q to quit): ");
		input_is_good = (scanf("%ld", &num) == 1);
	}
	printf("Those integers sum to %ld.\n", sum);

	return 0;
}
