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

int main(void) {

	const int FIRST_OZ = 37;
	const int NEXT_OZ = 23;
	int ounces;
	int cost;

	printf(" ounces cost\n");
	cost=FIRST_OZ;
	ounces= 1;
	while( ounces<=16 )
	{
		printf("%5d $%4.2f\n", ounces, cost/100.0);
		cost+=NEXT_OZ;
		ounces++;
	}


	return 0;
}
