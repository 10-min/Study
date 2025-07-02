#include <iostream>
#include "cow.h"

int main () {
    using namespace std;

    Cow a("cow1", "walk", 20);
    Cow b("cow2", "running", 30);

    a.ShowCow();
    b.ShowCow();
    a = b;
    a.ShowCow();

    return 0;
}