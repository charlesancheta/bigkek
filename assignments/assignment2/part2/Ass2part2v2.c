// ----------------------------
// ECE 220, Winter 2020
// Assignment 2 Program 2 
// Version 2 WORK IN PROGRESS
// ----------------------------

/*
NOTE: This version DOES use my_malloc() and my_free().
It reads
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memory.h" // for my_malloc() and my_free()

// maximum length of string that can be read from file
#define MAX_STR_LEN 256
// array size still has to be hardcoded 
// if you're not going to use realloc sorry :(
#define ARRAY_SIZE 100

int main() {
  // open files for input and output
  FILE* fileIn = fopen("test.txt", "r");
  FILE* fileOut = fopen("test_reverse.txt", "w");

  // use to read from file
  char readStr[MAX_STR_LEN];
  int counter = 0, min = 0, max = 0;
  // allocate memory for string array
  char **strArray = (char **) my_malloc(ARRAY_SIZE * sizeof(char*));
  
  // keeps reading until end of file is reached 
  // i.e. when fgets() returns a null pointer
  while (fgets(readStr, MAX_STR_LEN, fileIn) != NULL) {
    // only process the line if there is anything other than newline
    if (strlen(readStr) - 1) {
      size_t length = strlen(readStr) + 1; // +1 for null terminator
      // allocate memory for the read string
      strArray[counter] = (char *) my_malloc(length * sizeof(char));
      // copy read string to allocated memory
      strcpy(strArray[counter], readStr);
      // find the shortest and longest lines
      if (strlen(readStr) < strlen(strArray[min])) {
        // read line is now the shortest line
        min = counter;

      } else if (strlen(readStr) > strlen(strArray[max])) {
        // read line is now the longest line
        max = counter;
      }
      counter++;
    }
  }
  // print results
  printf("*** Number of read statements: %d\n", counter);
  printf("*** ID of the shortest statement: %d\n", min);
  printf("*** ID of the longest statement: %d\n\n", max);

  // does not count newline in character count
  printf("SHORTEST: length = %ld; statement = %s", strlen(strArray[min]) - 1, strArray[min]);
  printf("LONGEST: length = %ld; statement = %s", strlen(strArray[max]) - 1, strArray[max]);

  // write to file in reversed order
  while (counter > 0) {
    fprintf(fileOut, "%s\n", strArray[counter - 1]);
    // free each individual allocated memory for strings
    my_free(strArray[(counter--) - 1]);
  }
  // free string array
  my_free(strArray);

  // close files
  fclose(fileIn);
  fclose(fileOut);
  
  return 0;
}