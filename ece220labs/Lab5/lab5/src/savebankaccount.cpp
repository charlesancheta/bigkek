#include "savebankaccount.h"
using namespace std;

// savings bank account constructor
saveBankAccount::saveBankAccount(char *n, int a_no, double bal, double intRate, 
                                 int maxWD) : BankAccount(n, a_no, bal) 
{
  interestRate = intRate;
  MAXnoWithDraws = maxWD;
  noWithdraws = 0;
}

void saveBankAccount::printSummary() const 
{
  cout << "-------------------------" << endl;
  cout << "Name: " << name << endl;
  cout << "Account Number: " << account_number << endl;
  cout << "Balance: " << balance << endl;
  // print interest rate as a percent
  cout << "Interest Rate: " << interestRate * 100 << "%"<< endl;
  cout << "No. of withdraws: " << noWithdraws << endl;
  cout << "Max no. of withdraws: " << MAXnoWithDraws << endl;
  cout << "-------------------------" << endl;
}

// display new balance after a change
void saveBankAccount::displayNewBalance() const 
{
  cout << "New balance: " << balance << endl;
}

// calculates interest
void saveBankAccount::callInterest() 
{
  balance *= (interestRate + 1);
  displayNewBalance();
}

void saveBankAccount::resetWithdraws() 
{
  noWithdraws = 0;
}

double saveBankAccount::withdraw(double toWD) 
{
  if (noWithdraws == MAXnoWithDraws) {
    cout << "!!!Exceeded max no. of withdraws!!!" << endl;
  } else if (balance - toWD > 0) {
    balance -= toWD; // withdraw money
    displayNewBalance();
    noWithdraws++;
    return toWD;
  } else {
    cout << "!!!Sorry, not enough money!!!" << endl;
  }
  return 0;
}
