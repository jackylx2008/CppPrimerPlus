#ifndef __BRASS_H__
#define __BRASS_H__

#include <cstdint>
#include <string>

class Brass {
  private:
    std::string m_accName;
    int m_accNum;
    double m_Balance;

  public:
    Brass();
    Brass(const std::string& name, const int accNum, const double balance);
    Brass(const Brass& brass);
    virtual ~Brass() {
    }
    void Deposit(double money);
    virtual bool Withdraw(double money);
    virtual void ViewAccount(void);
    virtual double Balance(void) {
        return m_Balance;
    }
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
    virtual ~BrassPlus() {
    }
    virtual bool Withdraw(double money);
    virtual void ViewAccount(void);
};

#endif  // !__BRASS_H__
