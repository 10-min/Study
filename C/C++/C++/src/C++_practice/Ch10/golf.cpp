#include <iostream>
#include <cstring>
#include "golf.h"

Golf::Golf(const char *name, int hc)
{
    strncpy(fullname, name, Len);
    handicap = hc;
}

Golf::Golf()
{
    std::cout << "Enter your name: ";
    std::cin.getline(fullname, sizeof(fullname));

    if (strlen(fullname) == 0)
    {
        strncpy(fullname, "Taemin", Len);
    }

    std::cout << "Enter your handicap: ";
    std::cin >> handicap;
    std::cin.ignore();
}

void Golf::sethandicap(int hc)
{
    handicap = hc;
}

void Golf::showgolf()
{
    std::cout << "Name: " << fullname << std::endl;
    std::cout << "Handicap: " << handicap << std::endl;
}