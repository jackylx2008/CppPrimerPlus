#include <iostream>

const int operator_num = 3;
double add(double x, double y);
double minus(double x, double y);
double multiply(double x, double y);
double calculate(double x, double y, double (*pf)(double x, double y));

int main(int argc, char *argv[]) {
    double q = calculate(2.5, 10.4, add);
    std::cout << "q = " << q << std::endl;
    double (*pf[operator_num])(double, double) = {add, minus, multiply};
    for (int i = 0; i < operator_num; i++) {
        double ret = calculate(2.5, 10.4, (*pf[i]));
        std::cout << "Result = " << ret << std::endl;
    }
    return 0;
}
double add(double x, double y) {
    return x + y;
}
double minus(double x, double y) {
    return x - y;
}
double multiply(double x, double y) {
    return x * y;
}

double calculate(double x, double y, double (*pf)(double x, double y)) {
    return pf(x, y);
}
