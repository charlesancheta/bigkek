#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define characters 300 //put a number that is way bigger than the amount of characters in a line so my code can read any file
#include "memory.h"
int main() {
  char charstr[characters]; //defining variables//
  int num=0;
  char **stringlines = (char **) my_malloc(characters * sizeof(char*));  // creating an array of strings
  char charmin[characters];
  char charmax[characters];
  int max=0; //initilizing max
  int min=500;// initilizing minimum to some arbitrary number
  int linecountmax=0; // initializing ID of the longest string
  int linecountmin=0;//initializing ID of the shortest string
  int totalnum = 1000;
  unsigned int totalchar;
  FILE *test;
  FILE *test_reversed;
  char endfile;
  char *filename = "test.txt";
  char *filerev= "test_reverse.txt";

  test_reversed=  fopen(filerev,"w"); // opening text_reversed file and reading
  test = fopen(filename, "r");
  if (test_reversed==NULL){
    printf("Could not open file");
    return 1;
  }
  if (test == NULL) {
    printf("Could not open file");
    return 1;
  }
  while(1){ //infinite loop, works for any amount of read statements//
    //read a line from the file "test" and stores it in charstr
    if (fgets(charstr,characters, test) == NULL) {break;}
    if (strlen(charstr) > 1) { // condition
      totalchar = strlen(charstr); // store length of string into total char
      stringlines[num]= (char *) my_malloc(totalchar+1 * sizeof(char));
      strcpy(stringlines[num],charstr); //copying the string from charstr and storing it into the array of strings

      if (totalchar > max) { // if total char is greater than max
        max = totalchar; // total char is the new max
        linecountmax = num; // linecount max is the line ID of the longest line
        strcpy(charmax, charstr); // copy string from charstr to charmax
      }
      if (totalchar < min) { // if total char is less than min
        min = totalchar; // total char becomes the new min
        linecountmin = num; // linecount min is the ID of the smallest line
        strcpy(charmin, charstr); // copy statement from text file and store it in char min
      }
    num++;
    }
  }
  printf("***Number of statements : %d\n",num);
  printf("***ID of the shortest Statement: %d \n",linecountmin);
  printf("***ID of the Longest Statement: %d \n",linecountmax);
  printf("SHORTEST: length = %d; statement = %s \n",min,charmin);
  printf("LONGEST: length = %d; statement = %s \n", max, charmax);

  while(num>0) {
    fprintf(test_reversed, "%s\n", stringlines[num-1]);
    my_free(stringlines[(num--)-1]);
  }
  my_free(stringlines);
  fclose(test);
  fclose(test_reversed);

  return 0;

}