#include <iostream>
#include <cstring>
int main() {
    using namespace std;

    char firstName[20];
    char lastName[20];

    cout << "퍼스트 네임 (이름) 을 입력하시오: ";
    cin.getline(firstName, 20);
    cout << "라스트 네임 (성) 을 입력하시오: ";
    cin.getline(lastName, 20);

    char name[30];
    
    strcpy(name, lastName);
    strcat(name, ", ");
    strcat(name, firstName);

    cout << "하나의 문자열로 만들면: " << name << endl;
    
    return 0;
}