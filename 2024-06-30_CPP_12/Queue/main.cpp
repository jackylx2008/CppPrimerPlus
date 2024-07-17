#include <iostream>

#include "./My_Queue.h"

const int SIZE = 5;
int main(int argc, char *argv[]) {
    double test_arr[SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0};
    My_Queue my_q(SIZE);
    for (int i = 0; i < SIZE; i++) {
        my_q.push(test_arr[i]);
    }
    std::cout << "show_queue--------" << std::endl;
    my_q.show_queue();
    Item pop_item;
    if (my_q.pop(pop_item)) {
        std::cout << "pop_item = " << pop_item << std::endl;
    } else {
        std::cout << "Nothin to pop" << std::endl;
    }
    if (my_q.pop(pop_item)) {
        std::cout << "pop_item = " << pop_item << std::endl;
    } else {
        std::cout << "Nothin to pop" << std::endl;
    }

    std::cout << "Deconstrator" << std::endl;

    return 0;
}
