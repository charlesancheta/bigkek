#include <stdio.h>

int main() {
  int fib[11]; 
  fib[0] = 0, fib[1] = 1;
  for (int i = 2; i <= 10; i++) {
    fib[i] = fib[i-1] + fib[i-2];
  }
  printf("No.  Fibonacci\n");
  for (int i = 0; i < 10; i++) {
    printf("%2d %6d\n", i+1, fib[i]);
  }
  return 0;
}