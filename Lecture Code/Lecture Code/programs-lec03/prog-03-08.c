/*
 ============================================================================
 Name        : lecture-03.c
 Author      : mr
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 20
#define NEG -1

int main(void)
{
	char input_str[ARR_SIZE];
	char aux_str[ARR_SIZE];

	int int_number = 0;

	float float_number_1 = 0.0;
	float float_number_2 = 0.0;

	/* IMPORTNAT
	 * RUN EACH PART individually, especially the first
	 * one that illustrates the problem
	 */

	/* the first part that illustrates the problem
	 * with scanf("%d", ...) with a non digit entry
	 */
	printf("FIRST PART: problem illustration\n");
	printf("\nEnter integer number: \n");
	scanf("%d", &int_number);
	printf("You entered floating-point number: %d\n", int_number);

	printf("\nEnter floating-point number: \n");
	scanf("%f", &float_number_1);
	printf("You entered floating-point number: %f\n", float_number_1);

	printf("\nEnter floating-point number: \n");
	scanf("%s", aux_str);
	scanf("%f", &float_number_2);
	printf("You entered floating-point number: %f\n\n", float_number_2);


	/* one of possible solutions
	 * you reads anything as a string and then you convert it to a number
	 * this solution has a problem with 0
	 */
	printf("\nSECOND PART: first solution (problem with 0)\n");
	printf("Enter 1st integer number: \n");
	scanf("%s", input_str);
	int_number = atoi(input_str);

	while(int_number <= 0) {
		printf("Enter 1st integer number again: \n");
		scanf("%s", input_str);
		int_number = atoi(input_str);
	}
	printf("You entered 1st integer number: %d\n\n", int_number);


	/* another solution
	 * you reads anything as a string and then you convert it to a number
	 * this solution solves the problem with 0
	 */
	printf("\nTHIRD PART: second solution (problem with 0 addressed)\n");
	printf("Enter 2nd integer number: \n");
	scanf("%s", input_str);
	int_number = atoi(input_str);
	if (int_number == 0 && input_str[0] != '0') {
		int_number = NEG;
	}
	while(int_number < 0) {
		printf("Enter 2nd integer number again: \n");
		scanf("%s", input_str);
		int_number = atoi(input_str);
		if (int_number == 0 && input_str[0] != '0') {
			int_number = NEG;
		}
	}
	printf("You entered 2nd integer number: %d\n", int_number);

	return 0;
}
