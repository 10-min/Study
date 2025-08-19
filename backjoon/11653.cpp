#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int N;
    std::cin >> N;
    if (N == 1) return 0;
    std::vector<bool> isPrime(N + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i <= sqrt(N); i++) {
        int mul = 2;
        while (mul * i <= N) {
            isPrime[(mul++) * i] = false;
        }
    }

    std::vector<int> primes;
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
    int i = 0;
    while (i < primes.size()) {
        if (N % primes[i] == 0) {
            std::cout << primes[i] << std::endl;
            N /= primes[i];
            continue;
        } else {
            i++;
        }
    }

    return 0;
}