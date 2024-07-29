#include <cstring>
#include <iostream>

#include "./dma.h"

Dma_ABC::Dma_ABC(const char* l, int r) {
    if (l != nullptr) {
        label = new char[strlen(l) + 1];
        strcpy(label, l);
    } else {
        label = nullptr;
    }
    rating = r;
}
Dma_ABC::Dma_ABC(const Dma_ABC& dma) {
    if (dma.label != nullptr) {
        label = new char[strlen(dma.label) + 1];
        strcpy(label, dma.label);
    } else {
        label = nullptr;
    }
    rating = dma.rating;
}
Dma_ABC::~Dma_ABC() {
    delete[] label;
}
Dma_ABC& Dma_ABC::operator=(const Dma_ABC& dma) {
    if (this == &dma) {
        return *this;
    }
    delete[] label;
    label = new char[strlen(dma.label) + 1];
    strcpy(label, dma.label);
    rating = dma.rating;
    return *this;
}
void Dma_ABC::View() const {
    std::cout << "Label: " << label << std::endl;
    std::cout << "Rating: " << rating << std::endl;
}

baseDMA::baseDMA(const char* l, int r) : Dma_ABC(l, r) {
}
baseDMA::baseDMA(const baseDMA& bd) : Dma_ABC((const Dma_ABC&)bd) {
}
baseDMA::~baseDMA() {
}
baseDMA& baseDMA::operator=(const baseDMA& bd) {
    if (this == &bd) {
        return *this;
    }
    Dma_ABC::operator=((const Dma_ABC&)bd);
    return *this;
}
void baseDMA::View() const {
    Dma_ABC::View();
}
