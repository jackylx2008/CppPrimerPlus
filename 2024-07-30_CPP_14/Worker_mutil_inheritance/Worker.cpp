#include <iostream>

#include "./Worker.h"

void Worker::Set_data() {
    std::cout << "Set Name: ";
    getline(std::cin, Name);
    std::cout << "Set ID: ";
    std::cin >> ID;
    while (std::cin.get() != '\n') continue;
}
void Worker::Get_data() const {
    std::cout << "Name: " << Name << std::endl;
    std::cout << "ID: " << ID << std::endl;
}

const char* Singer::pv_type[] = {"", "High", "Medium", "Low", "Bass"};
void Singer::Set_data() {
    for (int i = 1; i < Vtypes; i++) {
        std::cout << i << " for " << pv_type[i] << "; ";
    }
    std::cout << std::endl;
    std::cout << "Voice: ";
    std::cin >> Voice;
    while (std::cin.get() != '\n') continue;
}
void Singer::Get_data() const {
    std::cout << "Voice type: " << pv_type[Voice] << std::endl;
}
void Singer::Set() {
    Worker::Set_data();
    Set_data();
}
void Singer::Show() const {
    Worker::Get_data();
    Get_data();
}

void Waiter::Set_data() {
    std::cout << "Power: ";
    std::cin >> Power;
    while (std::cin.get() != '\n') continue;
}
void Waiter::Get_data() const {
    std::cout << "Power: " << Power << std::endl;
}
void Waiter::Set() {
    Worker::Set_data();
    Set_data();
}
void Waiter::Show() const {
    Worker::Get_data();
    Get_data();
}

void SingerWaiter::Set() {
    Worker::Set_data();
    Singer::Set_data();
    Waiter::Set_data();
}
void SingerWaiter::Show() const {
    Worker::Get_data();
    Singer::Get_data();
    Waiter::Get_data();
}
