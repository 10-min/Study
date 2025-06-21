#include "plorg.h"
#include <iostream>
#include <cstring>

Plorg::Plorg(const char * name, int CI) {
    strncpy(this->name, name, MAX);
    this->CI = CI;
}

void Plorg::setCI(int CI) {
    this->CI = CI;
}

void Plorg::showplorg() const {
    using namespace std;

    cout << "Name: " << name << ", CI: " << CI << endl;
}