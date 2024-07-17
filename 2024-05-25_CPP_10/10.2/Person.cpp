#include <cstdio>
#include <cstring>
#include <iostream>

#include "./Person.h"

Person::Person(const std::string& ln, const char* fn) {
    lname = ln;
    // fname = fn;
    // strcpy(fname, fn);
    snprintf(fname, LIMIT, "%s", fn);
    // int i = 0;
    // while (fn[i] != '\0' && i < LIMIT - 1) {
    //     fname[i] = fn[i];
    //     i++;
    // }
    // fname[i + 1] = '\0';
}

void Person::Show() const {
    if (lname != "" && fname[0] != '\0') {
        std::cout << fname << " " << lname << std::endl;
    } else {
        std::cout << "No name" << std::endl;
    }
}
void Person::FormalShow() const {
    if (lname != "" && fname[0] != '\0') {
        std::cout << lname << " " << fname << std::endl;
    } else {
        std::cout << "No name" << std::endl;
    }
}
