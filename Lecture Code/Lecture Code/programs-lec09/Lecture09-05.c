/*
 * Lecture09-05.c
 *
 *  Created on: Mar 9, 2017
 *      Author: reform
 */


#include <stdio.h>
#define SIZE 12

int main(void)
{
 int no_data[SIZE] = {1492, 1066};
 int i;


 for (i=0; i < SIZE; i++)
	 printf("%2d%14d\n", i, no_data[i]);


 return 0;
}
