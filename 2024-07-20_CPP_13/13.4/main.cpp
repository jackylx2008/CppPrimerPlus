#include <iostream>

#include "./port.h"

int main(int argc, char *argv[]) {
    VintagePort p1;
    VintagePort p2("Wine", 100, "wine", 10);
    p1.Show();
    p2.Show();
    p1 = p2;
    p2 += 10;
    p1 -= 50;
    p1.Show();
    p2.Show();
    p1 -= 100;
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;

    return 0;
}
