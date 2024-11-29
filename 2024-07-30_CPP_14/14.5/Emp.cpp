#include <iostream>
#include <ostream>

#include "./Emp.h"
abstr_emp::abstr_emp() {
    fname = lname = job = "null";
}
abstr_emp::abstr_emp(const std::string& fn, const std::string& ln,
                     const std::string& j)
    : fname(fn), lname(ln), job(j) {}
void abstr_emp::ShowAll() const {
    std::cout << "Name: " << fname << " " << lname << std::endl;
    std::cout << "Job: " << job << std::endl;
}
void abstr_emp::SetAll() {
    std::string temp;
    std::cout << "First Name: " << std::endl;
    std::cin >> fname;
    std::cout << "Last Name: " << std::endl;
    std::cin >> lname;
    std::cout << "Job: " << std::endl;
    std::cin >> job;
}
std::ostream& operator<<(std::ostream& os, const abstr_emp& e) {
    std::cout << "Name: " << e.fname << " " << e.lname;
    return os;
}
abstr_emp::~abstr_emp() {}
employee::employee() : abstr_emp() {}
employee::employee(const std::string& fn, const std::string& ln,
                   const std::string& j)
    : abstr_emp(fn, ln, j) {}
void employee::ShowAll() const {
    abstr_emp::ShowAll();
}
void employee::SetAll() {
    abstr_emp::SetAll();
}
manager::manager() : abstr_emp() {}
manager::manager(const std::string& fn, const std::string& ln,
                 const std::string& j, int ico)
    : abstr_emp(fn, ln, j), inchargeof(ico) {}
manager::manager(const abstr_emp& e, int ico) : abstr_emp(e), inchargeof(ico) {}
manager::manager(const manager& m)
    : abstr_emp((const abstr_emp&)m), inchargeof(m.inchargeof) {}
void manager::ShowAll() const {
    abstr_emp::ShowAll();
    std::cout << "InChargeOf:" << inchargeof << std::endl;
}
void manager::SetAll() {
    abstr_emp::SetAll();
    std::cout << "InChargeOf:" << std::endl;
    std::cin >> inchargeof;
}
fink::fink() : abstr_emp(), reportsto("null") {}
fink::fink(const std::string& fn, const std::string& ln, const std::string& j,
           const std::string& rpo)
    : abstr_emp(fn, ln, j), reportsto(rpo) {}
fink::fink(const abstr_emp& f, const std::string& rpo)
    : abstr_emp(f), reportsto(rpo) {}
fink::fink(const fink& f)
    : abstr_emp((const abstr_emp&)f), reportsto(f.reportsto) {}
void fink::ShowAll() const {
    abstr_emp::ShowAll();
    std::cout << "Reports to: " << reportsto << std::endl;
}
void fink::SetAll() {
    abstr_emp::SetAll();
    std::cout << "Reports to whom:" << std::endl;
    std::cin >> reportsto;
}
highfink::highfink() : manager(), fink() {}
highfink::highfink(const std::string& fn, const std::string& ln,
                   const std::string& j, const std::string& rpo, int ico)
    : manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}
highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico)
    : abstr_emp(e), manager(e, ico), fink(e, rpo) {}
highfink::highfink(const fink& f, int ico)
    : fink(f),
      manager((const abstr_emp&)f, ico),
      abstr_emp((const abstr_emp&)f) {}
highfink::highfink(const manager& m, const std::string& rpo)
    : manager(m),
      fink((const abstr_emp&)m, rpo),
      abstr_emp((const abstr_emp&)m) {}
highfink::highfink(const highfink& h)
    : abstr_emp((const abstr_emp&)h),
      manager((const manager&)h),
      fink((const fink&)h) {}
void highfink::ShowAll() const {
    abstr_emp::ShowAll();
    manager::Show();
    fink::Show();
}
void highfink::SetAll() {
    abstr_emp::SetAll();
    std::cout << "InChargeOf: ";
    std::cin >> manager::InChargeOf();
    std::cout << "ReportsTo: ";
    std::cin >> fink::ReportsTo();
}
