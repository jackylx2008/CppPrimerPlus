#include <iostream>
template <typename T> void SumArray(T arr[], int n);
template <typename T> void ShowArray(T* arr[], int n);

struct debts {
    char name[50];
    double amout;
};

int main(int argc, char* argv[]) {
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] = {
        {"Ima Wolfe", 2400.0}, {"Ura Foxe", 1300.0}, {"Iby Stout", 1800.0}};
    double* pd[3];

    // set pointers to the amount members of the structures in mr_E
    for (int i = 0; i < 3; i++) {
        pd[i] = &mr_E[i].amout;
    }
    std::cout << "Listing Mr.E's counts of things" << std::endl;
    // things is an array of int
    SumArray(things, 6);  // uses template A
    std::cout << "Listing Mr.E's debts" << std::endl;
    // pd is an array of pointers to double
    ShowArray(pd, 3);

    return 0;
}
template <typename T> void SumArray(T arr[], int n) {
    std::cout << "template A" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}
template <typename T> void ShowArray(T* arr[], int n) {
    std::cout << "template B" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << *arr[i] << ' ';
    }
    std::cout << std::endl;
}
