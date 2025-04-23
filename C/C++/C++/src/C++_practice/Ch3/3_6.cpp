#include <iostream>
int main() {
    using namespace std;

    double miles, gallons;

    cout << "Enter the mileage in miles: ";
    cin >> miles;
    cout << "Enter the capacity of gasollin used in gallons: ";
    cin >> gallons;

    cout << "Your fuel efficiency in miles per gallon is: " << miles / gallons 
    << "miles/gallon" << endl;
    
    return 0;
}