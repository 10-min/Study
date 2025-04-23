#include <iostream>
const int Max = 5;
// 함수 원형
double* fill_array(double* start, double* end);
void show_array(double* start, double* end);
void revalue(double r, double* start, double* end);

int main() {
    using namespace std;
    double properties[Max];

    double* end = fill_array(properties, properties + Max);
    int size = (end - properties);
    show_array(properties, end);
    if (size > 0) {
        cout << "재평가율을 입력하십시오: ";
        double factor;
        while(!(cin >> factor)) {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "잘못 입력했습니다, 수치를 입력하세요: ";
        }
        revalue(factor, properties, end);
        show_array(properties, end);
    }
    cout << "프로그램을 종료합니다.\n";
    cin.get();
    cin.get();
    return 0;
}

double* fill_array(double* start, double* end) {
    using namespace std;
    double temp;
    double* i;
    for (i = start; i < end; i++) {
        cout << (i - start + 1) << "번 부동산의 가격: $";
        cin >> temp;
        if (!cin) {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "입력 불량; 입력 과정을 끝내겠습니다.\n";
            break;
        } else if (temp < 0) 
            break;
        *i = temp;
    }
    return i;   
}

void show_array(double* start, double* end) {
    using namespace std;
    for (double* i = start; i < end; i++) {
        cout << (i - start + 1) << "번 부동산: $";
        cout << *i << endl;
    }
}

void revalue(double r, double* start, double* end) {
    for (double* i = start; i < end; i++)
        *i *= r;
}