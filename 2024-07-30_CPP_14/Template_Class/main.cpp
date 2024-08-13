#include <iostream>

#include "./stack.h"

const int SIZE = 6;

const char* str[SIZE] = {
    "1. ", "2. ", "3. ", "4. ", "5. ", "6. ",
};

int main(int argc, char* argv[]) {
    Stack<const char*> my_stack;
    for (int i = 0; i < SIZE; i++) {
        my_stack.push(str[i]);
    }
    my_stack.show();

    const char* pop_item;
    while (my_stack.pop(&pop_item)) {
        std::cout << "pop_item = " << pop_item << std::endl;
    }

    my_stack.show();
}
