#include <cstring>
#include <iostream>

struct CandyBar {
    char brand[40];
    double weight;
    int calorie;
};

void SetCandyBar(CandyBar *c, const char *brand = "Mill",
                 const double weight = 2.85, const int calorie = 10);
void ShowCandyBar(const CandyBar &c);
int main(int argc, char *argv[]) {
    CandyBar c1;
    SetCandyBar(&c1);
    ShowCandyBar(c1);
    SetCandyBar(&c1, "df", 9.8, 324);
    ShowCandyBar(c1);
    return 0;
}

void SetCandyBar(CandyBar *c, const char *brand, const double weight,
                 const int calorie) {
    strcpy(c->brand, brand);
    c->weight = weight;
    c->calorie = calorie;
}
void ShowCandyBar(const CandyBar &c) {
    std::cout << "Brand = " << c.brand << std::endl;
    std::cout << "Weight = " << c.weight << std::endl;
    std::cout << "Calorie = " << c.calorie << std::endl;
}
