/*
 * Lecture09-12.c
 *
 *  Created on: Mar 10, 2017
 *      Author: reform
 */

#include <stdio.h>
#include <stdlib.h> /* for malloc(), free() */

int main(void)
{
 double *ptd = NULL;
 double value;

 int max;
 int number;
 int i = 0;

 puts("What is the maximum number of type double entries?");
 scanf("%d", &max);

 ptd = (double *) malloc(max * sizeof (double));
 if (ptd == NULL) {
    puts("Memory allocation failed. Goodbye.");
    exit(EXIT_FAILURE);
 }

  puts("Enter the values (q to quit):");
  while (i < max && scanf("%lf", &value) == 1) {
	  ptd[i] = value;
	  *(ptd+i) = value;
      ++i;
  }

  printf("Here are your %d entries:\n", number = i);
  for (i = 0; i < number; i++) {
     printf("%7.2f ", ptd[i]);
  }

  puts("\nDone.");

  free(ptd);
  *ptd = 4.3;

  return 0;
 }
