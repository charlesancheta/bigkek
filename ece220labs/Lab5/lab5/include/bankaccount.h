#ifndef _BANK_ACCOUNT_H_
#define _BANK_ACCOUNT_H_

#include <iostream>
#include <string.h>
using namespace std;

const int maxNameLen = 40;

// Bank account class from tutorial
class BankAccount 
{
// can't access private members so change to protected
// to let inherited classes access these properties
protected:
  char name[maxNameLen];
  int account_number;
  double balance;
public:
  BankAccount();
  BankAccount(char *);
  BankAccount(char *, int, double);
  void printSummary();
  double withdraw(double);
  void deposit(double);
  double getBalance();
};

#endif