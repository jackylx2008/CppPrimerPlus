#ifndef __MY_COMPLEX_H__
#define __MY_COMPLEX_H__
#include <istream>
#include <ostream>

class my_complex {
  private:
    double real_part, imaginary_part;

  public:
    my_complex();
    my_complex(double r, double i);
    void set(double r, double i) {
        real_part = r;
        imaginary_part = i;
    }
    my_complex operator+(const my_complex& c) const;
    my_complex operator-(const my_complex& c) const;
    my_complex operator*(const my_complex& c) const;
    my_complex operator~() const;
    friend my_complex operator*(double multi, const my_complex& c);
    friend std::ostream& operator<<(std::ostream& os, const my_complex& c);
    friend std::istream& operator>>(std::istream& is, my_complex& c);
};

#endif  // !__MY_COMPLEX_H__
