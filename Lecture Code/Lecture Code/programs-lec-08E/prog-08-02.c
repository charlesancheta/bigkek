/*
 ============================================================================
 Name        : lecture-08.c
 Author      : mr
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <string.h> /* for strlen() */

#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40
#define SPACE '-'

void show_n_char(char ch, int num);

int main(void)
{
 int spaces;

 show_n_char('*', WIDTH);					/*using constants as arguments */
 putchar('\n');

 show_n_char(SPACE, 12);					/*using constants as arguments */
 printf("%s\n", NAME);

 spaces = (WIDTH - strlen(ADDRESS)) / 2;	/* Let the program calculate how many spaces */
 show_n_char(SPACE, spaces);				/* use a variable as argument */
 printf("%s\n", ADDRESS);

 show_n_char(SPACE, (WIDTH - strlen(PLACE)) / 2);	/* expression as argument */
 printf("%s\n", PLACE);

 int num;
 num = 8;

 show_n_char('*', WIDTH); putchar('\n');

 return 0;
}

void show_n_char(char ch, int num)
/* show_n_char() definition */
 {
 int count;
 for (count = 1; count <= num; count++)
	 putchar(ch);
}
