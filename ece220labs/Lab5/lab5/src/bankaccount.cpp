#include "bankaccount.h"
using namespace std;

BankAccount::BankAccount() 
{
  name[0] = 0;
  account_number = 0;
  balance = 0.0;
}

BankAccount::BankAccount(char *n) 
{
  strcpy(name, n);
  account_number = 0;
  balance = 0.0;
}

BankAccount::BankAccount(char *n, int a_no, double bal) 
{
  strcpy(name, n);
  account_number = a_no;
  balance = bal;
}

void BankAccount :: printSummary() 
{
  cout << "---------------------" << endl;
  cout << "Name: " << name << endl;
  cout << "Account Number: " << account_number << endl;
  cout << "Balance: " << balance << endl;
  cout << "---------------------" << endl;
}

double BankAccount::withdraw(double toWD) 
{
  if (balance - toWD > 0) {
    balance -= toWD;
  } else {
    cout << "!!!Sorry, not enough money!!!" << endl;
    return 0;
  }
  return toWD;
}

void BankAccount::deposit(double toDep) 
{
  balance += toDep;
}

double BankAccount::getBalance() 
{
  return balance;
}
