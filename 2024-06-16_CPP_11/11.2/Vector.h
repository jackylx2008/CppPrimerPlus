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
        Mode mode;

      private:
        double x, y;
        void set_x(double mag, double anl);
        void set_y(double mag, double anl);

      public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        double magval();
        double anlval();
        double xval() const {
            return x;
        }
        double yval() const {
            return y;
        }
        void reset(double n1, double n2, Mode form = RECT);
        void polar_mode();
        void rect_mode();

        Vector operator+(const Vector &a) const;
        Vector operator-(const Vector &a) const;
        Vector operator-() const;
        Vector operator*(double n) const;

        friend Vector operator*(double n, const Vector &a);
        friend std::ostream &operator<<(std::ostream &os, Vector &a);
    };

}  // namespace VECTOR

#endif  // !__VECTOR_H__
