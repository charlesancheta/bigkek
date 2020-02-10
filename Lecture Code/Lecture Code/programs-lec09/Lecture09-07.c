/*
 * Lecture09-07.c
 *
 *  Created on: Mar 9, 2017
 *      Author: reform
 */


#include <stdio.h>
#define SIZE 4

int main(void)
{
  int value1 = 44;
  int arr[SIZE];
  int value2 = 88;
  int i;
  int *ptrv1, *ptrv2;

  ptrv1 = &value1;
  ptrv2 = &value2;

  printf("value1 = %d, value2 = %d\n", value1, value2);

  for (i = -1; i <= 2*SIZE; i++)
     arr[i] = 2 * i + 1;

  for (i = -1; i < 14; i++)
     printf("index[%2d]; value: %d\n", i , arr[i]);

  printf("value1 = %d, value2 = %d\n", value1, value2);

  return 0;
}
