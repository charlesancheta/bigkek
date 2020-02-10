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

#define ADJUST 7.64
#define SCALE 0.325

int main(void) {

	double shoe, foot;

	shoe = 9.0;
	foot = SCALE * shoe + ADJUST;
	printf("Shoe size (men's)    foot length\n");
	printf("%10.1f %15.2f inches\n", shoe, foot);
	return 0;

}
