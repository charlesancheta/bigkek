#include "savebankaccount.h"

int main() {
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