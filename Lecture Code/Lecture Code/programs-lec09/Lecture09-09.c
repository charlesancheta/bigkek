/*
 * Lecture09-09.c
 *
 *  Created on: Mar 9, 2017
 *      Author: reform
 */


#include <stdio.h>
#define MONTHS 12

int sumg(int *ar, int n);
int sumf(int *);


int main(void)
{
 int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
 int value;
 int no_months;

 value = sumf(days);
 printf("Days in 12 months (fixed): %d\n", value);

 no_months = 8;
 value = sumg(days, no_months);
 printf("Days in %d months (generic): %d\n", no_months, value);


 return 0;
}




int sumg(int * ar, int n) 	/* generic approach array size of n*/
{
 int i;
 int total = 0;
 for( i = 0; i < n; i++)
    total += *(ar+i); 		/*like *(ar + i) */
return total;
}





int sumf(int *ar) 			/* fixed array size of 12 */
{
 int i;
 int total = 0;
 for( i = 0; i < 12; i++)
    total += ar[i];
 return total;
}
