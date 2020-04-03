//
//

#include "bank.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "memory.h"
#include <errno.h>
#pragma warning(disable: 4996) // to disable _s function warnings on Visual Studio 
static struct account** accounts;
static int currentAccounts;
static int totalProfit;


// this function allocated memory for array of pointers to accounts
void openBank(int maxAccounts) {
  accounts = (struct account**) safe_malloc(maxAccounts * sizeof(struct account*));
}

// this function returns the total profit
int currentProfit() {
    
}

// this function updates interest on saving accounts
// and deducts fee from chequing accounts
void updateData(int day) {

}

// this function handles opening of account
void openAccount(char* message, char* name, char* type, int amount) {
  for (int i = 0; i < currentAccounts; i++) {
    if (!strcmp(accounts[i]->name, name)) {
      if (!strcmp(type, "Savings")) {
        if (accounts[i]->amount_sv < 0) {
          
        } else {
          
        }
      }
    }
  }
  
}

// this function handles deposit into account
void depositAccount(char* message, char* name, char* type, int amount) {

}

// this function handles withdrawing from account
void withdrawAccount(char* message, char* name, char* type, int amount) {

}

// this function generate report for accounts of person
void reportAccount(char* message, char* name) {

}

// this function frees all allocated memory for all accounts in bank
void closeBank() {

}
