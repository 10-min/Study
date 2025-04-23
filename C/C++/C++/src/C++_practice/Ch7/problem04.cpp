#include <iostream>
long double probability(unsigned numbers, unsigned picks);
int main() {
    using namespace std;
    double total, choices, megagTotal, megaChoices;
    cout << "전체 수의 개수와 뽑을 수의 개수를 입력하십시오:\n";
    while ((cin >> total >> choices) && choices <= total) {
        cout << "메가 수의 전체 개수와 뽑을 수의 개수를 입력하십시오:\n";
        if (!(cin >> megagTotal >> megaChoices)) break;
        cout << "당신이 이길 확률은 ";
        cout << probability(total, choices) * probability(megagTotal, megaChoices);
        cout << "번 중에서 한 번입니다.\n";
        cout << "다시 두 수를 입력하십시오. (끝내려면 q를 입력): ";
    }
    cout << "프로그램을 종료합니다.\n";
    return 0;
}

long double probability(unsigned numbers, unsigned picks) {
    long double result = 1.0;
    long double n;
    unsigned p;

    for (n = numbers, p = picks; p > 0; n--, p--) {
        result = result * n / p;
    }
    return result;
}