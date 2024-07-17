#include <iostream>

#include "./my_complex.h"

my_complex::my_complex() {
    real_part = 0.0;
    imaginary_part = 0.0;
}
my_complex::my_complex(double r, double i) {
    real_part = r;
    imaginary_part = i;
}
my_complex my_complex::operator+(const my_complex& c) const {
    return my_complex(real_part + c.real_part,
                      imaginary_part + c.imaginary_part);
}
my_complex my_complex::operator-(const my_complex& c) const {
    return my_complex(real_part - c.real_part,
                      imaginary_part - c.imaginary_part);
}
my_complex my_complex::operator*(const my_complex& c) const {
    return my_complex(
        real_part * c.real_part - imaginary_part * c.imaginary_part,
        real_part * c.imaginary_part + imaginary_part * c.real_part);
}
my_complex my_complex::operator~() const {
    return my_complex(real_part, -1 * imaginary_part);
}
my_complex operator*(double multi, const my_complex& c) {
    return my_complex(multi * c.real_part, multi * c.imaginary_part);
}
std::ostream& operator<<(std::ostream& os, const my_complex& c) {
    os << "(" << c.real_part << "," << c.imaginary_part << "i)";
    return os;
}
std::istream& operator>>(std::istream& is, my_complex& c) {
    double r, i;
    r = i = 0.0;
    std::cout << "real: ";
    is >> r;
    std::cout << "imaginary: ";
    is >> i;
    c.set(r, i);
    return is;
}
