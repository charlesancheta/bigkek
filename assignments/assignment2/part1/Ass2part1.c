// ----------------------
// ECE 220, Winter 2020
// Assignment 2 Program 1
// ----------------------

#include <stdio.h>
#include <string.h>

// NOTE: THIS HARDCODES A PRETTY IMPORTANT PART
// OF THE ASSIGNMENT
// PLEASE USE VERSION 2

#define BUFFER_SIZE 128
// number of lines is hardcoded
// more should be allocated depending on the file 
// although this does the job for part 1
#define NUM_LINES 18

int main() {
  FILE* file = fopen("test.txt", "r");
  // make an array of strings
  char strArray[NUM_LINES][BUFFER_SIZE];
  // use to read from file
  char readString[BUFFER_SIZE];
  int counter = 0;

  // reserved for first line to set min and max
  char* readLine = fgets(readString, BUFFER_SIZE, file);
  // copy string to the string array
  strcpy(strArray[0], readString);
  int strLen = strlen(readString) - 1;
  int min = strLen;
  int max = strLen;
  int minIndex = counter;
  int maxIndex = counter;
  counter++;

  readLine = fgets(readString, BUFFER_SIZE, file);
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
    readLine = fgets(readString, BUFFER_SIZE, file);
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