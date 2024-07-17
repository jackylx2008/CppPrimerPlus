#include <cmath>
#include <ostream>

#include "./Vector.h"

namespace VECTOR {
    const double PI = 3.1415926;

    Vector::Vector() {
        x = 0.0;
        y = 0.0;
        mag = 0.0;
        anl = 0.0;
    }

    Vector::Vector(double n1, double n2, Mode form) {
        if (form == RECT) {
            mode = form;
            x = n1;
            y = n2;
            mag = sqrt(x * x + y * y);
            anl = atan2(y, x);
        } else if (form == POLOR) {
            mode = form;
            mag = n1;
            anl = n2;
            x = cosf(anl) * mag;
            y = sinf(anl) * mag;
        }
    }

    void Vector::polar_mode() {
        mode = POLOR;
    }
    void Vector::rect_mode() {
        mode = RECT;
    }
    Vector Vector::operator+(const Vector &a) const {
        Vector sum(x + a.xval(), y + a.yval());
        return sum;
    }
    Vector Vector::operator-(const Vector &a) const {
        Vector sum(x - a.xval(), y - a.yval());
        return sum;
    }
    Vector Vector::operator-() const {
        Vector sum(-x, -y);
        return sum;
    }
    Vector Vector::operator*(double n) const {
        Vector multi(x * n, y * n);
        return multi;
    }

    Vector operator*(double n, const Vector &a) {
        return a * n;
    }

    std::ostream &operator<<(std::ostream &os, const Vector &a) {
        os << "x = " << a.yval() << " y = " << a.yval()
           << " mag = " << a.magval() << " anl = " << a.anlval() * 180 / PI;
        return os;
    }
}  // namespace VECTOR
