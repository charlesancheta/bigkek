/*
 ============================================================================
 Name        : Lecture09-01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void interchange(int u, int v); /* prototype of function */


int main(void)
{
 int x = 5, y = 10;

 printf("Originally:                x = %d  and y = %d.\n", x , y);
 interchange(x, y);
 printf("Now (after function):      x = %d  and y = %d.\n", x, y);

 return 0;
}

void interchange(int u, int v) /* define function */
{
 int temp;

 temp = u;
 u = v;
 v = temp;

 printf("Function (after exchange): u = %d and v = %d\n", u, v);

}

