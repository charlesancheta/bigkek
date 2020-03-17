// ----------------------------
// ECE 220, Winter 2020
// Assignment 2 Program 1 
// Version 1
// ----------------------------

/*
NOTE: This hardcodes the number of lines read.
      This is not necessarily a bad thing for part 1
      as they probably expect you to do this.
      Refer to the second version for an implementation 
      that does not use an array of strings.
*/

#include <stdio.h>
#include <string.h> // for strcpy()

// maximum length of string that can be read from file
#define MAX_STR_LEN 128

// number of lines is hardcoded
// more should be allocated depending on the file 
// although this does the job for part 1
#define NUM_LINES 18

int main() {
  FILE* file = fopen("test.txt", "r");
  // make an array of strings
  char strArray[NUM_LINES][MAX_STR_LEN];
  // use to read from file
  char readString[MAX_STR_LEN];
  int counter = 0;

  // reserved for first line to set min and max
  
  char* readLine = fgets(readString, MAX_STR_LEN, file);
  // copy string to the string array
  strcpy(strArray[0], readString);
  // does not count newline character in length
  int strLen = strlen(readString) - 1;
  int min = strLen;
  int max = strLen;
  int minIndex = counter;
  int maxIndex = counter;
  counter++;

  readLine = fgets(readString, MAX_STR_LEN, file);
  while (readLine != NULL) {
    strcpy(strArray[counter], readString);
    // subtract the newline from the string length
    strLen = strlen(readString) - 1;
    // only process the line if there is anything other than newline
    if (strLen) {
      // find the shortest and longest lines
      if (strLen < min) {
        min = strLen;
        minIndex = counter;
      } else if (strLen > max) {
        max = strLen;
        maxIndex = counter;
      }
    }

    counter++;
    readLine = fgets(readString, MAX_STR_LEN, file);
  }
  fclose(file);
  
  // print results
  printf("*** Number of read statements: %d\n", counter);
  printf("*** ID of the shortest statement: %d\n", minIndex);
  printf("*** ID of the longest statement: %d\n\n", maxIndex);
  printf("SHORTEST: length = %d; statement = %s", min, strArray[minIndex]);
  printf("LONGEST: length = %d; statement = %s", max, strArray[maxIndex]);

  return 0;
}