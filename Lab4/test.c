#include <stdlib.h>
#include <stdio.h>
#include <string.h>


FILE *fin;

int read(int* day, char* name, char* action, char *type, int* amount) {
  int cents;
  fscanf(fin, "%d %s %s %s %d.%d", day, name, action, type, amount, &cents);
  *amount = *amount * 100 + cents;
}

int main() {
  fin = fopen("sampleInput.dat","r");
  int *day, *amount;
  char name[256], action[16], type[16];
  read(day, name, action, type, amount);
  printf("%d %s %s %s %d\n", *day, name, action, type, *amount);
  return 0;
}