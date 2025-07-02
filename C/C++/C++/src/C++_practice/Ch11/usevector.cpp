#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "vector.h"
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
    int N;
    double min_step = __DBL_MAX__;
    double max_step = 0;
    double total_step = 0;
    double avg_step;
    cout << "목표 거리를 입력하십시오(끝내려면 q): ";
    while (cin >> target)
    {
        cout << "보폭을 입력하십시오: ";
        if (!(cin >> dstep))
            break;

        cout << "시행 횟수를 입력하십시오: ";
        cin >> N;

        for (int i = 0; i < N; i++) {
            while (result.magval() < target)
            {
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                steps++;
            }
            total_step += steps;

            if (max_step < steps) {
                max_step = steps;
            }
            if (min_step > steps) {
                min_step = steps;
            }
            steps = 0;
            result.reset(0.0, 0.0);
        }

        avg_step = total_step / N;

        cout << N << "번 시도했을 때\n";
        cout << "최고 걸음 수: " << max_step << endl;
        cout << "최저 걸음 수: " << min_step << endl;
        cout << "평균 걸음 수: " << avg_step << endl;
        
        cout << "목표 거리를 입력하십시오(끝내려면 q): ";
    }
    cout << "프로그램을 종료합니다.\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
}