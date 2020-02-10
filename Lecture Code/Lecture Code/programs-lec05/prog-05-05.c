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
	int n = 3;

	while (n) {
		printf("%2d is true\n", n--);
	}
	printf("%2d05 is false\n", n);

	return 0;
}
