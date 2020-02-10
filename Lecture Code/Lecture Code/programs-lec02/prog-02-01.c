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

void print_message(void); //this is function ...

int main(void) {

	int num;
	const int n=5;

	num = 7;
	num = n*4;

	print_message();     //this is function ...
	printf("My favorite number is %d.\n", num);
	printf("My favorite number is %#x.\n", num);

	return 0;
}

void print_message(void) //this is function ...
{
	printf("I am a simple computer.\n");
}

