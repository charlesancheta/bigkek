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

	int mice_01, mice_02;

	mice_01 = 1.6 + 1.7;
	mice_02 = (int)1.6 + (int)1.7;

	printf("the value of mice_01 is: %d\n", mice_01);
	printf("the value of mice_02 is: %d\n", mice_02);

	return 0;
}
