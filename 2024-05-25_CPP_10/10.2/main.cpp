#include <iostream>

#include "Person.h"

int main(int argc, char *argv[]) {
    Person one;                       // use default constructor
    Person two("Smythecraft");        // use #2 with one default argument
    Person three("Dimwiddy", "Sam");  // use #2, no defaults one.Show();
    std::cout << std::endl;
    one.Show();
    one.FormalShow();
    std::cout << std::endl;
    two.Show();
    two.FormalShow();
    std::cout << std::endl;
    three.Show();
    three.FormalShow();
    return 0;
}
