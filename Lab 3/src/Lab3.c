#include <stdio.h>
#include "io.h"

//#define _CRT_SECURE_NO_WARNINGS

#define BUFFER_SIZE 64

#define MIN     0
#define MAX     1
#define ODD     2
#define EVEN    3
#define MINMAX  4
#define ODDEVEN 5

// prototypes of your functions you need to write

// this function fills input buffer using values
// obtained with the function get_value()
void reading(int[]);

// this function performs processing of data in local buffer
// and put results back into local buffer
void processing(int[]);

// this function transfers data between two buffers
// it is used to transfer data from input buffer to local buffer
// and to transfer data from local buffer to output buffer
void transferring(int[], int[]);

// this function submit the results stored
// in output buffer for validation
void submitting(int[]);


// two functions provided to you (defined in io.h and io.c) are:
// int get_value(void);
//       this function generates a single value
//       you use it to obtain this value and put it into an input buffer
// int submit_result(int[]);
//       you use this function to submit the data processing results
//       for validation (your results are checked inside this function)


int main(void) {
    
    int inputBuffer[BUFFER_SIZE] = {0};
    int localBuffer[BUFFER_SIZE] = {0};
    int outputBuffer[BUFFER_SIZE]= {0};

    reading(inputBuffer);

    while (inputBuffer[0] != -1) {

      transferring(inputBuffer,localBuffer);
      processing(localBuffer);
      transferring(localBuffer,outputBuffer);
      submitting(outputBuffer);

      reading(inputBuffer);
    }
    return 0;
}

void reading(int inputBuffer[]) {
  // operation id
  inputBuffer[0] = get_value();
  // number of data points
  inputBuffer[1] = get_value();
  // get the rest of the data points into the buffer
  for (int i = 0; i < inputBuffer[1]; i++) {
    inputBuffer[i + 2] = get_value();
  }
  
}

void processing(int localBuffer[]) {
  // set the first number as both min and max
  int min = localBuffer[2]; 
  int max = localBuffer[2];
  int evenCount = 0, oddCount = 0;
  
  for (int i = 0; i < localBuffer[1]; i++) {
    int num = localBuffer[i + 2];
    // checks if number is odd or even
    if (num % 2) {
      oddCount++;
    } else {
      evenCount++;
    }
    // checks if number is less than min
    // or greater than max
    if (num < min) {
      min = num;
    } else if (num > max) {
      max = num;
    }
  }
  // operation id
  int op = localBuffer[0];
  // IF ELSE IF MASTER RACE
  // SWITCH STATEMENTS SUCK
  // IN C/C++ PLS NEVER USE THEM
  if (op == MIN) {
    localBuffer[2] = min;
  } else if (op == MAX) {
    localBuffer[2] = max;
  } else if (op == ODD) {
    localBuffer[2] = oddCount;
  } else if (op == EVEN) {
    localBuffer[2] = evenCount;
  } else if (op == MINMAX) {
    localBuffer[2] = min;
    localBuffer[3] = max;
  } else if (op == ODDEVEN) {
    localBuffer[2] = oddCount;
    localBuffer[3] = evenCount;
  }
  // puts the number of values acquired in the second element
  if (op < MINMAX) {
    localBuffer[1] = 1;
  } else {
    localBuffer[1] = 2;
  }

}

void transferring(int sourceBuffer[], int destinationBuffer[]) {
  // best way to copy with what they've give you
  for (int i = 0; i < BUFFER_SIZE; i++) {
    destinationBuffer[i] = sourceBuffer[i];
  }
}

void submitting(int outputBuffer[]) {
  if(submit_results(outputBuffer)) {
    printf("Results are incorrect\n");
  } else {
    printf("Results are correct\n");
  }
}