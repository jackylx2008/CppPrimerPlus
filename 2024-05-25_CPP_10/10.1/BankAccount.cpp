#include <iostream>

#include "./BankAccount.h"

BankAccount::BankAccount(const char* name, const char* accountNum, double bal) {
    name_str = name;
    accountNum_str = accountNum;
    balance = bal;
}
void BankAccount::show() {
    std::cout << "Name: " << name_str << " AccountNum: " << accountNum_str
              << " Balance: " << balance << std::endl;
}

void BankAccount::deposit(double cash) {
    balance += cash;
}
void BankAccount::withdraw(double cash) {
    if (cash <= balance) {
        balance -= cash;
    } else {
        std::cout << "Not enough money" << std::endl;
    }
}
