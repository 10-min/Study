#include <iostream>
int main() {
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);

    float tub = 10.0 / 3.0;
    double mint = 10.0 / 3.0;
    const float million = 1.0e6;

    cout << "tub = " << tub;
    cout << ", a million tubs = " << million * tub;
    cout << ",\nten million tubs = ";
    cout << 10 * million * tub << endl;

    cout << "miint = " << mint << "and a million mints = ";
    cout << million * mint << endl;
    return 0;
}