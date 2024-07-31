#include <iostream>

#include "./dma.h"

static const int SIZE = 3;

void test(void) {
    hasDMA hd1("hd1", 100, "hd1");
    Dma_ABC* p1 = &hd1;
    p1->View();
}
int main(int argc, char* argv[]) {
    Dma_ABC* p_dma[SIZE];

    char* temp_char = new char[100];
    char* color = new char[40];
    char* style = new char[100];
    int temp_int = 0;
    char type_dma = '0';

    for (int i = 0; i < SIZE; i++) {
        std::cout << "Label :";
        std::cin >> temp_char;
        std::cout << "Rating :";
        std::cin >> temp_int;
        std::cout
            << "Which type DMA: 1 for baseDMA; 2 for lacksDMA; 3 for hasDMA"
            << std::endl;
        while (std::cin >> type_dma) {
            if (type_dma == '1' || type_dma == '2' || type_dma == '3') {
                break;
            } else {
                std::cout << "Input error. Retry" << std::endl;
            }
        }

        switch (type_dma) {
            case '1': {
                p_dma[i] = new baseDMA(temp_char, temp_int);
                break;
            }
            case '2': {
                std::cout << "Color :";
                std::cin >> color;
                p_dma[i] = new lacksDMA(temp_char, temp_int, color);
                break;
            }
            case '3': {
                std::cout << "Style :";
                std::cin >> style;
                p_dma[i] = new hasDMA(temp_char, temp_int, style);
                break;
            }
            default: break;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        (*p_dma[i]).View();
        std::cout << std::endl;
    }
    for (int i = 0; i < SIZE; i++) {
        delete p_dma[i];
    }
    delete[] temp_char;

    // test();
    return 0;
}
