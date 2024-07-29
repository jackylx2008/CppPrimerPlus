#include <cstdlib>
#include <cstring>
#include <iostream>

#include "./Cow.h"

Cow::Cow() {
    name[0] = '\0';
    // hobby = new char[1];
    // hobby[0] = '\0';
    hobby = nullptr;
    weight = 0.0;
}
Cow::Cow(const char* nm, const char* ho, double wt) {
    strncpy(name, nm, 19);
    if (strlen(nm) > 20) {
        name[19] = '\0';
    }
    // strcpy(name, nm);
    hobby = new char[strlen(ho) + 1];
    strcpy(hobby, ho);
    weight = wt;
}
Cow::Cow(const Cow& c) {
    strcpy(name, c.name);
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}
Cow::~Cow() {
    if (hobby != nullptr) delete[] hobby;
}
Cow& Cow::operator=(const Cow& c) {
    if (this == &c) return *this;
    strcpy(name, c.name);
    delete[] hobby;
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    return *this;
}
void Cow::ShowCow() const {
    if (hobby != nullptr)
        std::cout << name << " : " << hobby << " weight = " << weight
                  << std::endl;
    else
        std::cout << name << " : " << " weight = " << weight << std::endl;
}
