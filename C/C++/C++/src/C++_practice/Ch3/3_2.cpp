#include <iostream>

int main() {
    using namespace std;

    const int InchsPerFeet {12};
    const double PoundsPerKg {2.2};

    int feets;
    int inchs;
    int pounds;

    cout << "Enter your height in feets and inchs.\n";
    cout << "Feets: ";
    cin >> feets;
    cout << "Inchs: ";
    cin >> inchs;

    cout << "Enter your weight in pounds: ";
    cin >> pounds;
    cout << endl;

    double heightInMeter = (feets * InchsPerFeet + inchs)*0.0254;
    double weightInKg = pounds / PoundsPerKg;
    
    cout << "Your BMI is: " << weightInKg / (heightInMeter * heightInMeter);
    return 0;
}