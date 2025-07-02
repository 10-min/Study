#include <cmath>
#include "vect1.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR {
    const double Rad_to_deg = 45.0 / atan(1.0);

    void Vector::set_x(double mag, double ang) {
        x = mag * cos(ang);
    }

    void Vector::set_y(double mag, double ang)
    {
        y = mag * sin(ang);
    }

    Vector::Vector() {
        x =  y = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form) {
        mode = form;
        if (form == RECT) {
            x = n1;
            y = n2;
        } else if (form == POL) {
            double mag = n1;
            double ang = n2 / Rad_to_deg;
            set_x(mag, ang);
            set_y(mag, ang);
        } else {
            cout << "Vector()에 전달된 제3의 매개변수가 잘못되었다.\n";
            cout << "그래서 벡터를 0으로 설정하였다.\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    void Vector::reset(double n1, double n2, Mode form) {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
        }
        else if (form == POL)
        {
            double mag = n1;
            double ang = n2 / Rad_to_deg;
            set_x(mag, ang);
            set_y(mag, ang);
        }
        else
        {
            cout << "Vector()에 전달된 제3의 매개변수가 잘못되었다.\n";
            cout << "그래서 벡터를 0으로 설정하였다.\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    Vector::~Vector() {}

    double Vector::angval() const {
        if (x == 0.0 && y == 0.0)
            return 0.0;
        else
            return atan2(y, x);
    }

    double Vector::magval() const {
        return sqrt(x * x + y * y);
    }

    void Vector::polar_mode() {
        mode = POL;
    }

    void Vector::rect_mode() {
        mode = RECT;
    }

    Vector Vector::operator+(const Vector & b) const {
        return Vector(x + b.x, y + b.y);
    }

    Vector Vector::operator-(const Vector & b) const {
        return Vector(x - b.x, y - b.y);
    }

    Vector Vector::operator-() const {
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n) const {
        return Vector(x * n, y * n);
    }

    Vector::operator double() const {
        return magval();
    }

    Vector operator*(double n, const Vector & a) {
        return a * n;
    }

    std::ostream & operator<<(std::ostream  & os, const Vector & v) {
        if (v.mode == Vector::RECT)
            os << "(x,y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == Vector::POL)
            os << "(m,a) = (" << v.magval() << ", " << v.angval() * Rad_to_deg << ")";
        else
            os << "Vector 객체의 모드 지정이 틀려습니다.\n";
        return os;
    }
}
