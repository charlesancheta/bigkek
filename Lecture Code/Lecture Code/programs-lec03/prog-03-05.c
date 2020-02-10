/*
 ============================================================================
 Name        : lecture-03.c
 Author      : mr
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>

#define BLURB "Authentic imitation!"

int main(void)
{
	printf("/%1s/ \n",BLURB);
	printf("/%24s/ \n",BLURB);
	printf("/%25.25s/ \n",BLURB);
	printf("/%-24.5s/ \n",BLURB);

	return 0;
}
