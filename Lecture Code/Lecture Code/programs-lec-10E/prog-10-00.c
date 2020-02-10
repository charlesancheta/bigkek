/*
 ============================================================================
 Name        : lecture-10.c
 Author      : mr
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int sump(int *start, int *end);

int *create_array(int);


int main(void)
{
 //int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
 int *marbles;
 long answer;

 marbles = create_array(SIZE);

 marbles[4] = 3;
 *(marbles + 7) = 5;

 answer = sump(marbles, marbles+SIZE);
 printf("The total number of marbles is %ld.\n", answer);
 printf("The size of marbles is %zd bytes.\n", sizeof marbles);

 return 0;
}

int *create_array(int size_arr) {

	int *array;

	array = (int *)malloc(size_arr*sizeof(int));

	array[0] = 20;

	return(array);
}


int sump(int *start, int *end)
{
 int total = 0;

 while( start < end) {
    *start += 2;
    printf("%p\n", start);
    start++;

 }
 return total;
}
