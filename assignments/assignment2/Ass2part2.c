// ----------------------
// ECE 220, Winter 2020
// Assignment 2 Program 2
// ----------------------

#include <stdio.h>
#include <string.h>

#include "memory.h"

#define BUFFER_SIZE 128


int main() {
  FILE* file = fopen("test.txt", "r");

  // use to read from file
  char readString[BUFFER_SIZE];
  int counter = 0;


  fclose(file);
  
  // print results
  printf("*** Number of read statements: %d\n", counter);
  printf("*** ID of the shortest statement: %d\n", minIndex);
  printf("*** ID of the longest statement: %d\n\n", maxIndex);
  printf("SHORTEST: length = %d; statement = %s", min, strArray[minIndex]);
  printf("LONGEST: length = %d; statement = %s", max, strArray[maxIndex]);

  return 0;
}