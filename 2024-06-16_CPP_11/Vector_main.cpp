#include <cmath>
#include <iostream>

#include "./Vector.h"

int main(int argc, char *argv[]) {
    using namespace VECTOR;
    Vector v1(sqrt(2), sqrt(2));
    Vector v2(sqrt(3), 1.0);
    std::cout << v1 * 2 << std::endl;
    std::cout << v2 << std::endl;
    std::cout << v1 - v1 << std::endl;

    return 0;
}
