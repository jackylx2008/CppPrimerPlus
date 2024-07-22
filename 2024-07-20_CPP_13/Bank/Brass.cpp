#include <iostream>

#include "./Brass.h"

Brass::Brass() : m_accName("NULL"), m_accNum(-1), m_Balance(0.0) {
}
Brass::Brass(const std::string& name, const int accNum, const double balance) {
    m_accName = name;
    m_accNum = accNum;
    m_Balance = balance;
}

Brass::Brass(const Brass& brass) {
    m_accName = brass.m_accName;
    m_accNum = brass.m_accNum;
    m_Balance = brass.m_Balance;
}
void Brass::Deposit(double money) {
    m_Balance += money;
}
bool Brass::Withdraw(double money) {
    if (money > m_Balance) {
        std::cout << "Withdraw :$" << money << " more than Balance"
                  << std::endl;
        return false;
    } else {
        m_Balance -= money;
    }
    return true;
}
void Brass::ViewAccount(void) {
    std::cout << "Name: " << m_accName << std::endl;
    std::cout << "Account Num: " << m_accNum << std::endl;
    std::cout << "Balance: $" << m_Balance << std::endl;
}

BrassPlus::BrassPlus() : m_loan(0.0), m_rate(0.0), m_oweBank(0.0) {
    Brass("NULL", -1, 0.0);
}
BrassPlus::BrassPlus(const std::string& name, const int accNum,
                     const double balance, const double loan, const double rate)
    : Brass(name, accNum, balance), m_loan(loan), m_rate(rate), m_oweBank(0.0) {
}
BrassPlus::BrassPlus(const double loan, const double rate, const Brass& brass)
    : m_loan(loan), m_rate(rate), m_oweBank(0.0), Brass(brass) {
}
bool BrassPlus::Withdraw(double money) {
    if (money > Brass::Balance() + m_loan) {
        std::cout << "Withdraw :$" << money << " more than Balance + Loan"
                  << std::endl;
        return false;
    } else if (money <= Brass::Balance() + m_loan && money > Brass::Balance()) {
        m_loan = money - Brass::Balance();
        Brass::Withdraw(Brass::Balance());
        m_oweBank = m_rate * m_loan;
    } else if (money <= Brass::Balance()) {
        Brass::Withdraw(money);
    }
    return true;
}
void BrassPlus::ViewAccount(void) {
    Brass::ViewAccount();
    std::cout << "Loan :$" << m_loan << std::endl;
    std::cout << "Rate = " << m_rate << std::endl;
    std::cout << "Owe Bank :$" << m_oweBank << std::endl;
}
