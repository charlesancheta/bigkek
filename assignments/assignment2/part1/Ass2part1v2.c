// ----------------------
// ECE 220, Winter 2020
// Assignment 2 Program 1 Version 2
// ----------------------

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 128

int main() {
  FILE* file = fopen("test.txt", "r");
  // use to read from file
  char readStr[BUFFER_SIZE];
  char shortStr[BUFFER_SIZE], longStr[BUFFER_SIZE];
  int counter = 0;

  // reserved for first line to set min and max
  fgets(readStr, BUFFER_SIZE, file);
  strcpy(shortStr, readStr);
  strcpy(longStr, readStr);
  int minIndex = counter, maxIndex = counter;
  counter++;


  while (fgets(readStr, BUFFER_SIZE, file) != NULL) {
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
    }

    counter++;
  }
  fclose(file);
  
  // print results
  printf("*** Number of read statements: %d\n", counter);
  printf("*** ID of the shortest statement: %d\n", minIndex);
  printf("*** ID of the longest statement: %d\n\n", maxIndex);
  // does not count newline in character count
  printf("SHORTEST: length = %ld; statement = %s", strlen(shortStr) - 1, shortStr);
  printf("LONGEST: length = %ld; statement = %s", strlen(longStr) - 1, longStr);

  return 0;
}