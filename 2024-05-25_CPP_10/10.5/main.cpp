#include <iostream>

#include "./stack.h"

int main() {
    Stack stack;
    customer cu;
    double total = 0;
    char ch;
    std::cout
        << "Press a to add a customer, P to process an order, and Q to exit."
        << std::endl;
    while (std::cin >> ch && toupper(ch) != 'Q') {
        while (std::cin.get() != '\n') {
            continue;
        }
        if (!isalpha(ch)) {
            std::cout << '\a';
            continue;
        }
        switch (ch) {
            case 'a':
            case 'A':
                if (stack.is_full()) {
                    std::cout
                        << "The order of 10 customers has been filled. Please "
                           "process the existing order first !"
                        << std::endl;
                } else {
                    std::cout << "Add customer name : ";
                    std::cin.getline(cu.fullname, 35);
                    std::cout << "Add the customer's consumption amount : ";
                    std::cin >> cu.payment;
                    std::cout << cu.fullname << ": " << cu.payment
                              << " pushed in" << std::endl;
                    stack.push(cu);
                }
                break;
            case 'p':
            case 'P':
                if (stack.is_empty()) {
                    std::cout << " There are currently no unprocessed orders."
                              << std::endl;
                } else {
                    stack.pop(&cu);
                    std::cout << cu.fullname << ": " << cu.payment << " poped "
                              << std::endl;
                    total += cu.payment;
                }
                break;
            default: std::cout << " Input error！！！" << std::endl; break;
        }
        std::cout
            << "Press a to add a customer, P to process an order, and Q to "
               "exit."
            << std::endl;
    }
    std::cout << "Total = " << total << std::endl;
    return 0;
}
