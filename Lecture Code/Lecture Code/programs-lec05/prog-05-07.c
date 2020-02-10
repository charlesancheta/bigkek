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

	const int NUMBER = 3;
	int counter = 1;
	_Bool not_done = 1;

	not_done = (counter <= NUMBER);

	while (not_done) {
		printf("Remember to ...increment counter (%d)\n", counter);
		not_done = (counter++ <= NUMBER);
	}

	return 0;
}
