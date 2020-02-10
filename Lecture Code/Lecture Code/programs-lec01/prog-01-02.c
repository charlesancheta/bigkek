/*
 ============================================================================
 Name        : lecture-01.c
 Author      : mr
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void print_message(void);

int main(void) {

	int num;
	num = 7;

	print_message();
	printf("My favorite number is %d.\n", num);

	return 0;
}

void print_message(void)
{
	printf("I am a simple computer.\n");
}
