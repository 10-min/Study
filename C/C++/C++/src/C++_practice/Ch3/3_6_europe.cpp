#include <iostream>
int main() {
    using namespace std;

    double km, liters;

    cout << "Enter the mileage in km: ";
    cin >> km;
    cout << "Enter the capacity of gasollin used in liters: ";
    cin >> liters;

    cout << "Your fuel efficiency in liters per 100km is: " << liters / (km*0.01) 
    << "liters/100km" << endl;
    
    return 0;
}