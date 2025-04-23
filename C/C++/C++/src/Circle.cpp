#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Circle {
    private:
    double radius;

    public:
    Circle() {
        radius = 0;
    }
    Circle(double r) {
    radius = r;
    } 
    double area() {
        return M_PI*pow(radius, 2);
    }
    double circumference() {
        return M_PI * 2 * radius;
    }
    double getRadius() {
        return radius;
    }
    string toString() {
        string tmp = "Circle{radius=" + to_string(getRadius()) + "}";
        return tmp;
    }

};

int main() {

    Circle c(10);

    cout << c.toString();

    return 0;
}