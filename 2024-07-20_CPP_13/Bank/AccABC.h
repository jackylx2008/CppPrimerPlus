#ifndef __ACCABC_H__
#define __ACCABC_H__

#include <cstdint>
#include <string>

class AccAbc {
  private:
    std::string m_name;
    long m_acc_num;
    double m_balance;

  public:
    AccAbc() : m_name("NULL"), m_acc_num(-1), m_balance(0.0) {
    }
    AccAbc(const std::string& name, long acc_num, double balance)
        : m_name(name), m_acc_num(acc_num), m_balance(balance) {
    }
    ~AccAbc() {
    }
    std::string& get_name() {
        return m_name;
    }
    long get_acc_num() {
        return m_acc_num;
    }
    double& get_balance() {
        return m_balance;
    }
    virtual void Deposit(double amount) = 0;
    virtual void Withdraw(double amount) = 0;
    virtual void ViewAccount() = 0;
};

class Brass : public AccAbc {
  private:
  public:
    Brass() {
    }
    Brass(const std::string& name, long acc_num, double balance)
        : AccAbc(name, acc_num, balance) {
    }
    ~Brass() {
    }
    virtual void Deposit(double amount);
    virtual void Withdraw(double amount);
    virtual void ViewAccount();
};

class BrassPlus : public Brass {
  private:
    double m_loan;
    double m_rate;
    double m_oweBank;

  public:
    BrassPlus();
    BrassPlus(const std::string& name, const int accNum, const double balance,
              const double loan, const double rate);
    BrassPlus(const double loan, const double rate, const Brass& brass);
    ~BrassPlus() {
    }
    virtual void Deposit(double amount);
    virtual void Withdraw(double amount);
    virtual void ViewAccount();
};
#endif  // !__ACCABC_H__
