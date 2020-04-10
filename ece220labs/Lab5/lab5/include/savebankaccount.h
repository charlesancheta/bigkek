#ifndef _SAVE_BANK_ACCOUNT_H_
#define _SAVE_BANK_ACCOUNT_H_

#include "bankaccount.h"

// Savings BankAccount class inherited from BankAccount
class saveBankAccount : public BankAccount
{
public:
  saveBankAccount(char*, int, double, double, int);
  // const promises that we are not changing anything
  void printSummary() const; // just displaying
  void callInterest();
  void resetWithdraws();

  double withdraw(double);                
private:
  void displayNewBalance() const;
  double interestRate;
  int noWithdraws;
  int MAXnoWithDraws;
};

#endif