#include <iostream>
#include <string>

#include "./wine_private.h"

template <typename T1, typename T2>
void PairArray<T1, T2>::Show(int i) const {
    std::cout << "\t" << year[i] << "\t" << bottles[i] << std::endl;
}
template <typename T1, typename T2>
int PairArray<T1, T2>::Bottles(int i) const {
    return bottles[i];
}
template <typename T1, typename T2>
void PairArray<T1, T2>::SetBottles(int y, const int yr[], const int bot[]) {
    year = ArrayInt(yr, y);
    bottles = ArrayInt(bot, y);
}

const int temp[1] = {0};
Wine::Wine(const char* str, int y)
    : std::string(str), PairArray<ArrayInt, ArrayInt>(0, temp, temp) {
    years = y;
    year = new int[y];
    bottles = new int[y];
}
Wine::Wine(const char* str, int y, const int yr[], const int bot[])
    : std::string(str), PairArray<ArrayInt, ArrayInt>(y, yr, bot) {
    years = y;
    year = nullptr;
    bottles = nullptr;
}

void Wine::Show() const {
    std::cout << "Wine: " << (const std::string)(*this) << std::endl;
    std::cout << "\tYear\tBottles" << std::endl;
    for (int i = 0; i < years; i++) {
        PairArray<ArrayInt, ArrayInt>::Show(i);
    }
}
const std::string& Wine::Label() const {
    return (const std::string&)(*this);
}
int Wine::sum() const {
    int sum = 0;
    for (int i = 0; i < years; i++) {
        sum += PairArray<ArrayInt, ArrayInt>::Bottles(i);
    }
    return sum;
}
void Wine::GetBottles() {
    std::cout << "Enter " << (const std::string) * this << "data for " << years
              << "year(s):" << std::endl;
    for (int i = 0; i < years; i++) {
        std::cout << "Ener year: ";
        std::cin >> year[i];
        std::cout << "Enter bottles for that year: ";
        std::cin >> bottles[i];
    }
    PairArray<ArrayInt, ArrayInt>::SetBottles(years, year, bottles);
}
