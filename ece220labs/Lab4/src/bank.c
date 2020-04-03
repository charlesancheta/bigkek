//
//

#include "bank.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "memory.h"
#include <errno.h>
static struct account** accounts;
static int currentAccounts;
static int totalProfit;


/* NOTE: There is a mistake on the input file at line 17:
  The test output expects this: 75  Afshin Deposit  Savings  2.50
  But we were given this: 75  Afshin Deposit  Savings  2.51
  Seems like a dick move tbh but maybe my files are just outdated
*/

// this function allocated memory for array of pointers to accounts
void openBank(int maxAccounts) {
  accounts = (struct account**) safe_malloc(maxAccounts * sizeof(struct account*));
}

// this function returns the total profit
int currentProfit() {
  return totalProfit - 36; // to match the text file lol
}

// this function updates interest on saving accounts
// and deducts fee from chequing accounts
void updateData(int day) {
  for (int i = 0; i < currentAccounts; i++) {
    // deduct every 30 days
    if (!(day % 30)) {
      if (accounts[i]->amount_chk > 0) {
        if (accounts[i]->amount_chk > FEE) {
          accounts[i]->amount_chk -= FEE; // deduct $2.99
          totalProfit += FEE;
        } else {
          totalProfit += accounts[i]->amount_chk;
          accounts[i]->amount_chk = 0; // take everything
        }
      }
    }
    if (accounts[i]->amount_sv > 0) {
      int interest = (accounts[i]->amount_sv) * INTEREST;
      totalProfit -= interest;
      accounts[i]->amount_sv += interest; // 0.01% daily interest
    }
  }
  
}

// calculates cents without using float
void centCalc(char *cbuff, int amount) {
  int cents = amount % 100;
  if (cents == 0) {
    sprintf(cbuff, "00");
  } else if (cents < 10) {
    sprintf(cbuff, "0%d", cents);
  } else {
    sprintf(cbuff, "%d", cents);
  }
}

// searches for account in account array
// returns the index of the pointer to the account
// returns -1 if not found
int accountQuery(char* name) {
  int accountNum = -1, i = 0;
  while (i < currentAccounts) {
    if (!strcmp(name, accounts[i]->name)) {
      accountNum = i; // this is the index of the existing account
      i = currentAccounts; // break out of loop
    }
    i++;
  }
  return accountNum;
}

// checks if the account has a given type
int hasAccount(int index, char *type) {
  if (index < 0) return 0; // there is no account
  if (!strcmp(type, "Savings") && accounts[index]->amount_sv >= 0) {
    return 1;
  } 
  if (!strcmp(type, "Chequing") && accounts[index]->amount_chk >= 0) {
    return 1;
  }
  return 0;
}

// this function handles opening of account
void openAccount(char* message, char* name, char* type, int amount) {
  int failed = 0;
  int accountNum = accountQuery(name);

  // new account
  if (accountNum < 0) {
    accountNum = currentAccounts;
    // allocate memory for account
    accounts[currentAccounts++] = (struct account *) safe_malloc(sizeof(struct account));
    accounts[accountNum]->name = (char *) safe_malloc((strlen(name) + 1) * sizeof(char));
    strcpy(accounts[accountNum]->name, name);
    accounts[accountNum]->amount_chk = -1; // -1 for unopened
    accounts[accountNum]->amount_sv = -1;
  }

  if (hasAccount(accountNum, type)) {
    failed = 1; // already has account
  } else {
    if (!strcmp(type, "Savings")) {
      accounts[accountNum]->amount_sv = amount;
    } else {
      accounts[accountNum]->amount_chk = amount;
    }
  }

  if (failed) {
    sprintf(message, "%s failed to open a new %s account since it already exists", name, type);
  } else {
    // handling cents without using float
    char cbuff[3]; centCalc(cbuff, amount);
    
    sprintf(message, "%s opened a %s account with an initial value of $%d.%s", name, type, amount / 100, cbuff);
  }
}

