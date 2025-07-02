#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>

class complex {
private:
    double real_num;
    double img_num;
public:
    complex();
    complex(double r, double i);
    ~complex();
    
    complex operator+(const complex & c) const;
    complex operator-(const complex & c) const;
    complex operator*(const complex & c) const;
    complex operator*(double n) const;
    complex operator~() const;
    friend complex operator*(double n, const complex & c) {
        return c * n;
    }
    friend std::ostream & operator<<(std::ostream & os, const complex & c);
    friend std::istream & operator>>(std::istream & is, complex & c);
};

#endif