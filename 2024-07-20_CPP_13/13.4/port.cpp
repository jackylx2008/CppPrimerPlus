#include <cstring>
#include <ostream>

#include "./port.h"

Port::Port(const char* br, const char* st, int b) {
    if (br != nullptr) {
        brand = new char[strlen(br) + 1];
        strcpy(brand, br);
    } else
        br = nullptr;
    strcpy(style, st);
    bottles = b;
}
Port::Port(const Port& p) {
    if (p.brand != nullptr) {
        delete[] brand;
        brand = new char[strlen(p.brand) + 1];
        strcpy(brand, p.brand);
    } else
        brand = nullptr;
    strcpy(style, p.style);
    bottles = p.bottles;
}
Port& Port::operator=(const Port& p) {
    if (this == &p) {
        return *this;
    }
    if (p.brand != nullptr) {
        delete[] brand;
        brand = new char[strlen(p.brand) + 1];
        strcpy(brand, p.brand);
    } else
        brand = nullptr;
    strcpy(style, p.style);
    bottles = p.bottles;
    return *this;
}
Port& Port::operator+=(int b) {
    bottles += b;
    return *this;
}
Port& Port::operator-=(int b) {
    if (bottles >= b) {
        bottles -= b;
    } else {
        std::cout << "Bottles less than b" << std::endl;
    }
    return *this;
}
void Port::Show() const {
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Kind: " << style << std::endl;
    std::cout << "Bottles: " << bottles << std::endl;
}
std::ostream& operator<<(std::ostream& os, const Port& p) {
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}
VintagePort::VintagePort() : Port() {
    nickname = new char[5];
    strcpy(nickname, "none");
    year = -1;
}
VintagePort::VintagePort(const char* br, int b, const char* nn, int y)
    : Port(br, "none", b) {
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}
VintagePort::VintagePort(const VintagePort& vp) : Port((const Port&)vp) {
    delete[] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}
VintagePort& VintagePort::operator=(const VintagePort& vp) {
    Port::operator=((const Port&)vp);
    delete[] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}
void VintagePort::Show() const {
    Port::Show();
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Year:" << year << std::endl;
}
std::ostream& operator<<(std::ostream& os, const VintagePort& vp) {
    os << (const Port&)vp << ", " << vp.nickname << ", " << vp.year;
    return os;
}
