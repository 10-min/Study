#include "move.h"
#include <iostream>

Move::Move(double a, double b) {
    x = a;
    y = b;
}

void Move::showmove() const {
    using namespace std;

    cout << "x: " << x << ", y: " << y << endl;
}

Move Move::add(Move & m) const {
    return Move(m.x + x, m.y + y);
}

void Move::reset(double a, double b) {
    x = a;
    y = b;
}