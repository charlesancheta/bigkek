#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// defines boolean type using enum
typedef enum {true, false} bool;
void main() {
  // uses current time as random seed
  srand(time(0));
  int guessNumber;
  // generates random number from 0 to RAND_MAX (32767) and
  // modulos it by 101 to keep it between 0 and 100
  int generatedNumber = rand() % 101;
  int guessCounter = 0;
  bool correctGuess = false;
  printf("Please guess a number: ");
  while (correctGuess != true) {
    // pointers (&) are always used when using scanf except when 
    // assigning values to arrays (e.g. strings (character arrays))
    scanf("%d",&guessNumber);
    if (guessNumber > generatedNumber) {
      printf("TOO LARGE\n");
    } else if (guessNumber < generatedNumber) {
      printf("TOO SMALL\n");
    } else {
      printf("FOUND\n");
      correctGuess = true;
    }
    if (correctGuess == false) {
      printf("Please try again: ");
    }
    guessCounter += 1;
  }
  printf("No. of tries: %d", guessCounter);
}