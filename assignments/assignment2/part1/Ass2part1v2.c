// ----------------------------
// ECE 220, Winter 2020
// Assignment 2 Program 1 
// Version 2
// ----------------------------

/* 
NOTE: This program already can read any number of lines
      as it only stores the shortest and longest strings.
      Simply adding an implementation of reversing a string and 
      writing that to a file completes the requirement for Part 2.
      However, this does not use dynamically allocated memory 
      and you might get deductions. (I think it's dumb that 
      you're required to use malloc() and free() for that task.) 
*/

#include <stdio.h>
#include <string.h>

// maximum length of string that can be read from file
#define MAX_STR_LEN 128

int main() {
  FILE* file = fopen("test.txt", "r");
  // used to read from file
  char readStr[MAX_STR_LEN];

  // used to store the shortest and longest strings
  char shortStr[MAX_STR_LEN], longStr[MAX_STR_LEN];

  int counter = 0;
  fgets(readStr, MAX_STR_LEN, file);
  // first line is both the shortest and longest string
  strcpy(shortStr, readStr);
  strcpy(longStr, readStr);
  int minIndex = counter, maxIndex = counter;
  counter++;

  // keeps reading until end of file is reached 
  // i.e. when fgets() returns a null pointer
  while (fgets(readStr, MAX_STR_LEN, file) != NULL) {
    // only process the line if there is anything other than newline
    if (strlen(readStr) - 1) {

      // find the shortest and longest lines
      if (strlen(readStr) < strlen(shortStr)) {

        // read line is now the shortest line
        strcpy(shortStr, readStr);
        minIndex = counter;

      } else if (strlen(readStr) > strlen(longStr)) {

        // read line is now the longest line
        strcpy(longStr, readStr);
        maxIndex = counter;
      }
      // NOTE: this only counts the number of statements.
      // if you want the index to also count empty lines,
      // move this outside the if statement
      counter++;       
    }
  }
  fclose(file);
  
  // print results
  printf("*** Number of read statements: %d\n", counter);
  printf("*** ID of the shortest statement: %d\n", minIndex);
  printf("*** ID of the longest statement: %d\n\n", maxIndex);

  // do not count newline in character count
  printf("SHORTEST: length = %ld; statement = %s", strlen(shortStr) - 1, shortStr);
  printf("LONGEST: length = %ld; statement = %s", strlen(longStr) - 1, longStr);

  return 0;
}