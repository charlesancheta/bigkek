/*
 * Lecture09-06.c
 *
 *  Created on: Mar 9, 2017
 *      Author: reform
 */


#include <stdio.h>
#define SIZE 12

int main(void)
{
 int no_data[SIZE] = {31,28, [4] = 31,30,31, [1] = 29};
 int i;


 for (i=0; i < SIZE; i++)
	 printf("%2d%14d\n", i, no_data[i]);


 return 0;
}
