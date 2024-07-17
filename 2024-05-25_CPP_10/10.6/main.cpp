#include "Move.h"

int main(int argc, char *argv[]) {
    Move m1(1, 2);
    Move m2(3, 4);
    Move m3;
    m3 = m1.add(m2);
    m3.showmove();
    m3.reset();
    m3.showmove();
    return 0;
}
