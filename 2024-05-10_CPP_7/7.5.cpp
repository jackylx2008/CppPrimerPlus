#include <cstdint>
#include <iostream>

std::int64_t factorial(const std::int64_t n);
int main(int argc, char *argv[]) {
    std::int64_t n;
    std::cout << "Enter a int:" << std::endl;
    while ((std::cin >> n) && n > 0) {
        std::cout << "The " << n << "!= ";
        std::cout << factorial(n) << std::endl;
        std::cout << "Next two numbers (q to quit): ";
    }

    return 0;
}

std::int64_t factorial(const std::int64_t n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
