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
  int wrongGuessCounter = 0;
  bool correctGuess = false;
  while (wrongGuessCounter < 6 && correctGuess == false) {
    printf("Guess the number: ");
    // pointers (&) are always used when using scanf except when 
    // assigning values to arrays (e.g. strings (character arrays))
    scanf("%d",&guessNumber);
    if (guessNumber > generatedNumber) {
      printf("LOWER!\n");
      wrongGuessCounter += 1;
    } else if (guessNumber < generatedNumber) {
      printf("HIGHER!\n");
      wrongGuessCounter += 1;
    } else {
      printf("GUESSED RIGHT!\n");
      correctGuess = true;
    }
  }
  if (correctGuess == true) {
    printf("YOU WIN!\n");
  } else {
    printf("YOU LOSE!\nTHE NUMBER WAS: %d\n",generatedNumber);
    
  }
}