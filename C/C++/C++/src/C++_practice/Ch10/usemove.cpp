#include "move.h"

int main() {
    Move m(5, 3);
    m.showmove();

    Move n(8, 1);
    n.showmove();

    Move sum = m.add(n);
    sum.showmove();
    
    return 0;
}