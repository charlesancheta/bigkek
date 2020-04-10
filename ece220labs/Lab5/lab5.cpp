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


// savings bank account constructor
saveBankAccount::saveBankAccount(char *n, int a_no, double bal, 
                                 double intRate, int maxWD) 
{
  strcpy(name, n);
  account_number = a_no;
  balance = bal;
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
  // check first if we've not exceeded max no.
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

int main() 
{
  saveBankAccount tomAcc = saveBankAccount("Tom", 234567, 2000, 0.05, 1);
  tomAcc.deposit(1000);
  tomAcc.withdraw(500);
  tomAcc.withdraw(500);
  tomAcc.printSummary();
  tomAcc.resetWithdraws();
  tomAcc.withdraw(500);
  tomAcc.printSummary();
  tomAcc.callInterest();
  tomAcc.printSummary();
  return 0;
}