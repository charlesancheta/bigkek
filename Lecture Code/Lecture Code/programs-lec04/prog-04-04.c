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
#include <string.h>

#define ARR_SIZE 10

int main(void)
{
	int n = 6;
	char m[ARR_SIZE] = "ece220";

	size_t intsize_n;
	size_t intsize_m;

	intsize_n = sizeof (int);
	intsize_m = sizeof (char);

	printf("n = %d, variable n has %zd bytes, all ints have %zd bytes.\n", n,
			sizeof (n), intsize_n);
	printf("m = %s, variable m has %zd bytes, its value has %zd characters, all chars have %zd bytes.\n", m,
			sizeof (m), strlen(m), intsize_m);
	return 0;
}
