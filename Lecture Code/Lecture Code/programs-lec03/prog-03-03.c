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
#include <string.h>

#define SIZE 40

#define STATEMENT "What a very nice name."

int main(void){

  char name [SIZE] = "What a very nice name.";

  printf("The statement has %d letters, \n and ", strlen("What a very nice name."));
  printf("occupies %d memory cells.\n", sizeof("What a very nice name."));

  printf("\nThe name has %d letters, \n and ", strlen(name));
  printf("occupies %d memory cells.\n", sizeof(name));
}
