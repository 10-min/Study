#include <iostream>
#include <vector>
#include <cmath>

int main() {

    int A, B, m;
    std::cin >> A >> B;
    std::cin >> m;

    long long value = 0;

    for (int i = m - 1; i >= 0; i--) {
        int temp;
        std::cin >> temp;
        value += temp * pow(A, i);
    }

    std::vector<int> result;
    while (true) {
        if (value / B == 0) {
            result.push_back(value);
            break;
        }

        result.push_back(value % B);
        value /= B;
    }

    for(int i = result.size() - 1; i >= 0; i--) {
        std::cout << result[i] << " ";
    }

    return 0;
}