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
    char fkey_path[] = "/home/chaari/AC/MEGAsync/AC/AC_Teaching/ECE-220_2019/Labs/Lab2/Lab2_Code/Key.dat";
    char fin_path[]  = "/home/chaari/AC/MEGAsync/AC/AC_Teaching/ECE-220_2019/Labs/Lab2/Lab2_Code/Raw.dat";
    char fout_path[] = "/home/chaari/AC/MEGAsync/AC/AC_Teaching/ECE-220_2019/Labs/Lab2/Lab2_Code/output.dat";
       
    unsigned char buf_in[FROM_SIZE];
    unsigned char buf_out[TO_SIZE];
    char keys[64];
    int count;
    int total_char;

    // cLion/xCode version
    fkey=fopen(fkey_path,"r");
    if (fkey == NULL) {
        printf("The file cannot be found\n");
        return ERR;
    }
    // Visual Studio version
    // definting errno_t err; at the top
    // err = fopen_s(&fkey, fkey_path, "r+b");
    // if (err) {
    //   printf("The file cannot be found\n");
    //   return ERR;
    // }


    //load Key.dat




    // closing file
    fclose(fkey);
    
    // cLion/xCode version
    fin=fopen(fin_path,"r");
    if (fin == NULL) {
        printf("The file cannot be found\n");
        return ERR;
    }
    // Visual Studio version
    // err = fopen_s(&fin, fin_path, "r+b");
    // if (err) {
    //   printf("The file cannot be found\n");
    //   return ERR;
    // }
    
    // cLion/xCode version
    fout=fopen(fout_path,"w");
    if (fout == NULL) {
        printf("The file cannot be found\n");
        exit(ERR);
    }
    // Visual Studio version
    // err = fopen_s(&fout, fout_path, "w+b");
    // if (err) {
    //   printf("The file cannot be found\n");
    //   return ERR;
    // }

    
    // Conversion from ASCII to Base64

    
    
    
    // Saving Base64 text into a file

    

    
    // closing files
    fclose(fin);
    fclose(fout);

    return 0;
}
