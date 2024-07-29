#include <cstring>
#include <iostream>

#include "./dma.h"

Dma_ABC::Dma_ABC(const char *l, int r) {
    if (l != nullptr) {
        label = new char[strlen(l) + 1];
        strcpy(label, l);
    } else {
        label = nullptr;
    }
    rating = r;
}
Dma_ABC::Dma_ABC(const Dma_ABC &dma) {
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
Dma_ABC &Dma_ABC::operator=(const Dma_ABC &dma) {
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

baseDMA::baseDMA(const char *l, int r) : Dma_ABC(l, r) {
}
baseDMA::baseDMA(const baseDMA &bd) : Dma_ABC((const Dma_ABC &)bd) {
}
baseDMA::~baseDMA() {
}
baseDMA &baseDMA::operator=(const baseDMA &bd) {
    if (this == &bd) {
        return *this;
    }
    Dma_ABC::operator=((const Dma_ABC &)bd);
    return *this;
}
void baseDMA::View() const {
    Dma_ABC::View();
}
lacksDMA::lacksDMA(const char *l, int r, const char *c) : Dma_ABC(l, r) {
    if (strlen(c) > 39) {
        strncpy(color, c, 39);
        color[39] = '\0';
    } else {
        strcpy(color, c);
    }
}
lacksDMA::lacksDMA(const lacksDMA &ld) : Dma_ABC((const Dma_ABC &)ld) {
    strcpy(color, ld.color);
}
lacksDMA::~lacksDMA() {
}
lacksDMA &lacksDMA::operator=(const lacksDMA &ld) {
    if (this == &ld) {
        return *this;
    }
    Dma_ABC::operator=((const Dma_ABC &)ld);
    strcpy(color, ld.color);
    return *this;
}
void lacksDMA::View() const {
    Dma_ABC::View();
    std::cout << "Color: " << color << std::endl;
}

hasDMA::hasDMA(const char *l, int r, const char *s) : Dma_ABC(l, r) {
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA &hd) : Dma_ABC((const Dma_ABC &)hd) {
    delete[] style;
    style = new char[strlen(hd.style) + 1];
    strcpy(style, hd.style);
}
hasDMA::~hasDMA() {
    delete[] style;
}
hasDMA &hasDMA::operator=(const hasDMA &hd) {
    if (this == &hd) {
        return *this;
    }
    Dma_ABC::operator=((const Dma_ABC &)hd);
    delete[] style;
    style = new char[strlen(hd.style) + 1];
    strcpy(style, hd.style);
    return *this;
}
void hasDMA::View() const {
    Dma_ABC::View();
    std::cout << "Style: " << style << std::endl;
}
