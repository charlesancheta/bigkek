#include <stdio.h>
#include <stdlib.h>

int roll() {
  return 2 * (rand() % 3) + 1; // rolls either 1, 3, or 5
}

int main() {
  srand(time(0)); // uses current time as random seed
  int x; // initialize number of rols
  int rollsum;
  int freqs[5] = {}; // initializes array of zeros
  unsigned int sum = 0; // sum to calculate mean
  scanf("%d", &x);
  for (int i = 0; i < x; i++) {
    rollsum = roll() + roll(); // rolls two dice
    freqs[rollsum/2 - 1]++;
    sum += rollsum;
  }
  printf("Sum  Frequency\n");
  for (int i = 0; i < 5; i++) {
    printf("%2d %8d\n", 2*(i+1), freqs[i]);
  }
  printf("Mean value is: %d\n", sum/x);
  return 0;
}
