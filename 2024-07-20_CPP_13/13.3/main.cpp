#include <iostream>

#include "./dma.h"

static const int SIZE = 4;

int main(int argc, char* argv[]) {
    Dma_ABC* p_dma[SIZE];

    char* temp_char = new char[100];
    int temp_int = 0;

    for (int i = 0; i < SIZE; i++) {
        std::cout << "Label :";
        std::cin >> temp_char;
    }

    delete[] temp_char;

    return 0;
}
