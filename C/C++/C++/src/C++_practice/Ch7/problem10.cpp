#include <iostream>

double calculate(double input1, double input2, double (*function)(double, double));
double add(double input1, double input2);
double sub(double input1, double input2);

int main() {
    using namespace std;

    while (1) {
        cout << "Enter 2 input for calculating:" << endl;
        double input1, input2;
        cin >> input1 >> input2;
        if (!cin) {
            break;
        }

        cout << input1 << " + " << input2 << ": " << calculate(input1, input2, add) << endl;
        cout << input1 << " - " << input2 << ": " << calculate(input1, input2, sub) << endl;
        cout << endl;
    }
    cout << calculate(2.5, 10.4, add) << endl;
    return 0;
}

double calculate(double input1, double input2, double (*function)(double, double)) {
    return function(input1, input2);
}

double add(double input1, double input2) {
    return input1 + input2;
}

double sub(double input1, double input2) {
    return input1 - input2;
}