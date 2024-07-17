#include <array>
#include <iostream>
#include <string>
const int Seasons = 4;
const char* Snames[] = {"Spring", "Summer", "Fall", "Winter"};

struct Sepenses {
    double expenses[Seasons];
};

void fill(double expenses[]);
void show(double expenses[]);
void fill(Sepenses* pa);
void show(const Sepenses da);
int main() {
    double expenses[Seasons];
    fill(expenses);
    show(expenses);
    // std::cin.get();
    // std::cin.get();
    Sepenses S_exp;
    fill(&S_exp);
    show(S_exp);
    return 0;
}

void fill(double expenses[]) {
    for (int i = 0; i < Seasons; i++) {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> expenses[i];
    }
}

void show(double expenses[]) {
    double total = 0.0;
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++) {
        std::cout << Snames[i] << ": $" << expenses[i] << '\n';
        total += expenses[i];
    }
    std::cout << "Total: $" << total << '\n';
}
void fill(Sepenses* pa) {
    for (int i = 0; i < Seasons; i++) {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> pa->expenses[i];
    }
}
void show(const Sepenses da) {
    double total = 0.0;
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++) {
        std::cout << Snames[i] << ": $" << da.expenses[i] << '\n';
        total += da.expenses[i];
    }
    std::cout << "Total: $" << total << '\n';
}
