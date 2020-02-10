/*
 * Lecture09-02.c
 *
 *  Created on: Mar 9, 2017
 *      Author: reform
 */


#include <stdio.h>
#include <stdlib.h>

void interchangeN(int *u, int *v); /* prototype of function */


int main(void)
{
 int x, y;

 x = 5;
 y = 10;

 printf("Originally:          x = %d and y = %d.\n", x , y);
 printf("pointer of x: %p, pointer of y: %p\n", &x, &y);
 interchangeN(&x, &y);
 printf("Now(after function): x = %d and y = %d.\n", x, y);

 return 0;
}

void interchangeN(int * u_ptr, int *v_ptr) /* define function */
{
 int temp;
 int *ptr;

 ptr = &temp;

 printf("pointer of u: %p, pointer of v: %p\n", u_ptr, v_ptr);
 printf("value of u: %d, value of v: %d\n", *u_ptr, *v_ptr);

 temp = *u_ptr;
 *u_ptr = *v_ptr;
 *v_ptr = temp;
}
