#include <iostream>

#include "./stack.h"

const int S = 6;

int main(int argc, char *argv[]) {
    Stack my_stack;
    for (int i = 0; i < S; i++) {
        my_stack.push(i);
    }
    my_stack.show();
    Item pop_item;
    for (int i = 0; i < S; i++) {
        my_stack.pop(&pop_item);
        std::cout << "pop_item = " << pop_item << std::endl;
    }
    my_stack.show();
}
