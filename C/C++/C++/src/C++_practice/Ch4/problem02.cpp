#include <iostream>
#include <string>
int main() {
    using namespace std;
    string name;
    string dessert;

    cout << "이름을 입력하십시오:\n";
    getline(cin, name);
    cout << "좋아하는 디저트를 입력하십시오:\n";
    getline(cin, dessert);
    cout << "맛있는 " << dessert;
    cout << " 디저트를 준비하겠습니다. " << name << " 님!\n";
    return 0;
}