#include <cstdint>
#include <cstdlib>
#include <ios>
#include <iostream>

#include "./Vector.h"

int main(int argc, char *argv[]) {
    using namespace VECTOR;
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    int steps = 0;
    double target;
    double dstep;
    std::cout << "Enter target distance (q to quit): ";
    while (std::cin >> target) {
        srand((int)time(NULL));
        std::cout << "Enter step length: ";
        if (!(std::cin >> dstep)) break;
        std::cout << "Target Distance: " << target << " Step Size: " << dstep
                  << "\n";
        while (result.magval() < target) {
            direction = rand() % 359;
            step.reset(dstep, direction, Vector::POLOR);
            std::cout << steps << ": (x,y) = " << result << "\n";
            result = result + step;
            steps++;
        }
        std::cout << "After " << steps
                  << " steps, the subject "
                     "has the following location: "
                  << result << "\n";
        result.polar_mode();
        std::cout << " or\n(m,a) = " << result << std::endl;
        std::cout << "Average outward distance per step = "
                  << result.magval() / steps << std::endl;
        steps = 0;
        result.reset(0.0, 0.0);
        std::cout << "Enter target distance (q to quit): ";
    }
    std::cout << "Bye!\n";
    std::cin.clear();
    while (std::cin.get() != '\n') continue;
    return 0;
}
