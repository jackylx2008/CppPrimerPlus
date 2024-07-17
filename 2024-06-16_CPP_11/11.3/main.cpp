#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <ios>
#include <iostream>

#include "./Vector.h"

int main(int argc, char* argv[]) {
    using namespace VECTOR;
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    int64_t steps = 0;
    double target;
    double dstep;
    int loop_times = 0;
    int times = 0;
    int min = 0, max = 0, sum = 0;
    double avg;
    sum = 0;
    std::cout << "Enter how many times: ";
    if (std::cin >> loop_times && loop_times > 0) {
        std::cout << "Enter target distance: ";
        while (!(std::cin >> target)) {
            std::cout << "target input error input\n";
            std::cout << "Enter target distance: ";
            std::cin.clear();
            while (std::cin.get() != '\n') continue;
        }
        std::cout << "Enter step length: ";
        while (!(std::cin >> dstep)) {
            std::cout << "dstep error input\n";
            std::cout << "Enter step length: ";
            std::cin.clear();
            while (std::cin.get() != '\n') continue;
        }
        srand((unsigned int)time(NULL));
        for (int i = 0; i < loop_times; i++) {
            while (result.magval() < target) {
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POLOR);
                result = result + step;
                steps++;
            }

            sum += steps;
            if (min == 0) {
                min = steps;
            } else if (steps < min) {
                min = steps;
            }
            if (steps > max) {
                max = steps;
            }
            steps = 0;
            result.reset(0.0, 0.0, Vector::POLOR);
            // if (times < loop_times) {
            //     std::cout << "Enter target distance (q to quit): ";
            // }
        }

        avg = (double)sum / loop_times;
        std::cout << "max = " << max << " min = " << min << "  avg = " << avg
                  << std::endl;
        std::cout << "Bye!\n";
        std::cin.clear();
        while (std::cin.get() != '\n') continue;
    }
    return 0;
}
