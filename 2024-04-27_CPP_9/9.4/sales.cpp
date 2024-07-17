#include <iostream>

#include "./sales.h"

void SALES::setSales(SALES::Sales *s, const double ar[], int n) {
    double sum = 0.0;
    for (int i = 0; i < SALES::QUARTERS; i++) {
        s->sales[i] = ar[i];
        if (i >= n) {
            s->sales[i] = 0;
        }
        sum += s->sales[i];
    }
    s->average = sum / n;
    s->max = s->min = s->sales[0];
    for (int i = 1; i < SALES::QUARTERS; i++) {
        if (s->max < s->sales[i]) {
            s->max = s->sales[i];
        }
        if (s->min > s->sales[i]) {
            s->min = s->sales[i];
        }
    }
}
void SALES::setSales(SALES::Sales *s) {
    double temp_sales[SALES::QUARTERS];
    int n = 0;
    for (int i = 0; i < SALES::QUARTERS; i++) {
        while (true) {
            std::cout << "Enter QUARTERS " << i + 1 << " Sales" << std::endl;
            if (std::cin >> temp_sales[i]) {
                break;
            } else {
                std::cout << "Error input" << std::endl;
                std::cin.clear();
                while (std::cin.get() != '\n') {
                    continue;
                }
            }
        }
        // std::cin >> temp_sales[i];
    }
    SALES::setSales(s, temp_sales, SALES::QUARTERS);
}

void SALES::showSales(const SALES::Sales &s) {
    for (int i = 0; i < SALES::QUARTERS; i++) {
        std::cout << "QUARTERS " << i + 1 << ": " << s.sales[i] << std::endl;
    }
    std::cout << "Avg = " << s.average << std::endl;
    std::cout << "Max = " << s.max << std::endl;
    std::cout << "Min = " << s.min << std::endl;
}
