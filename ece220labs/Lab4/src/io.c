//
// Created by chaari on 2020-03-10.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "io.h"

static FILE* inputFile;
static FILE* outputFile;

// this function opens both files: input and output
void initializeIO(char* inputFileName, char* outputFileName) {
  inputFile = fopen(inputFileName, "r");
  outputFile = fopen(outputFileName, "w");
}  

// this function reads sinlge line from the input file
// and saves the values into the input arguments
// and returns 0 very time it reads a record ( and 1 if there is no more records to read)
int readRecord(int* currentDay, char* name, char* action, char* type, int* amount) {
  char message[64];
  // eof reached
  if (fgets(message, 64, inputFile) == NULL) return 1;
  int cents;
  sscanf(message, "%d %s %s %s %d.%d", currentDay, name, action, type, amount, &cents);
  
  *amount = (*amount * 100) + cents;
  return 0;
}

// this function writes into an output file
// based on the requested format
void writeRecord(int day, char* message) {
  fprintf(outputFile, "[%3d] %s\n", day, message);
}

// this function closes the files
void closeIO() {
  fclose(inputFile);
  fclose(outputFile);
}

// this function is used to compare your output file
// with the expected output
void compare(char fileNameA[], char fileNameB[]) {
    FILE* fileA=fopen(fileNameA,"r");
    FILE* fileB=fopen(fileNameB,"r");
    int row=1;
    int col=1;
    for(;!feof(fileA) && !feof(fileB);) {
        char c1=fgetc(fileA);
        char c2=fgetc(fileB);
        if(c1!=c2) {
            break;
        }
        if(c1=='\n') {
            row++;
            col=1;
        }
        else {
            col++;
        }
    }
    if (feof(fileA) && feof(fileB)) {
        printf("{***} The two files match!\n");
    }
    else {
        printf("{###} Inconsistency at character %d of line %d.\n",col,row);
    }
    fclose(fileA);
    fclose(fileB);
}
