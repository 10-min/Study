#include<iostream>

int yearsToMonths(int);

int main() {
    using namespace std;

    int age;

    cout << "Enter your age : ";
    cin >> age;
    cout << "Your age in months : " << yearsToMonths(age) << endl;
}

int yearsToMonths(int years) {
    return 12 * years;
}