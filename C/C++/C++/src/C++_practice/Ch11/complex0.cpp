#include "complex0.h"
#include <iostream>

complex::complex() {
    real_num = 0.0;
    img_num = 0.0;
}

complex::complex(double r, double i) {
    real_num = r;
    img_num = i;
}

complex::~complex() {}

complex complex::operator+(const complex & c) const {
    return complex(real_num + c.real_num, img_num + c.img_num);
}

complex complex::operator-(const complex &c) const
{
    return complex(real_num - c.real_num, img_num - c.img_num);
}

complex complex::operator*(const complex &c) const
{
    return complex((real_num*c.real_num) - (img_num * c.img_num), (real_num * c.img_num) + (img_num * c.real_num));
}

complex complex::operator~() const {
    return complex(real_num, -img_num);
}

complex complex::operator*(double n) const
{
    return complex(n * real_num, n * img_num);
}

std::ostream & operator<<(std::ostream & os, const complex & c) {
    os << '(' << c.real_num << ',' << c.img_num << "i)";
    return os;
}

std::istream & operator>>(std::istream & is, complex & c) {
    std::cout << "실수부: ";
    is >> c.real_num;
    if (!is) {return is;}
    std::cout << "허수부: ";
    is >> c.img_num;
    return is;
}