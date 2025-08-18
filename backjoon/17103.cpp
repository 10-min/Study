#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> testcases(n);
    int max = 0;
    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;
        if (value > max) max = value;
        testcases[i] = value;
    }
    
    std::vector<int> arr(max + 1, 1);
    arr[0] = 0;
    arr[1] = 0;

    for (int i = 2; i <= sqrt(max); i++) {
        int mul = 2;
        while (mul * i <= max) {
            arr[(mul++) * i] = 0;
        }
    }

    std::vector<int> primes;

    for (int i = 2; i <= max; i++) {
        if (arr[i]) primes.push_back(i);
    }

    for (auto& c : testcases) {
        int count = 0;
        for (auto &value : primes)
        {
            if (c / 2 < value) break;
            auto found = arr[c - value];
            if (found) count++;
        }
        std::cout << count << std::endl;
    }

    return 0;
}