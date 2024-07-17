#include "./sales.h"

int main(int argc, char *argv[]) {
    SALES::Sales s;
    double a[4] = {1, 2, 3, 4};
    double b[3] = {1, 2, 3};
    SALES::setSales(&s, a, 3);
    SALES::showSales(s);
    return 0;
}
