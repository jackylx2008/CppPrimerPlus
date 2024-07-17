#include <iostream>
#include <ostream>

#include "./stonewt.h"
// using std::cout;
// construct Stonewt object from double value
Stonewt::Stonewt(double lbs) {
    stone = int(lbs) / Lbs_per_stn;  // integer division
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
    form = STONE;
}
// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs, Mode f) {
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
    form = f;
}
Stonewt::Stonewt() {  // default constructor, wt = 0
    stone = pounds = pds_left = 0;
}
Stonewt::~Stonewt() {  // destructor
}
Stonewt::Mode Stonewt::get_stat() const {
    return form;
}
void Stonewt::set_stat(Stonewt::Mode f) {
    form = f;
}
double Stonewt::get_stone() const {
    return stone;
}
double Stonewt::get_pounds() const {
    return pounds;
}
double Stonewt::get_pds_left() const {
    return pds_left;
}
Stonewt Stonewt::operator+(const Stonewt& s) const {
    Stonewt result(s.get_pounds() + pounds);
    return result;
}
Stonewt Stonewt::operator-(const Stonewt& s) const {
    Stonewt result(abs((s.get_pounds() - pounds)));
    return result;
}
Stonewt Stonewt::operator*(const double multi) const {
    Stonewt result(pounds * multi);
    return result;
}
Stonewt operator*(const double multi, const Stonewt& s) {
    Stonewt result(s.get_pounds() * multi);
    return result;
}

bool Stonewt::operator<(const Stonewt& s) const {
    return pounds < s.get_pounds();
}
bool Stonewt::operator<=(const Stonewt& s) const {
    return pounds <= s.get_pounds();
}
bool Stonewt::operator>(const Stonewt& s) const {
    return pounds > s.get_pounds();
}
bool Stonewt::operator>=(const Stonewt& s) const {
    return pounds >= s.get_pounds();
}
bool Stonewt::operator==(const Stonewt& s) const {
    return pounds == s.get_pounds();
}
bool Stonewt::operator!=(const Stonewt& s) const {
    return pounds != s.get_pounds();
}
std::ostream& operator<<(std::ostream& os, const Stonewt st) {
    switch (st.get_stat()) {
        case Stonewt::STONE:
            os << st.get_stone() << " stone, " << st.get_pds_left()
               << " pounds\n";
            break;
        case Stonewt::INTEGER_POUNDS:
            os << (int)st.get_pounds() << " pounds\n";
            break;
        case Stonewt::FLOATING_POUNDS:
            os << st.get_pounds() << " pounds\n";
            break;
        default: os << "default\n";
    }
    return os;
}
