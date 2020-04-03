#include <iostream>
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
  int x, rollsum, freqs[5] = {};
  unsigned int sum = 0;
  scanf("%d", &x);
  for (int i = 0; i < x; i++) {
    rollsum = roll() + roll();
    freqs[(rollsum/2) - 1]++;
    sum += rollsum;
  }
  printf("Sum  Frequency\n");
  for (int i = 0; i < 9; i++) {
    printf("%2d %8d\n", i+2, freqs[i]);
  }
  std::cout << "Mean value is: " << sum/x << '\n';
  return 0;
}
