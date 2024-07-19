#include <iostream>

#include "./Queue.h"

int main(int argc, char *argv[]) {
    Queue q1(5);
    q1.enqueue(Customer());
    q1.enqueue(Customer());
    q1.enqueue(Customer());
    q1.enqueue(Customer());
    q1.enqueue(Customer());
    q1.show();
    std::cout << "dequeue" << std::endl;
    Item i1;
    q1.dequeue(i1);
    q1.show();

    return 0;
}
