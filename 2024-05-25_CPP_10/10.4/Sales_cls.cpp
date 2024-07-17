#include <iostream>

#include "./Sales_cls.h"

SALES::Sales::Sales() {
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
    SALES::Sales::setSales(temp_sales, SALES::QUARTERS);
}

SALES::Sales::Sales(const double ar[], int n) {
    SALES::Sales::setSales(ar, n);
}
void SALES::Sales::setSales(const double ar[], int n) {
    double sum = 0.0;
    for (int i = 0; i < SALES::QUARTERS; i++) {
        sales[i] = ar[i];
        if (i >= n) {
            sales[i] = 0;
        }
        sum += sales[i];
    }
    average = sum / n;
    max = min = sales[0];
    for (int i = 1; i < SALES::QUARTERS; i++) {
        if (max < sales[i]) {
            max = sales[i];
        }
        if (min > sales[i]) {
            min = sales[i];
        }
    }
}

void SALES::Sales::showSales() const {
    for (int i = 0; i < SALES::QUARTERS; i++) {
        std::cout << "QUARTERS " << i + 1 << ": " << sales[i] << std::endl;
    }
    std::cout << "Avg = " << average << std::endl;
    std::cout << "Max = " << max << std::endl;
    std::cout << "Min = " << min << std::endl;
}
