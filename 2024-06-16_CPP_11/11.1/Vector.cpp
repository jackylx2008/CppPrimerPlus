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
            set_mag();
            set_anl();
        } else if (form == POLOR) {
            mode = form;
            mag = n1;
            anl = n2;
            set_x();
            set_y();
        }
    }
    void Vector::reset(double n1, double n2, Mode form) {
        if (form == RECT) {
            mode = form;
            x = n1;
            y = n2;
            set_mag();
            set_anl();
        } else if (form == POLOR) {
            mode = form;
            mag = n1;
            anl = n2;
            set_x();
            set_y();
        }
    }
    void Vector::set_x() {
        x = cosf(anl) * mag;
    }
    void Vector::set_y() {
        y = sinf(anl) * mag;
    }
    void Vector::set_anl() {
        if (x == 0.0 && y == 0.0) {
            anl = 0.0;
        } else {
            anl = atan2(y, x);
        }
    }
    void Vector::set_mag() {
        mag = sqrt(x * x + y * y);
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
        if (a.mode == Vector::RECT) {
            os << "(" << a.xval() << ", " << a.yval() << ")";
        } else if (a.mode == Vector::POLOR) {
            os << "(" << a.magval() << ", " << a.anlval() * 180 / PI << ")";
        }
        return os;
    }
}  // namespace VECTOR
