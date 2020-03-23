#include <stdio.h>

int main() {
  // SERIOUSLY FCK MALLOC
  // THIS IS WHAT YOU GET 
  FILE* f = fopen("test.txt", "r");
  char hi[128];
  char* read = fgets(hi, 128, f);
  char **all = (char **) malloc(1);
  all = &read;
  printf("%s", *all);
  printf("%ld\n", sizeof(char*));
  fclose(f);
}