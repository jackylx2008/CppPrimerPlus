#include <istream>
#include <ostream>
#include <valarray>

#include "./student.h"

double Student::Average() const {
    if (std::valarray<double>::size() > 0) {
        return std::valarray<double>::sum() / std::valarray<double>::size();
    } else {
        return 0.0;
    }
}
double& Student::operator[](int n) {
    return std::valarray<double>::operator[](n);
}
const double Student::operator[](int n) const {
    return std::valarray<double>::operator[](n);
}
std::istream& operator>>(std::istream& is, Student& s) {
    is >> (std::string&)s;
    return is;
}
std::istream& getline(std::istream& is, Student& s) {
    getline(is, (std::string&)s);
    return is;
}
std::ostream& Student::show_Scores(std::ostream& os) const {
    os << "Name: " << (const std::string&)(*this);
    os << " Scores:";
    if (std::valarray<double>::size() > 0) {
        for (int i = 0; i < std::valarray<double>::size(); i++) {
            os << std::valarray<double>::operator[](i) << " ";
        }
    } else {
        os << " 0.0";
    }
    return os;
}
std::ostream& operator<<(std::ostream& os, const Student& s) {
    s.show_Scores(os);
    return os;
}
