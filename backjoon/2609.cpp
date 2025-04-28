#include <iostream>
#include <algorithm>

int main() {
    using namespace std;

    int a, b;

    cin >> a >> b;
    int gcd;
    int lcm;
    int temp;
    int temp_a = a, temp_b = b;
    while (temp_b > 0) {
        temp = temp_b;
        temp_b = temp_a % temp_b;
        temp_a = temp;
    }
    gcd = temp_a;
    lcm = a * b / gcd;

    cout << gcd << endl;
    cout << lcm << endl;
    
    return 0;
}

