#include <cstring>
#include <iostream>

#include "./classic.h"

Cd::Cd() : performers(nullptr), label(nullptr), selections(0), playtime(0.0) {
}
Cd::Cd(const char* s1, const char* s2, int n, double x) {
    performers = new char(strlen(s1) + 1);
    strcpy(performers, s1);
    label = new char(strlen(s2) + 1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}
Cd::Cd(const Cd& d) {
    delete[] performers;
    performers = new char(strlen(d.performers) + 1);
    strcpy(performers, d.performers);
    delete[] label;
    label = new char(strlen(d.label) + 1);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}
Cd::~Cd() {
    delete[] performers;
    delete[] label;
}
void Cd::Report() const {
    if (performers != nullptr)
        std::cout << "Performers: " << performers << std::endl;
    if (label != nullptr) std::cout << "Label: " << label << std::endl;
    std::cout << "Selections: " << selections << std::endl;
    std::cout << "Playtime: " << playtime << std::endl;
}
Cd& Cd::operator=(const Cd& d) {
    if (this == &d) {
        return *this;
    }
    delete[] performers;
    performers = new char(strlen(d.performers) + 1);
    strcpy(performers, d.performers);
    delete[] label;
    label = new char(strlen(d.label) + 1);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}
Classic::Classic() : Cd() {
    primary_works = nullptr;
}
Classic::Classic(const char* s1, const char* s2, const char* s3, int n,
                 double x)
    : Cd(s1, s2, n, x) {
    primary_works = new char(strlen(s3) + 1);
    strcpy(primary_works, s3);
}
Classic::Classic(const Classic& c) : Cd((const Cd&)c) {
    primary_works = new char(strlen(c.primary_works) + 1);
    strcpy(primary_works, c.primary_works);
}
Classic::~Classic() {
    delete[] primary_works;
}
void Classic::Report() const {
    Cd::Report();
    if (primary_works != nullptr)
        std::cout << "Primary Works: " << primary_works << std::endl;
}
Classic& Classic::operator=(const Classic& c) {
    if (this == &c) {
        return *this;
    }
    Cd::operator=((const Cd&)c);
    delete[] primary_works;
    primary_works = new char(strlen(c.primary_works) + 1);
    strcpy(primary_works, c.primary_works);
    return *this;
}
