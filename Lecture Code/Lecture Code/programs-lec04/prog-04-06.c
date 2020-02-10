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
	int a = 1, b = 1;
	int aplus, plusb;

	aplus = a++; // postfix
	plusb = ++b; // prefix
	printf("a   aplus   b   plusb\n");
	printf("%1d %5d %5d %5d\n", a, aplus, b, plusb);

	return 0;

}
