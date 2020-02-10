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
#define SIZE 4

int main(void)
{
	int index, score[SIZE];
	int sum = 0;
	float average;

	printf("Enter %d scores:\n", SIZE);

	for(index=0; index < SIZE; index++) {
		scanf("%d", &score[index]);
	}
	for(index=0; index < SIZE; index++) {
		sum += score[index];
	}
	average = (float) sum/SIZE;
	printf("Sum of scores = %d, average = %.2f\n", sum, average);

	return 0;
	}
