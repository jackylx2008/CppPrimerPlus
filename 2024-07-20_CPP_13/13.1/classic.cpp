#include <cstring>
#include <iostream>

#include "./classic.h"

Cd::Cd() : performers(""), label(""), selections(0), playtime(0.0) {
}
Cd::Cd(const char* s1, const char* s2, int n, double x) {
    if (strlen(s1) > 49) {
        strncpy(performers, s1, 49);
        performers[49] = '\0';
    } else {
        strncpy(performers, s1, strlen(s1));
        performers[strlen(s1)] = '\0';
    }
    if (strlen(s2) > 19) {
        strncpy(label, s2, 19);
        label[19] = '\0';
    } else {
        strncpy(label, s2, strlen(s2));
        label[strlen(s2)] = '\0';
    }
    selections = n;
    playtime = x;
}
Cd::Cd(const Cd& d) {
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}
Cd::~Cd() {
}
void Cd::Report() const {
    std::cout << "Performers: " << performers << std::endl;
    std::cout << "Label: " << label << std::endl;
    std::cout << "Selections: " << selections << std::endl;
    std::cout << "Playtime: " << playtime << std::endl;
}
Cd& Cd::operator=(const Cd& d) {
    if (this == &d) {
        return *this;
    }
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}
Classic::Classic() : Cd(), primary_works("") {
}
Classic::Classic(const char* s1, const char* s2, const char* s3, int n,
                 double x)
    : Cd(s1, s2, n, x) {
    if (strlen(s3) > 49) {
        strncpy(primary_works, s3, 49);
        primary_works[49] = '\0';
    } else {
        strncpy(primary_works, s3, strlen(s3));
        primary_works[strlen(s3)] = '\0';
    }
}
Classic::Classic(const Classic& c) : Cd((const Cd&)c) {
    strcpy(primary_works, c.primary_works);
}
Classic::~Classic() {
}
void Classic::Report() const {
    Cd::Report();
    std::cout << "Primary Works: " << primary_works << std::endl;
}
Classic& Classic::operator=(const Classic& c) {
    if (this == &c) {
        return *this;
    }
    Cd::operator=((const Cd&)c);
    strcpy(primary_works, c.primary_works);
    return *this;
}
