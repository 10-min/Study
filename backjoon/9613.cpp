#include <iostream>
#include <vector>

long long gcd(long long a, long long b) {
    long long temp_a = a;
    while (b != 0) {
        a = b;
        b = temp_a % b;
        temp_a = a;
    }
    return a;
}

int main() {
    using namespace std;

    int t, n;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;

        vector<long long> arr(n);

        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        long long sum = 0;

        for (int j = 0; j < arr.size() - 1; j++) {
            for (int k = j + 1; k < arr.size(); k++) {
                sum += gcd(arr[j], arr[k]);
            }
        }

        cout << sum << endl; 
    }

    return 0;
}