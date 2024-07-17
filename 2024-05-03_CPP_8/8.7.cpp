#include <iostream>
template <typename T>
T SumArray(T arr[], int n);
template <typename T>
T SumArray(T *arr[], int n);

struct debts {
    char name[50];
    double amout;
};

int main(int argc, char *argv[]) {
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] = {
        {"Ima Wolfe", 2400.0}, {"Ura Foxe", 1300.0}, {"Iby Stout", 1800.0}};
    double *pd[3];

    // set pointers to the amount members of the structures in mr_E
    for (int i = 0; i < 3; i++) {
        pd[i] = &mr_E[i].amout;
    }
    std::cout << "Sum of things = " << SumArray(things, 6) << std::endl;
    std::cout << "Sum of debts = " << SumArray(pd, 3) << std::endl;

    return 0;
}
template <typename T>
T SumArray(T arr[], int n) {
    std::cout << "template A" << std::endl;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}
template <typename T>
T SumArray(T *arr[], int n) {
    std::cout << "template B" << std::endl;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += *arr[i];
    }
    return sum;
}
