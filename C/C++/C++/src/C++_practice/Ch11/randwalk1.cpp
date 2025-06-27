#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "vect.h"
int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    
    ofstream file;
    file.open("randwalk1.txt");
    
    cout << "목표 거리를 입력하십시오: ";
    cin >> target;
    cout << "보폭을 입력하십시오: ";
    cin >>dstep;
    file << "목표 거리: " << target << ", 보폭: " << dstep << endl;

    while (result.magval() < target) {
        direction = rand() % 360;
        step.reset(dstep, direction, Vector::POL);
        result = result + step;
        file << steps << ": " << result << endl;
        steps++;
    }
    file << steps << " 걸음 후 술고래가 서 있는 위치\n"
        << result << endl;
    result.polar_mode();
    file << "또는\n" << result << endl;
    file << "걸음당 기둥에서 벗어난 평균 거리 = " << result.magval() / steps << endl;
    return 0;
}