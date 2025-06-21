#include "person.h"
#include <iostream>

int main() {
    using namespace std;
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");
    one.Show();
    cout << endl;
    two.FormalShow();
    return 0;
}