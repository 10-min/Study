#include "person.h"
#include <iostream>
#include <cstring>

Person::Person(const string & ln, const char * fn) {
    lname = ln;
    strncpy(fname, fn, LIMIT);
}

void Person::Show() const {
    std::cout << fname << " " << lname << std::endl;
}

void Person::FormalShow() const {
    std::cout << lname << ", " << fname << std::endl;
}
