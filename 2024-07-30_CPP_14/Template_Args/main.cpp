#include <iostream>

#include "./stack.h"

template <template <typename T> class S>
class Crab {
  private:
    S<int> t1;
    S<double> t2;

  public:
    bool push(int a, double b);
    bool pop(int* a, double* b);
    bool pop(int& a, double& b);
    void show();
};

template <template <typename T> class Thing>
bool Crab<Thing>::push(int a, double b) {
    return t1.push(a) && t2.push(b);
}

template <template <typename T> class Thing>
bool Crab<Thing>::pop(int* a, double* b) {
    return t1.pop(a) && t2.pop(b);
}
template <template <typename T> class Thing>
bool Crab<Thing>::pop(int& a, double& b) {
    return t1.pop(a) && t2.pop(b);
}
template <template <typename T> class Thing>
void Crab<Thing>::show() {
    t1.show();
    t2.show();
}

int main(int argc, char* argv[]) {
    int a = 0;
    double b = 0.0;
    std::cout << "Enter a int and a double. 0 0 to exit" << std::endl;
    Crab<Stack> int_double;
    while ((std::cin >> a >> b) && (a != 0) && (b != 0.0)) {
        int_double.push(a, b);
    }
    while (int_double.pop(&a, &b)) {
        std::cout << "a= " << a << " b= " << b << std::endl;
    }
    return 0;
}
