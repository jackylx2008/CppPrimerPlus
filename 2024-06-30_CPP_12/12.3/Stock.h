// stock20.h -- augmented version
#ifndef STOCK20_H_
#define STOCK20_H_
#include <cstdint>
#include <ostream>
#include <string>
class Stock {
  private:
    // std::string company;
    char* company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() {
        total_val = shares * share_val;
    }

  public:
    Stock();  // default constructor
    // Stock(const std::string& co, long n = 0, double pr = 0.0);
    explicit Stock(const char* s, int16_t n = 0, double pr = 0.0);
    ~Stock();  // do-nothing destructor
    void buy(int16_t num, double price);
    void sell(int16_t num, double price);
    void update(double price);
    // void show() const;
    const Stock& topval(const Stock& s) const;
    friend std::ostream& operator<<(std::ostream& os, const Stock& st);
};
#endif
