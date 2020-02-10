/*
 * Lecture09-11.c
 *
 *  Created on: Mar 9, 2017
 *      Author: reform
 */



#include <stdio.h>
#define SIZE 10

int sump(int *start, int *end);

int main(void)
{
 int marbles[SIZE] =
            {20,10,5,39,4,16,19,26,31,20};
 long answer;

 answer = sump(marbles, marbles+SIZE);
 printf("The total number of marbles is %ld.\n", answer);
 printf("The size of marbles is %zd bytes.\n", sizeof marbles);

 return 0;
}

int sump(int *start, int *end)
{
 int total = 0;

 while( start < end) {
    *start += 2; // *star = *star + 2;
    printf("%p\n", start);
    start++;

 }
 return total;
}
