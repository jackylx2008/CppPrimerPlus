#include <iostream>

#include "./Move.h"

Move::Move(double a, double b) {
    this->x = a;
    this->y = b;
}

void Move::showmove() const {
    std::cout << "x = " << this->x << " y = " << this->y << std::endl;
}

Move Move::add(const Move& m) const {
    Move* new_move = new Move;
    new_move->x = this->x + m.x;
    new_move->y = this->y + m.y;
    return *new_move;
}

void Move::reset(double a, double b) {
    this->x = a;
    this->y = b;
}
