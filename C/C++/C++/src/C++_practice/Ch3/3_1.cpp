#include <iostream>
int main() {
    using namespace std;

    const int CmPerMeter {100};

    int height;
    cout << "Enter your height in centimeter: ___\b\b\b";
    cin >> height;

    cout << "Your height " << height << "cm "
    << "is:\n";
    cout << height / CmPerMeter << "m " << height % CmPerMeter << "cm.\n";
    return 0;
}