#include <iostream>
int main() {
    using namespace std;

    const int MinPerDeg {60};
    const int SecPerDeg {3600};

    int deg, arcmin, arcsec;

    cout << "위도를 도, 분, 초 단위로 입력하시오:\n";
    cout << "먼저, 도각을 입력하시오: ";
    cin >> deg;
    cout << "다음에, 분각을 입력하시오: ";
    cin >> arcmin;
    cout << "끝으로, 초각을 입력하시오: ";
    cin >> arcsec;

    cout << deg << "도, " << arcmin << "분, " << arcsec << "초 = "
    << deg + double (arcmin) / MinPerDeg + double (arcsec) / SecPerDeg
    << "도" << endl;
    return 0;
}