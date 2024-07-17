#include <iostream>

double avg();
int main(int argc, char *argv[]) {
    while (true) {
        double result = avg();
        std::cout << "result = " << result << std::endl;
        if (result == 0.0) {
            break;
        }
    }
    return 0;
}

double avg() {
    double res = 0.0;
    int x, y;
    while (true) {
        std::cout << "Input x int" << std::endl;
        if (!(std::cin >> x)) {
            std::cout << "Error input" << std::endl;
            std::cin.clear();
            while (std::cin.get() != '\n') {
            }
        } else {
            break;
        }
    }
    while (true) {
        std::cout << "Input y int" << std::endl;
        if (!(std::cin >> y)) {
            std::cout << "Error input" << std::endl;
            std::cin.clear();
            while (std::cin.get() != '\n') {
            }
        } else {
            break;
        }
    }
    if (x == 0 || y == 0) {
        return 0.0;
    }
    res = 2.0 * x * y / (x + y);

    return res;
}
