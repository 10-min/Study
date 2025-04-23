#include <iostream>

void getTwoNumber(double &x, double &y) {
    using namespace std;
    cout << "Enter two number:\n";
    cin >> x;
    cin >> y;
}

double harmonicMean(double x, double y) {
    return 2.0 * x * y / (x + y);
}

int main() {
    using namespace std;
    double x,  y;
    while (1) {
        getTwoNumber(x, y);
        if (x == 0 || y == 0) break;
        cout << "Harmonic Mean of " << x << " and " << y << ": " << harmonicMean(x, y) << endl;
    }
    return 0; 
}