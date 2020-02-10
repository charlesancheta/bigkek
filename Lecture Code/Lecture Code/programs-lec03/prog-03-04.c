/*
 ============================================================================
 Name        : lecture-03.c
 Author      : mr
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(void)
{
	const double RENT = 123.45;

	printf("1- *%f*\n", RENT);
	printf("2- *%e*\n", RENT);
	printf("3- *%4.2f*\n", RENT);
	printf("4- *%3.1f*\n", RENT);
	printf("5- *%10.3f*\n", RENT);
	printf("6- *%10.3e*\n", RENT);
	printf("7- *%+4.2f*\n", RENT);
	printf("8- *%010.2f*\n", RENT);

return 0; }












