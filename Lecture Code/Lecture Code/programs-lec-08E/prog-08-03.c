/*
 ============================================================================
 Name        : lecture-08.c
 Author      : mr
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>

int imax(int, int); /* prototype */

int main(void)
{
 printf("The maximum of %d and %d is %d.\n", 3, 5, imax(3, 5));
 printf("The maximum of %d and %d is %d.\n", 3, 5, imax(3.5, 5.7));

 return 0;
}

int imax(int n, int m)
{
 int max;

 if (n > m) {
        max = n;
 }
 else {
	 max = m;
 }
 return max;
}
