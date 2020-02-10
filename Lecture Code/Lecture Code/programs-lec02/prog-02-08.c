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
#include <stdlib.h>
#include <string.h>

int main(void)
{

	int rate = 0.3; 
	float value, amount = 22.5;

	value = rate*amount;
	printf("the value is %f\n", value);

	return 0;
}
