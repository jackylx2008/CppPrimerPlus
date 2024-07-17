#include <iostream>

#include "./stack.h"

int main(int argc, char* argv[]) {
    Stack customer_stack;
    customer* c1 = new customer;
    double total = 0.0;
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Name?" << std::endl;
        std::cin.getline(c1->fullname, 40);
        std::cout << "Payment?" << std::endl;
        std::cin >> c1->payment;
        while (std::cin.get() != '\n') {
            continue;
        }
        customer_stack.push(*c1);
    }
    customer_stack.show();

    if (!customer_stack.is_empty()) {
        customer_stack.pop(c1);
        std::cout << c1->fullname << "is poped, payment: " << c1->payment
                  << std::endl;
        total += c1->payment;
        std::cout << total << std::endl;
    }

    delete c1;
    return 0;
}
