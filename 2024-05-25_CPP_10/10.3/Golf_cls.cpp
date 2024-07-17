#include <cstring>
#include <iostream>

#include "./Golf_cls.h"

Golf::Golf(const char *fullname, int hc) {
    this->hc = hc;
    strcpy(this->fullname, fullname);
}

void Golf::handicap(int hc) {
    if (fullname[0] != '\0') {
        this->hc = hc;
    } else {
        std::cout << "No data" << std::endl;
    }
}

void Golf::showgolf() const {
    if (fullname[0] != '\0') {
        std::cout << "Name: " << this->fullname << " Handicap: " << this->hc
                  << std::endl;
    } else {
        std::cout << "No data" << std::endl;
    }
}
