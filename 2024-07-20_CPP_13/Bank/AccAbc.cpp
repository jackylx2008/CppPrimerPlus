#include <iostream>

#include "./AccABC.h"

void Brass::Deposit(double money) {
    get_balance() += money;
}
void Brass::Withdraw(double money) {
    if (money > get_balance()) {
        std::cout << "Withdraw :$" << money << " more than Balance"
                  << std::endl;
    } else {
        get_balance() -= money;
    }
}
void Brass::ViewAccount(void) {
    std::cout << "Name: " << get_name() << std::endl;
    std::cout << "Account Num: " << get_acc_num() << std::endl;
    std::cout << "Balance: $" << get_balance() << std::endl;
}

BrassPlus::BrassPlus()
    : m_loan(0.0), m_rate(0.0), m_oweBank(0.0), Brass("NULL", -1, 0.0) {
}

BrassPlus::BrassPlus(const std::string& name, const int accNum,
                     const double balance, const double loan, const double rate)
    : Brass(name, accNum, balance), m_loan(loan), m_rate(rate), m_oweBank(0.0) {
}
BrassPlus::BrassPlus(const double loan, const double rate, const Brass& brass)
    : m_loan(loan), m_rate(rate), m_oweBank(0.0), Brass(brass) {
}
void BrassPlus::Deposit(double money) {
    get_balance() += money;
}
void BrassPlus::Withdraw(double money) {
    if (money > get_balance() + m_loan) {
        std::cout << "Withdraw :$" << money << " more than Balance + Loan"
                  << std::endl;
    } else if (money <= get_balance() + m_loan && money > get_balance()) {
        m_loan = money - get_balance();
        Brass::Withdraw(get_balance());
        m_oweBank = m_rate * m_loan;
    } else if (money <= get_balance()) {
        Brass::Withdraw(money);
    }
}
void BrassPlus::ViewAccount(void) {
    Brass::ViewAccount();
    std::cout << "Loan :$" << m_loan << std::endl;
    std::cout << "Rate = " << m_rate << std::endl;
    std::cout << "Owe Bank :$" << m_oweBank << std::endl;
}
