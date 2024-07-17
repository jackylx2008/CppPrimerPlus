#include <iostream>

#include "./Plorg.h"

void Plorg::show() {
    std::cout << "name = " << name << " ci =" << contentment_index << std::endl;
}

void Plorg::set_ci(int ci) {
    contentment_index = ci;
}
