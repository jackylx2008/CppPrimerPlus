#include <iostream>

const int MAX = 5;

double* fill_array(double* begin, double* end);
void show_array(const double* begin, const double* end);
void revalue(double* begin, double* end, double v);

int main(int argc, char* argv[]) {
    // double test[MAX] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double test[MAX];
    double* p_t = fill_array(test, &test[MAX]);
    show_array(test, p_t);
    revalue(test, p_t, 10.2);
    show_array(test, p_t);
    return 0;
}

double* fill_array(double* begin, double* end) {
    double temp;
    double* p_t;
    int i = 0;
    for (p_t = begin; p_t != end; p_t++) {
        std::cout << "Enter value #" << i + 1 << std::endl;
        std::cin >> temp;
        if (std::cin.fail()) {  // bad input
            std::cin.clear();
            while (std::cin.get() != '\n') continue;
            std::cout << "Bad input; input process terminated" << std::endl;
            break;
        } else if (temp < 0) {
            break;
        }
        *p_t = temp;
        i++;
    }
    std::cout << i << std::endl;
    return p_t;
}

void show_array(const double* begin, const double* end) {
    double* pt = (double*)begin;
    for (; pt != end; pt++) {
        std::cout << *pt << " ";
    }
    std::cout << std::endl;
}

void revalue(double* begin, double* end, double v) {
    for (double* pt = begin; pt != end; pt++) {
        *pt = v;
    }
}
