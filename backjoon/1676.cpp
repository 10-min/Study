#include <iostream>

int number_of_zero(long long n) {
    int count = 0;
    
    for (int i = 5; i <= n; i*= 5) {
        count += n / i;
    }
    return count;
}

int main() {
    using namespace std;

    long long n;

    cin >> n;

    cout << number_of_zero(n) << endl;

    return 0;
}