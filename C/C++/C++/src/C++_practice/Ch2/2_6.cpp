#include<iostream>

double lightYearsToAstronomicalUnit(double);

int main() {
    using namespace std;

    cout << "Enter the Light years : ";

    double lightYears;
    cin >> lightYears;

    cout << lightYears << " light years are " << lightYearsToAstronomicalUnit(lightYears) << " astronomical unit" << endl;

    return 0;
}

double lightYearsToAstronomicalUnit(double lightYears) {
    return 63240 * lightYears;
}