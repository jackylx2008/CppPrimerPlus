#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <ostream>
namespace VECTOR {

    class Vector {
      public:
        enum Mode {
            RECT,
            POLOR
        };

      private:
        double x, y;
        double mag, anl;
        Mode mode;
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();

      public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        double magval() const {
            return mag;
        }
        double anlval() const {
            return anl;
        }
        double xval() const {
            return x;
        }
        double yval() const {
            return y;
        }
        void polar_mode();
        void rect_mode();

        Vector operator+(const Vector &a) const;
        Vector operator-(const Vector &a) const;
        Vector operator-() const;
        Vector operator*(double n) const;

        friend Vector operator*(double n, const Vector &a);
        friend std::ostream &operator<<(std::ostream &os, const Vector &a);
    };

}  // namespace VECTOR

#endif  // !__VECTOR_H__
