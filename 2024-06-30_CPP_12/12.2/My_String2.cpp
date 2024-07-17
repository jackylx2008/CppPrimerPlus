#include <cstring>
#include <iostream>
#include <ostream>

#include "./My_String2.h"

My_String2::My_String2() {
    str = new char[1];
    str[0] = '\0';
    len = 0;
}
My_String2::My_String2(const char* s) {
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
}
My_String2::My_String2(const My_String2& s) {
    len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str);
}
My_String2::~My_String2() {
    delete[] str;
}
My_String2& My_String2::operator=(const My_String2& s) {
    if (this == &s) return *this;
    delete[] str;
    len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str);
    // std::cout << "operator=(const My_String2&)" << std::endl;
    return *this;
}
My_String2& My_String2::operator=(const char* s) {
    // delete[] str;
    // len = strlen(s);
    // str = new char[len + 1];
    // strcpy(str, s);
    // std::cout << "operator=(const char*)" << std::endl;
    *this = My_String2(s);
    return *this;
}
My_String2& My_String2::operator+(const My_String2& s) {
    int len_s1 = len;
    int len_s2 = s.len;
    len = len_s1 + len_s2;
    char* temp = new char[len + 1];
    strcpy(temp, str);
    for (int i = len_s1; i < len; i++) {
        temp[i] = s[i - len_s1];
    }
    delete[] str;
    str = new char[len + 1];
    str[len + 1] = '\0';
    strcpy(str, temp);
    delete[] temp;
    return *this;
}
My_String2& My_String2::operator+(const char* s) {
    // int len_s1 = len;
    // int len_s2 = strlen(s);
    // len = len_s1 + len_s2;
    // char* temp = new char[len + 1];
    // strcpy(temp, str);
    // for (int i = len_s1; i < len; i++) {
    //     temp[i] = s[i - len_s1];
    // }
    // delete[] str;
    // str = new char[len + 1];
    // str[len + 1] = '\0';
    // strcpy(str, temp);
    // delete[] temp;
    *this = *this + My_String2(s);
    return *this;
}
const char& My_String2::operator[](int i) const {
    return str[i];
}
bool My_String2::operator==(const My_String2& s) {
    if (len != s.len) {
        return false;
    } else {
        for (int i = 0; i < len + 1; i++) {
            if (str[i] != s.str[i]) {
                return false;
            }
        }
    }
    return true;
}
void My_String2::stringup() {
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}
void My_String2::stringlow() {
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}
int My_String2::has(const char c) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}
std::ostream& operator<<(std::ostream& os, const My_String2& my_s) {
    os << my_s.str;
    return os;
}
std::istream& operator>>(std::istream& is, My_String2& my_s) {
    char temp[My_String2::CINLIM];
    is.get(temp, My_String2::CINLIM);
    if (is) {
        my_s = temp;
        // delete[] my_s.str;
        // my_s.len = strlen(temp);
        // my_s.str = new char[my_s.len + 1];
        // strcpy(my_s.str, temp);
        // std::cout << "operator=(const char*) and operator >>" << std::endl;
    }
    while (is && is.get() != '\n') {
        continue;
    }
    return is;
}
My_String2 operator+(const char* s, const My_String2& my_s) {
    My_String2 temp;
    temp = My_String2(s) + my_s;
    return temp;
}
