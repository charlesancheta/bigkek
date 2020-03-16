#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define ERR -1
#define FROM_SIZE 3
#define TO_SIZE   4

// for extracting least significant bits from chars
#define LSB_2 3
#define LSB_4 15
#define LSB_6 63

int main(void) {
  
  FILE* fkey;
  FILE* fin;
  FILE* fout;

  setlocale(LC_ALL, "en_US.UTF-8");
  // replace paths (below) with the paths to files at your machine
  char fkey_path[] = "/home/charles/COMPELYF/bigkek/yuwulabv2/lab2/Key.dat";
  char fin_path[]  = "/home/charles/COMPELYF/bigkek/yuwulabv2/lab2/Raw.dat";
  char fout_path[] = "/home/charles/COMPELYF/bigkek/yuwulabv2/lab2/output.dat";
      
  unsigned char buf_in[FROM_SIZE];
  unsigned char buf_out[TO_SIZE];
  char keys[64];
  int count = 0;

  // getting Base64 key
  fkey=fopen(fkey_path,"r");
  if (fkey == NULL) {
    printf("The file cannot be found\n");
    return ERR;
  }
  fread(keys, 1, 64, fkey);
  // closing file
  fclose(fkey);
  
  // opening input and output files
  fin=fopen(fin_path,"r");
  if (fin == NULL) {
    printf("The file cannot be found\n");
    return ERR;
  }

  fout=fopen(fout_path,"w");
  if (fout == NULL) {
    printf("The file cannot be found\n");
    exit(ERR);
  }
  
  // read first 3 bytes from text file
  int bytesRead = fread(buf_in, 1, FROM_SIZE, fin);

  // regular case where bytes read == 3
  while (bytesRead == FROM_SIZE) {
    unsigned int num = 0;
    // creates 24 bit num from 3 ASCII chars
    for (int i = 0; i < FROM_SIZE; i++) {
      num <<= 8;
      num |= buf_in[i];
    }

    // Conversion from ASCII to Base64
    for (int i = TO_SIZE - 1; i >= 0; i--) {
      // get 6 LSB to encode to Base 64
      buf_out[i] = keys[num & LSB_6]; 
      num >>= 6; // shift to get next 6 bits
    }

    // Saving Base64 text into a file
    fwrite(buf_out, 1, TO_SIZE, fout);
    count++;

    // groups 8 Base64 characters by adding a space
    // after 2 groups of 3 ASCII chars have been read 
    if (count % 2 == 0) {
      
      fputc(' ', fout); 
    }

    // read next group of characters
    bytesRead = fread(buf_in, 1, FROM_SIZE, fin); 
  }
  
  // special case for when the total characters 
  // is not a multiple of 3
  if (bytesRead) {
    unsigned int num = 0;

    for (int i = 0; i < bytesRead; i++) {
      num <<= 8;
      num |= buf_in[i];
    }
    // 1 extra ASCII char: 2 Base64 + 2 padding
    // 2 extra ASCII char: 3 Base64 + 1 padding
    if (bytesRead == 1) {
      buf_out[1] = keys[num & LSB_2]; // get 2 LSB
      num >>= 2;
      buf_out[2] = '=';
    } else if (bytesRead == 2) {
      buf_out[2] = keys[num & LSB_4]; // get 4 LSB
      num >>= 4;
      buf_out[1] = keys[num & LSB_6];
      num >>= 8;
    }
    buf_out[0] = keys[num & LSB_6];
    buf_out[3] = '=';
    fwrite(buf_out, 1, TO_SIZE, fout);
  }
  
  // closing files
  fclose(fin);
  fclose(fout);

  return 0;
}
