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
#include <math.h>

int main(void)
{
	const double ANSWER = 3.14159;
	double response;
	double difference;

	printf("What is the value of pi?\n");
	scanf("%lf", &response);

	difference = fabs(response-ANSWER);
	while ( difference > 0.001) {
		printf("Try again!\n");
		scanf("%lf", &response);
		difference = fabs(response-ANSWER);
	}

	printf("Close enough.\n");

	return 0;
}
