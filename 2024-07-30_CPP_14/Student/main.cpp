#include <iostream>
#include <string>
#include <valarray>

#include "./student.h"

int main(int argc, char* argv[]) {
    double d_valarray[] = {1, 2, 3, 4, 5};
    std::valarray<double> val_score(d_valarray, 5);
    double d_score[3] = {5, 10, 15};
    Student s1;
    Student s2("s2", 10);
    Student s3(5);
    Student s4("s4", val_score);
    Student s5("s5", d_score, 3);
    std::cout << s1 << std::endl;
    s1 = s5;
    std::cout << "operator=" << std::endl;
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    std::cout << s4 << std::endl;
    std::cout << s5 << std::endl;
    std::cout << "cin" << std::endl;
    std::cin >> s5;
    while (std::cin.get() != '\n') continue;
    std::cout << s5 << std::endl;
    getline(std::cin, s5);
    std::cout << s5 << std::endl;

    return 0;
}
