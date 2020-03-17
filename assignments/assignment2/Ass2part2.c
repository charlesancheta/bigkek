// ----------------------
// ECE 220, Winter 2020
// Assignment 2 Program 2 Version 1
// ----------------------

/*
NOTE: This version does NOT use malloc() and free().
      Although it would work with any number of lines,
      You will get deductions for not using dynamic memory.
*/


#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 128

// function to reverse a string
// implementation is missing in Linux
// if you are using Windows
// try to comment this code out first and see if it works
char *strrev(char *str) {
  
  // return if NULL
  if (!str || ! *str) {
    return str;
  }
  
  // start reversing string
  int i = strlen(str) - 1, j = 0;
  char ch;
  while (i > j) {
    ch = str[i];
    str[i] = str[j];
    str[j] = ch;
    i--; j++;
  }
  return str;
}

int main() {
  // open files for input and output
  FILE* fileIn = fopen("test.txt", "r");
  FILE* fileOut = fopen("test_reverse.txt", "w");

  // use to read from file
  char readStr[BUFFER_SIZE];
  char shortStr[BUFFER_SIZE], longStr[BUFFER_SIZE];

  // reserved for first line to set min and max
  int counter = 0;
  fgets(readStr, BUFFER_SIZE, fileIn);
  strcpy(shortStr, readStr);
  strcpy(longStr, readStr);
  int minIndex = counter, maxIndex = counter;
  counter++;
  
  // write the reversed form to file
  fprintf(fileOut, "%s", strrev(readStr));


  while (fgets(readStr, BUFFER_SIZE, fileIn) != NULL) {
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
    // write reversed string on file
    fprintf(fileOut, "%s", strrev(readStr));

    counter++;
  }

  // close files
  fclose(fileIn);
  fclose(fileOut);
  
  // print results
  printf("*** Number of read statements: %d\n", counter);
  printf("*** ID of the shortest statement: %d\n", minIndex);
  printf("*** ID of the longest statement: %d\n\n", maxIndex);

  // does not count newline in character count
  printf("SHORTEST: length = %ld; statement = %s", strlen(shortStr) - 1, shortStr);
  printf("LONGEST: length = %ld; statement = %s", strlen(longStr) - 1, longStr);

  return 0;
}