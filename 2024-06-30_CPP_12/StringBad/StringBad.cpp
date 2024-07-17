#include <cstring>
#include <iostream>
#include <ostream>

#include "./StringBad.h"

int StringBad::num_strings = 0;

StringBad::StringBad() {
    len = 4;
    str = new char[4];
    strcpy(str, "C++");
    std::cout << str << " constructed " << std::endl;
    num_strings++;
}
StringBad::StringBad(const char* s) {
    len = strlen(s) + 1;
    str = new char[len];
    strcpy(str, s);
    std::cout << str << " constructed " << std::endl;
    num_strings++;
}
StringBad::StringBad(const StringBad& s) {
    len = s.len;
    str = new char[len];
    strcpy(str, s.str);
    std::cout << str << " &s constructed " << std::endl;
    num_strings++;
}
StringBad& StringBad::operator=(
    const StringBad& s) {  // StringBad & s :Reference
    if (this == &s) {      // &s: get addr of Reference
        return *this;
    }
    delete[] str;
    len = s.len;
    str = new char[len];
    strcpy(str, s.str);
    std::cout << str << " = constructed " << std::endl;
    return *this;
}
StringBad& StringBad::operator=(const char* s) {  // StringBad & s :Reference
    delete[] str;
    len = strlen(s);
    str = new char[len];
    strcpy(str, s);
    std::cout << str << " = constructed " << std::endl;
    return *this;
}
const char& StringBad::operator[](int i) const {
    if (i < len) {
        return str[i];
    } else {
        return str[len];
    }
}
StringBad::~StringBad() {
    // std::cout << "num_strings = " << num_strings << std::endl;
    std::cout << str << " destoried" << std::endl;
    delete[] str;
    num_strings--;
}

std::ostream& operator<<(std::ostream& os, StringBad& s) {
    os << s.str;
    return os;
}
