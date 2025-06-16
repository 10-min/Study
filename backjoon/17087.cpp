#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

long long gcd(long long a, long long b) {
    while (b != 0) {
        auto temp_a = a;
        a = b;
        b = temp_a % b;
    }
    
    return a;
}

int main() {
    using namespace std;

    long long N,S;
    cin >> N >> S;

    vector<long long> arr;
    long long A;
    for (int i = 0; i < N; i++) {
        cin >> A;
        arr.push_back(abs(S - A));
    }
    long long temp = arr[0];

    for (int i = 1; i < N; i++) {
        temp = gcd(temp, arr[i]);
    }

    cout << temp << endl;
    return 0;
}