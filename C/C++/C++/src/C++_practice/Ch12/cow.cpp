#include <iostream>
#include <cstring>
#include "cow.h"

Cow::Cow() {
    name[0] = '\0';
    hobby = NULL;
    weight = 0;
}

Cow::Cow(const char * nm, const char * ho, double wt) {
    strncpy(name, nm, 20);
    
    int len = strlen(ho);
    hobby = new char[len + 1];
    strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow & c) {
    strncpy(name, c.name, 20);
    
    int len = strlen(c.hobby);
    hobby = new char[len + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow() {
    delete [] hobby;
}

Cow & Cow::operator=(const Cow & c) {
    if (this == &c)
        return *this;

    strncpy(name, c.name, 20);
    delete [] hobby;
    
    int len = strlen(c.hobby);
    hobby = new char[len + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    return *this;
}

void Cow::ShowCow() const {
    using std::cout;
    using std::endl;

    cout << "이름: " << name << endl;
    cout << "취미: " << hobby << endl;
    cout << "몸무게: " << weight << endl;
}