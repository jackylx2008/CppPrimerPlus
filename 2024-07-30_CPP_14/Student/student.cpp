#include <istream>
#include <ostream>

#include "./student.h"

double Student::Average() const {
    if (Scores.size() > 0) {
        return Scores.sum() / Scores.size();
    } else {
        return 0.0;
    }
}
Student& Student::operator=(const Student& s) {
    Name = s.Name;
    Scores = s.Scores;
    return *this;
}
double& Student::operator[](int n) {
    return Scores[n];
}
const double Student::operator[](int n) const {
    return Scores[n];
}
std::istream& operator>>(std::istream& is, Student& s) {
    is >> s.Name;
    return is;
}
std::istream& getline(std::istream& is, Student& s) {
    getline(is, s.Name);
    return is;
}
std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << "Name: " << s.Name;
    os << " Scores:";
    if (s.Scores.size() > 0) {
        for (int i = 0; i < s.Scores.size(); i++) {
            os << s.Scores[i] << " ";
        }
    } else {
        os << " 0.0";
    }

    return os;
}
