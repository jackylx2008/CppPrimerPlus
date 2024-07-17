#include "Stock.h"

void Stock::set_val() {
    total_val = share * share_val;
}

void Stock::buy(const std::string& company, int share) {
    name = company;
    this->share = share;
    // share_val = pr;
    set_val();
}

void Stock::show(void) const {
    std::cout << "name = " << name << " total = " << total_val << std::endl;
}
Stock::Stock() {
    this->name = "Error";
    this->share_val = 100;
    this->share = 100;
    set_val();
}

Stock::Stock(std::string company, int share, double share_val) {
    this->name = company;
    this->share_val = share_val;
    this->share = share;
    set_val();
}

const double Stock::get_share_val(void) const {
    return this->share_val;
}
const Stock& Stock::topval(const Stock& s) const {
    if (this->share_val > s.get_share_val()) {
        return *this;
    } else {
        return s;
    }
}
int main(int argc, char* argv[]) {
    Stock s1 = Stock("s1", 50, 5.0);
    Stock s2 = Stock("lll", 10, 6.0);
    // s.buy("lll", 50);
    Stock top = s1.topval(s2);
    s1.show();
    s2.show();
    top.show();
    Stock s_arr[] = {
        Stock("2", 2, 20),
        Stock("3", 3, 30),
        Stock("4", 4, 40),
        Stock("1", 1, 10),
    };
    const Stock* top1 = &s_arr[0];
    for (int i = 0; i < 4; i++) {
        top1 = &top1->topval(s_arr[i]);
    }
    top1->show();
}
