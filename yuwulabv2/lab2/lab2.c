#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define ERR -1
#define FROM_SIZE 3
#define TO_SIZE   4

int main(void) {
  
  FILE* fkey;
  FILE* fin;
  FILE* fout;

  setlocale(LC_ALL, "en_US.UTF-8");
  
  // replace paths (below) with the paths to files at your machine
  char fkey_path[] = "/home/charles/COMPELYF/bigkek/yuwulabv2/Key.dat";
  char fin_path[]  = "/home/charles/COMPELYF/bigkek/yuwulabv2/Raw.dat";
  char fout_path[] = "/home/charles/COMPELYF/bigkek/yuwulabv2/output.dat";
      
  unsigned char buf_in[FROM_SIZE];
  unsigned char buf_out[TO_SIZE];
  char keys[64];
  int count = 0;
  int total_char = 0;

  // cLion/xCode version
  fkey=fopen(fkey_path,"r");
  if (fkey == NULL) {
      printf("The file cannot be found\n");
      return ERR;
  }
  fread(keys, FROM_SIZE, 64, fkey);
  // closing file
  fclose(fkey);
  
  // cLion/xCode version
  fin=fopen(fin_path,"r");
  if (fin == NULL) {
      printf("The file cannot be found\n");
      return ERR;
  }

  // cLion/xCode version
  fout=fopen(fout_path,"w");
  if (fout == NULL) {
      printf("The file cannot be found\n");
      exit(ERR);
  }
  
  // Conversion from ASCII to Base64
  fread(buf_in, 1, 3, fin);

  for (int i = 0; i < 13; i++) {
    num = 0;
    for (int j = 2; j >= 0; j--) {
      num |= conv[(i * 3) + (2-j) ] << (8 * j);
    }
    for (int k = 2; k >= 0; k--) {
      char c = num & 63;
      str[(i * 3) + k] = keys[c];
      num >>= 6;
    }
  }
  
  // Saving Base64 text into a file


  
  // closing files
  fclose(fin);
  fclose(fout);

  return 0;
}
