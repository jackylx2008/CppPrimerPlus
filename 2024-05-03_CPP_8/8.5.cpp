#include <iostream>

template <typename T> T maxn(const T ar[]);

int main(int argc, char *argv[]) {
    int i[5] = {1, 2, 3, 4, 5};
    double f[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << "Max int = " << maxn<int>(i) << std::endl;
    std::cout << "Max double = " << maxn(f) << std::endl;
    return 0;
}
template <typename T> T maxn(const T ar[]) {
    T max = ar[0];
    for (int i = 1; i < 5; i++) {
        if (max < ar[i]) {
            max = ar[i];
        }
    }
    return max;
}
