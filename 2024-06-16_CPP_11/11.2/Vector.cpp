#include <cmath>
#include <ostream>

#include "./Vector.h"

namespace VECTOR {
    const double PI = 3.1415926;

    Vector::Vector() {
        x = 0.0;
        y = 0.0;
    }

    Vector::Vector(double n1, double n2, Mode form) {
        if (form == RECT) {
            mode = form;
            x = n1;
            y = n2;
        } else if (form == POLOR) {
            mode = form;
            set_x(n1, n2);
            set_y(n1, n2);
        }
    }
    void Vector::reset(double n1, double n2, Mode form) {
        if (form == RECT) {
            mode = form;
            x = n1;
            y = n2;
        } else if (form == POLOR) {
            mode = form;
            set_x(n1, n2);
            set_y(n1, n2);
        }
    }
    void Vector::set_x(double mag, double anl) {
        x = cosf(anl) * mag;
    }
    void Vector::set_y(double mag, double anl) {
        y = sinf(anl) * mag;
    }
    double Vector::magval() {
        return sqrt(x * x + y * y);
    }
    double Vector::anlval() {
        if (x == 0.0 && y == 0.0) {
            return 0.0;
        } else {
            return asin(y / magval());
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

    std::ostream &operator<<(std::ostream &os, Vector &v) {
        if (v.mode == Vector::RECT) {
            os << "(" << v.xval() << ", " << v.yval() << ")";
        } else if (v.mode == Vector::POLOR) {
            os << "(" << v.magval() << ", " << v.anlval() * 180 / PI << ")";
        }
        return os;
    }
}  // namespace VECTOR
