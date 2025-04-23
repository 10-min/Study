#include <iostream>
int main() {
    using namespace std;

    char firstName[20];
    char lastName[20];
    char grade;
    int age;

    cout << "영문 퍼스트 네임 (이름) : ";
    cin.getline(firstName, 20);
    cout << "영문 라스트 네임 (성) : ";
    cin >> lastName;
    cout << "학생이 원하는 학점: ";
    cin >> grade;
    cout << "나이: ";
    cin >> age;

    cout << "성명: " << lastName << ", " << firstName << endl;
    cout << "학점: " << (char) (grade+1) << endl;
    cout << "나이: " << age << endl;

    return 0;
}