#include <iostream>
#include <cstring>
#include "golf.h"

void setgolf(golf & g, const char * name, int hc) {
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf & g) {
    std::cout << "Enter your name: ";
    std::cin.getline(g.fullname, sizeof(g.fullname));

    if (strlen(g.fullname) == 0) {
        return 0;
    }

    std::cout << "Enter your handicap: ";
    std::cin >> g.handicap;
    std::cin.ignore();
    return 1;
}

void handicap(golf & g, int hc) {
    g.handicap = hc;
}

void showgolf(const golf & g) {
    std::cout << "Name: " << g.fullname << std::endl;
    std::cout << "Handicap: " << g.handicap << std::endl;
}