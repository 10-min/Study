#include <iostream>
int main() {
    using namespace std;

    int n, sum = 0;

    while(1) {
        cout << "Enter the integer(exit: 0): ";
        cin >> n;
        if (n == 0) break;
        sum += n;
        cout << "Sum of input integers: " << sum << endl;
    }
    return 0;
}