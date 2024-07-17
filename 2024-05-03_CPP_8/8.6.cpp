#include <cstring>
#include <iostream>

template <typename T> T maxn(T *ar, int n);
template <> const char *maxn<const char *>(const char *ar[], int n);

int main(int argc, char *argv[]) {
    int arr_int[6] = {1, 2, 3, 4, 5, 6};
    double arr_double[4] = {1.1, 2.2, 3.3};
    const char *arr_str[5] = {"aaaa aaaa ", "bbb bbbb", "ccc ccc", "xin", "ll"};
    std::cout << "Max int = " << maxn(arr_int, 6) << std::endl;
    std::cout << "Max double = " << maxn(arr_double, 4) << std::endl;
    std::cout << "Max char* = " << maxn(arr_str, 5) << std::endl;
    return 0;
}
template <typename T> T maxn(T *ar, int n) {
    T max = ar[0];
    for (int i = 1; i < n; i++) {
        if (max < ar[i]) {
            max = ar[i];
        }
    }
    return max;
}
template <> const char *maxn<const char *>(const char *ar[], int n) {
    const char *tmp = ar[0];
    for (int i = 1; i < n; i++) {
        if (strlen(tmp) < strlen(ar[i])) {
            tmp = ar[i];
        }
    }
    return tmp;
}
