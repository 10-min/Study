#include <iostream>
#include <ctime>
int main() {
    using namespace std;
    cout << "지연 시간을 초 단위로 입력하십시오: ";
    float secs;
    cin >> secs;
    clock_t delay = secs * CLOCKS_PER_SEC;

    cout << "카운트를 시작합니다.\a\n";
    clock_t start = clock();
    while (clock() - start < delay)
    ;
    cout << "종료\a\n";
    return 0;
}