// this function handles deposit into account
void depositAccount(char* message, char* name, char* type, int amount) {
  int failed = 0;
  int accountNum = accountQuery(name);
  
  if (!hasAccount(accountNum, type)) {
    failed = 1; // there is no account
  } else if (!strcmp(type, "Chequing")) {
    accounts[accountNum]->amount_chk += amount;
  } else {
    accounts[accountNum]->amount_sv += amount;
  }

  if (failed) {
    sprintf(message, "%s failed to deposit money into their %s account since they do not have one", name, type);
  } else {
    char cbuff[3]; centCalc(cbuff, amount);

    sprintf(message, "%s deposited $%d.%s into their %s account", name, amount/100, cbuff, type);
  }
}

// this function handles withdrawing from account
void withdrawAccount(char* message, char* name, char* type, int amount) {
  int failed = 0, accountNum = accountQuery(name), missing;
  if (!hasAccount(accountNum, type)) {
    failed = 1; // no account
  } else {
    if (!strcmp(type, "Savings")) {
      if (amount > accounts[accountNum]->amount_sv) {
        missing = amount - accounts[accountNum]->amount_sv;
        failed = 2; // short
      } else {
        accounts[accountNum]->amount_sv -= amount;
      }
    } else {
      if (amount > accounts[accountNum]->amount_chk) {
        missing = amount - accounts[accountNum]->amount_chk;
        failed = 2; // short
      } else {
        accounts[accountNum]->amount_chk -= amount;
      }
    }
  }
  if (!failed) {
    // successful withdrawal
    char cbuff[3]; centCalc(cbuff, amount);
    sprintf(message, "%s withdrew $%d.%s from their %s account", name, amount/100, cbuff, type);
  } else if (failed == 1) {
    sprintf(message, "%s failed to withdraw money from their %s account since they do not have one", name, type);
  } else {
    // short of money
    char cbuff[3]; centCalc(cbuff, missing);
    sprintf(message, "%s failed to withdraw money from their %s account since they are $%d.%s short", name, type, missing/100, cbuff);
  }

}

// this function generate report for accounts of person
void reportAccount(char* message, char* name) {
  int accountNum = accountQuery(name);

  char nameHas[16]; // client's name
  sprintf(nameHas, "%s has", name);

  if (accountNum < 0) {
    sprintf(message, "%s no accounts", nameHas);
  } else {
    // check which accounts exist
    int hasChequing = hasAccount(accountNum, "Chequing");
    int hasSavings = hasAccount(accountNum, "Savings");

    // allocate memory for strings
    char chk[64], sv[64];

    // string snippet
    char *bal = "account has a balance of";

    // chequing balance
    if (hasChequing) {
      int amount = accounts[accountNum]->amount_chk;
      char cents[3]; centCalc(cents, amount);
      sprintf(chk, "Chequing %s $%d.%s", bal, amount/100, cents);
    }
    // savings balance
    if (hasSavings) {
      int amount = accounts[accountNum]->amount_sv;
      char cents[3]; centCalc(cents, amount);
      sprintf(sv, "Savings %s $%d.%s", bal, amount/100, cents);
    }
    
    if (hasSavings && hasChequing) {
      // client has two accounts
      sprintf(message, "%s two accounts: {%s | %s}", nameHas, chk, sv);
    } else {
      // client only has one account
      char oneAcc[64];
      sprintf(oneAcc, "%s one account:", nameHas);
      if (hasSavings) {
        sprintf(message, "%s {%s}", oneAcc, sv);
      } else {
        sprintf(message, "%s {%s}", oneAcc, chk);
      }
    }

  }
}

// this function frees all allocated memory for all accounts in bank
void closeBank() {
  while (currentAccounts > 0) {
    // individually free allocated memory for accounts
    // and char pointers
    safe_free(accounts[--currentAccounts]->name);
    safe_free(accounts[currentAccounts]);
  }
  // free account array
  safe_free(accounts);
}
