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

#define SEC_PER_MIN 60

int main(void)
{
	int sec, min, left;
	printf("Enter the number of seconds (<=0 to quit): ");
	scanf("%d", &sec);

	while (sec > 0) {
		min = sec / 60.0;
		left = sec % SEC_PER_MIN;
		printf("\n%d seconds is %d minutes and %d seconds\n",sec, min, left);
		printf("\nEnter the number of seconds (<=0 to quit): ");
	    scanf("%d", &sec);
	}
	return 0;
}
