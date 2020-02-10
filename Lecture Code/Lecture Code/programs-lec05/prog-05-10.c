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

	const int SECRET_CODE = 13;
	int code_entered;

	do {
		printf("To enter the safe room,\n");
		printf("please type-in the secret code: ");
		scanf("%d", &code_entered);
	} while (code_entered != SECRET_CODE);

	printf("Congratulations, you are in!");

	return 0;
}
