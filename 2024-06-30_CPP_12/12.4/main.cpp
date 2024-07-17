#include <iostream>

#include "./Stack.h"

int main(int argc, char *argv[]) {
    Stack s1;
    Stack s2;
    for (int i = 0; i < 11; i++) {
        if (!s2.push((i + 1) * 100)) {
            std::cout << "isfull" << std::endl;
        }
    }
    Stack s3(s2);
    for (int i = 0; i < 11; i++) {
        Item temp;
        if (s3.pop(temp)) {
            std::cout << "pop = " << temp << std::endl;
        } else {
            std::cout << "isempty" << std::endl;
        }
    }
    s1 = s2;
    for (int i = 0; i < 11; i++) {
        Item temp;
        if (s1.pop(temp)) {
            std::cout << "s1 pop = " << temp << std::endl;
        } else {
            std::cout << "s1 isempty" << std::endl;
        }
    }
    return 0;
}
