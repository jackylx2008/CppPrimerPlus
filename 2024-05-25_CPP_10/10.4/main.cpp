#include "./Sales_cls.h"

int main(int argc, char *argv[]) {
    double a[4] = {1, 2, 3, 4};
    double b[3] = {1, 2, 3};
    SALES::Sales s(a, 4);
    s.showSales();
    SALES::Sales s1;
    s1.showSales();

    return 0;
}
