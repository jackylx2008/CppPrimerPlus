#include <iostream>

int& add(int& a) {
    a += 100;
    return a;
}

int* add_pr(int* a) {
    *a += 200;
    return a;
}

int main(int argc, char* argv[]) {
    int b = 10;
    std::cout << add(b) << std::endl;
    int c = 20;
    std::cout << *(add_pr(&c)) << std::endl;
    return 0;
}
