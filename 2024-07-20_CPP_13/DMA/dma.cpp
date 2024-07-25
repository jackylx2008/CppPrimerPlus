#include <cstring>
#include <iostream>
#include <ostream>

#include "./dma.h"

static int t = 0;

const int __TEST__ = false;

/* BaseDma */
BaseDma::BaseDma(const char* s, int n) {
    if (__TEST__) {
        std::cout << "args BaseDma" << std::endl;
    }
    str = new char(strlen(s + 1));
    strcpy(str, s);
    num = n;
}
BaseDma::BaseDma(const BaseDma& ba) {
    if (__TEST__) {
        std::cout << "constrcut ba" << std::endl;
    }
    delete[] str;
    str = new char(strlen(ba.str + 1));
    strcpy(str, ba.str);
    num = ba.num;
}
BaseDma& BaseDma::operator=(const BaseDma& ba) {
    if (__TEST__) {
        std::cout << "operator=ba" << std::endl;
    }
    if (this == &ba) {
        return *this;
    }
    delete[] str;
    str = new char(strlen(ba.str + 1));
    strcpy(str, ba.str);
    num = ba.num;
    return *this;
}
BaseDma::~BaseDma() {
    delete[] str;
}
std::ostream& operator<<(std::ostream& os, const BaseDma& ba) {
    os << "Str : " << ba.str << std::endl;
    os << "Num : " << ba.num << std::endl;
    return os;
}
/* Derived_Ba */
Derived_Ba::Derived_Ba(const char* s, int n, int m) : BaseDma(s, n), m_m(m) {
}
Derived_Ba::Derived_Ba(const BaseDma& ba, int m) : BaseDma(ba), m_m(m) {
}
Derived_Ba::Derived_Ba(const Derived_Ba& da) {
    BaseDma::operator=((const BaseDma&)da);
    m_m = da.m_m;
}
std::ostream& operator<<(std::ostream& os, const Derived_Ba& da) {
    os << (const BaseDma&)da;
    os << da.m_m << std::endl;
    return os;
}

/* Derived_New */
Derived_New::Derived_New(const char* s, int n, const char* ns) : BaseDma(s, n) {
    std::cout << "Derived_New " << ++t << std::endl;
    delete[] new_str;
    new_str = new char(strlen(ns + 1));
    strcpy(new_str, ns);
}
Derived_New::Derived_New(const BaseDma& ba, const char* ns) : BaseDma(ba) {
    delete[] new_str;
    new_str = new char(strlen(ns + 1));
    strcpy(new_str, ns);
}
Derived_New::Derived_New(const Derived_New& dn) : BaseDma((const BaseDma&)dn) {
    delete[] new_str;
    new_str = new char(strlen(dn.new_str + 1));
    strcpy(new_str, dn.new_str);
}
Derived_New& Derived_New::operator=(const Derived_New& dn) {
    if (this == &dn) {
        return *this;
    }
    // BaseDma((const BaseDma&)dn);
    delete[] str;
    str = new char(strlen(dn.str + 1));
    strcpy(str, dn.str);

    num = dn.num;

    delete[] new_str;
    new_str = new char(strlen(dn.new_str + 1));
    strcpy(new_str, dn.new_str);
    return *this;
}
Derived_New::~Derived_New() {
    delete[] new_str;
}
std::ostream& operator<<(std::ostream& os, const Derived_New& dn) {
    os << (const BaseDma&)dn;
    os << dn.new_str << std::endl;
    return os;
}
