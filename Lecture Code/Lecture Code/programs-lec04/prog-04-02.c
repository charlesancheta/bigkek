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

int main(void)
{

	double shoe, foot;

	printf("Shoe size (men's) foot length\n");
	shoe = 3.0;

	while (shoe < 18.5) {
		foot = SCALE * shoe + ADJUST;
		printf("%10.1f %15.2f inches\n", shoe, foot);
		shoe = shoe +1;
	}
	return 0;
}
