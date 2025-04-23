#include <iostream>

struct car {
    char name[20];
    int year;
};

int main() {
    using namespace std;
    cout << "몇 대의 차를 목록으로 관리하시겠습니까? ";
    int numberOfCar;
    cin >> numberOfCar;

    car* carArr = new car[numberOfCar];

    for (int i = 0; i < numberOfCar; i++) {
        cout << "자동차 #" << i+1 << ":\n";
        cout << "제작업체: ";
        cin >> carArr[i].name;
        cin.get();
        cout << "제작년도: ";
        cin >> carArr[i].year;
    }

    cout << "현재 귀하가 보유하고 있는 자동차 목록은 다음과 같습니다.\n";
    for (int i = 0; i < numberOfCar; i++) {
        cout << carArr[i].year << "년형 " << carArr[i].name << endl; 
    }
}