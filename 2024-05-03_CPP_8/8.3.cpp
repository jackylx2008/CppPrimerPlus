#include <cctype>
#include <iostream>
#include <string>
const int SIZE = 50;

void to_upper(const char *s, char *dst, int n);
void to_upper(std::string *s);

int main(int argc, char *argv[]) {
    std::string s;
    while (true) {
        std::cout << "Enter a string q to exit" << std::endl;
        std::getline(std::cin, s);
        if (s == "q") {
            std::cout << "Bye" << std::endl;
            break;
        } else {
            to_upper(&s);
            std::cout << s << std::endl;
        }
    }
    return 0;
}

void to_upper(const char *s, char *dst, int n) {
    int i = 0;
    while (s[i] != '\0' && i < n) {
        if (s[i] > 96 && s[i] < 123) {
            dst[i] = s[i] - 32;
        } else {
            dst[i] = s[i];
        }
        i++;
    }
    dst[i] = '\0';
}
void to_upper(std::string *s) {
    for (int i = 0; i < (*s).size(); i++) {
        (*s)[i] = toupper((*s)[i]);
    }
}
