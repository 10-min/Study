#include <iostream>
int main() {
    using namespace std;

    const double ARate = 0.1;
    const double BRate = 0.05;

    int principal = 100000;
    double aTotal, bTotal;
    aTotal = bTotal = principal;

    int years = 0;
    while (bTotal <= aTotal) {
        years++;
        aTotal += principal*ARate;
        bTotal += bTotal*BRate;
    }

    cout << "After " << years << " years "
        << "value of B exceeds value of A.\n";
    cout << "Total value\n"
        << "A: " << aTotal << endl
        << "B: " << bTotal << endl;
    return 0;
}