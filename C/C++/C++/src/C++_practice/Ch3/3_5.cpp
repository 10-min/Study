#include <iostream>
int main() {
    using namespace std;

    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(5);

    long long worldPopulation;
    long long koreaPopulation;

    cout << "세계 인구수를 입력하시오: ";
    cin >> worldPopulation;
    cout << "한국 인구수를 입력하시오: ";
    cin >> koreaPopulation;
    cout << "세계 인구수에서 한국이 차지하는 비중은 " << double (koreaPopulation) / worldPopulation * 100
    << "%이다." << endl;

    return 0;

}