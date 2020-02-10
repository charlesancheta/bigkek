/*
 * Lecture09-04.c
 *
 *  Created on: Mar 9, 2017
 *      Author: reform
 */


#include <stdio.h>
#define MONTHS 12

int main(void)
{
 int days[MONTHS] ={0};
 int index;

 for (index = 0; index < MONTHS; index++)
   printf("Month %d has %2d days.\n", index +1, days[index]);
 return 0;

}

