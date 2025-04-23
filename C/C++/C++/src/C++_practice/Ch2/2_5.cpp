#include<iostream>

double celsiusToFahrenheit(double);

int main() {
    using namespace std;
    
    cout << "Enter Temperature in Celsius : ";
    
    double celsius;

    cin >> celsius;
    cout << celsius << " in Celsius is " << celsiusToFahrenheit(celsius) << " in Fahrenheit" << endl;
    
    return 0;
}

double celsiusToFahrenheit(double celcius) {
    return 1.8 * celcius + 32.0;
}