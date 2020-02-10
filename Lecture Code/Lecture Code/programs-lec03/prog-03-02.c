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
#include <stdlib.h>
#include <string.h>

#define ARR_SIZE 5

int main(void)
{

  int size, letters;
  char name [ARR_SIZE];

  /* this part displays addresses of three variables:
   * an array "name", an integers "size" and "letters"
   * this allows you to see their locations in the memory
   */
  printf("Address: name %p\n", name);
  printf("Address: size %p\n", &size);
  printf("Address: letters %p\n", &letters);
  
  
  /* main program */
  printf("Hi, what is your first name?\n");
  scanf("%s", name);

  printf("The name is: %s\n", name);
  letters = strlen(name);
  printf("Your first name has %d letters, \n", letters);

  size = sizeof name;
  printf("and we have %d bytes to store it in.\n", size);

  printf("The name is: %s\n", name);

  size = sizeof(double);
  printf("double needs %d\n", size);

  return 0;
}



