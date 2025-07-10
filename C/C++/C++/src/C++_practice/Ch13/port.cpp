#include <iostream>
#include <cstring>
#include "port.h"

Port::Port(const char * br, const char * st, int b) {
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
    strncpy(style, st, 19);
    style[19] = '\0';
    bottles = b;
}

Port::Port(const Port & p) {
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strncpy(style, p.style, 19);
    style[19] = '\0';
    bottles = p.bottles;
}

Port & Port::operator=(const Port & p) {
    if (this == &p)
        return *this;

    delete [] brand;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strncpy(style, p.style, 19);
    style[19] = '\0';
    bottles = p.bottles;
    return *this;
}

Port & Port::operator+=(int b) {
    bottles += b;
    return *this;
}

Port & Port::operator-=(int b) {
    if (bottles >= b) {
        bottles -= b;
    } else {
        cout << "bottles 보다 많은 수를 뺄 수 없습니다.\n";
    }
    return *this;
}

void Port::Show() const {
    cout << "브랜드: " << brand << endl;
    cout << "스타일: " << style << endl;
    cout << "수량: " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p) {
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

VintagePort::VintagePort(const char * br, const char * style, int b, const char * nn, int y) 
            : Port(br, "vintage", b)
{
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;

}

VintagePort & VintagePort::operator=(const VintagePort & vp) {
    if (this == &vp)
        return *this;

    Port::operator=(vp);
    delete [] nickname;
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::Show() const {
    Port::Show();
    cout << "별명: " << nickname << endl;
    cout << "포도 수확 년도: " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp) {
    os << (const Port &) vp << ", " << vp.nickname << ", " << vp.year;
    return os;
}