#include<iostream>

double mileToKm(double);

int main() {
    using namespace std;

    double mile;
    cout << "Enter the Mile: ";
    cin >> mile;
    cout << "Changed Mile in KM: " << mileToKm(mile) << endl;

}

double mileToKm(double mile) {
    return mile * 1.60934;
}