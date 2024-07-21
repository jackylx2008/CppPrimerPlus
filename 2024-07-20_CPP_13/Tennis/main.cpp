#include <iostream>

#include "./TennisPlayer.h"

int main(int argc, char *argv[]) {
    TennisPlayer t1("liu", "xin", true);
    RatedPlayer r1("r1", "r1", true, 100);
    RatedPlayer r2(t1, 200);
    RatedPlayer r3(r1);
    r1.ShowPlayer();
    r2.ShowPlayer();
    std::cout << "-------R3-------" << std::endl;
    r3.ShowPlayer();
    std::cout << "-------R4-------" << std::endl;
    RatedPlayer r4 = r3;
    r4.ShowPlayer();
}
