#ifndef __BANKACCOUNT_H__
#define __BANKACCOUNT_H__
#include <string>

using namespace std;

class BankAccount {
  private:
    static const int CHAR_SIZE = 40;
    // const char* name_str;
    // const char* accountNum_str;
    char name_str[CHAR_SIZE];
    char accountNum_str[CHAR_SIZE];
    double balance;

  public:
    // BankAccount(const char name[CHAR_SIZE], const char accountNum[CHAR_SIZE],
    //             double bal = 0.0);
    BankAccount(const char* name, const char* accountNum, double bal = 0.0);
    void show();
    void deposit(double cash);
    void withdraw(double cash);
};
#endif
