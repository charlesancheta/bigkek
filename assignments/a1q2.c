#include <stdio.h>
#include <stdlib.h>

int roll() {
  return 2 * (rand() % 3) + 1;
}

int testroll() {
  for (int i = 0; i < 10; i++){
    printf("%d\n", roll());
  }
}

int main() {
  srand(time(0));
  int x, rollsum, freqs[9] = {};
  unsigned int sum = 0;
  scanf("%d", &x);
  for (int i = 0; i < x; i++) {
    rollsum = roll() + roll();
    freqs[rollsum - 2]++;
    sum += rollsum;
  }
  printf("Sum  Frequency\n");
  for (int i = 0; i < 9; i++) {
    printf("%2d %8d\n", i+2, freqs[i]);
  }
  printf("Mean value is: %d\n", sum/x);
  return 0;
}
