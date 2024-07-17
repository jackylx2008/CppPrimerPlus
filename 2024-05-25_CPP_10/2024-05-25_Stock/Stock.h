#ifndef __STOCK_H__
#define __STOCK_H__

#include <iostream>
#include <string>

class Stock {
  private:
    static const int n = 0;
    std::string name;
    int share;
    double share_val;
    double total_val;
    void set_val();

  public:
    void buy(const std::string& company, int share);
    void show(void) const;
    Stock();
    Stock(std::string company, int share, double share_val);
    const double get_share_val(void) const;
    const Stock& topval(const Stock& s) const;
};
#endif  // !__STOCK_H__
