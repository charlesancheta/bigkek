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
#include <stdbool.h>

typedef enum {FALSE, TRUE} BOOL;

int main(void) {

	BOOL b=TRUE;

	printf("boolvar=%d.\n", b);

	b = FALSE;
	printf("boolvar=%d.\n", b);

	return 0;
}

/*
 // or
  *
 int main(void) {

	_Bool b=true;

	printf("boolvar=%d.\n", b);

	b = false;
	printf("boolvar=%d.\n", b);

	return 0;
}
 */
