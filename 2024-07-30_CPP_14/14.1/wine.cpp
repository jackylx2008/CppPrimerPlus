#include <iostream>
#include <string>
#include <valarray>

#include "./wine.h"

template <typename T1, typename T2>
void Pair<T1, T2>::Show(int i) const {
    std::cout << "\t" << year[i] << "\t" << bottles[i] << std::endl;
}
template <typename T1, typename T2>
int Pair<T1, T2>::Bottles(int i) const {
    return bottles[i];
}

const int temp[1] = {0};

Wine::Wine(const std::string str, int y)
    : name(str),
      years(y),
      years_bottles(Pair<ArrayInt, ArrayInt>(0, temp, temp)) {
    year = new int[y];
    bottles = new int[y];
}
Wine::Wine(const std::string str, int y, const int yr[], const int bot[])
    : name(str), years(y), years_bottles(Pair<ArrayInt, ArrayInt>(y, yr, bot)) {
    year = nullptr;
    bottles = nullptr;
}

void Wine::Show() const {
    std::cout << "Wine: " << name << std::endl;
    std::cout << "\tYear\tBottles" << std::endl;
    for (int i = 0; i < years; i++) {
        years_bottles.Show(i);
    }
}
const std::string& Wine::Label() const {
    return name;
}
int Wine::sum() const {
    int sum = 0;
    for (int i = 0; i < years; i++) {
        sum += years_bottles.Bottles(i);
    }
    return sum;
}
void Wine::GetBottles() {
    std::cout << "Enter " << name << "data for " << years
              << "year(s):" << std::endl;
    for (int i = 0; i < years; i++) {
        std::cout << "Enter year: ";
        std::cin >> year[i];
        std::cout << "Enter bottles for that year: ";
        std::cin >> bottles[i];
    }
    years_bottles = Pair<ArrayInt, ArrayInt>(years, year, bottles);
}
