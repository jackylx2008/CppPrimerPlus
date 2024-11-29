#include <iostream>

#include "./Tv.h"

bool Tv::volup() {
    if (++volumn >= MaxVal) {
        volumn = MaxVal;
        return false;
    } else {
        return true;
    }
}
bool Tv::voldown() {
    if (--volumn <= MinVal) {
        volumn = MinVal;
        return false;
    } else {
        return true;
    }
}
void Tv::chanup() {
    if (++channel > maxchannel) {
        channel = 1;
    }
}
void Tv::chandown() {
    if (--channel < 1) {
        channel = maxchannel;
    }
}
void Tv::settings() const {
    std::cout << "Tv is ";
    if (state) {
        std::cout << "On" << std::endl;
    } else {
        std::cout << "Off" << std::endl;
        return;
    }
    std::cout << "Tv volumn is " << volumn << std::endl;
    std::cout << "Tv channel is " << channel << std::endl;
    std::cout << "Tv mode is ";
    if (mode) {
        std::cout << "Cable" << std::endl;
    } else {
        std::cout << "Antenna" << std::endl;
    }
    std::cout << "Tv input is ";
    if (input) {
        std::cout << "DVD" << std::endl;
    } else {
        std::cout << "TV" << std::endl;
    }
}
