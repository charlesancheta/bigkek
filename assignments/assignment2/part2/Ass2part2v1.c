// ----------------------------
// ECE 220, Winter 2020
// Assignment 2 Program 2 
// Version 1
// ----------------------------

/*
NOTE: DO NOT USE THIS CODE. I misinterpreted the 
      instructions and just reversed the strings 
      as I wrote them. Dum me 
*/

#include <stdio.h>
#include <string.h>

// maximum length of string that can be read from file
#define MAX_STR_LEN 128

/* char *strrev(char *str): reverses a string

Implementation is missing in Linux. If you are using Windows,
try to comment this code out first and see if it works. */

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
  char readStr[MAX_STR_LEN];
  char shortStr[MAX_STR_LEN], longStr[MAX_STR_LEN];

  // read first line
  int counter = 0;
  fgets(readStr, MAX_STR_LEN, fileIn);

  // first line is both the shortest and longest string
  strcpy(shortStr, readStr);
  strcpy(longStr, readStr);
  int minIndex = counter, maxIndex = counter;
  counter++;
  
  // write the reversed form of the string to fileOut
  fprintf(fileOut, "%s", strrev(readStr));

  // keeps reading until end of file is reached 
  // i.e. when fgets() returns a null pointer
  while (fgets(readStr, MAX_STR_LEN, fileIn) != NULL) {
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
      // If you want the index to also count empty lines,
      // move this outside the if statement.
      counter++; 
    }
    // write reversed string on fileOut
    fprintf(fileOut, "%s", strrev(readStr));

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