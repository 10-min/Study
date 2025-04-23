#include <iostream>

int factorial(int n) {
    using namespace std;
    if (n < 0) {
        cout << "n must not be negative value\n";
        return 0;
    }

    if (n == 0 || n == 1) return 1;
    else {
        return n * factorial(n-1);
    }
}

int main() {
    using namespace std;
    int n;
    cout << "Enter the number of positive integer (enter not integer to quit): ";
    while((cin >> n)) {
        cout << n << "! :" << factorial(n) << endl;
        cout << "Re enter the number (enter not integer to quit): ";
    }
    return 0;
}