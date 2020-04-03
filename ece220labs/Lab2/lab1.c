#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// defines boolean type using enum
typedef enum {true, false} bool;
void main() {
  // uses current time as random seed
  int counter = 0;
  int min, max, option;
  printf("Range: minimum ");
  scanf("%d", &min);
  printf("Range: maximum ");
  scanf("%d", &max);
  bool guessed = false;
  while (guessed == false) {
    int program_guessed_number = (min + max)/2;
    printf("Guessed number: %d\n", program_guessed_number);
    printf("1. TOO LARGE\n");
    printf("2. TOO SMALL\n");
    printf("3. FOUND\n");
    scanf("%d", &option);
    switch (option) {
      case 1:
        max = program_guessed_number + 1;
        counter++;
        break;
      case 2:
        min = program_guessed_number - 1;
        counter++;
        break;
      case 3:
        guessed = true;
        break;
      default:
        break;
    }
  }
  printf("FOUND IT\nNo of tries: %d", counter);
}