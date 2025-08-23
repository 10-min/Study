#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    const int MAX = 100;

    std::vector<std::vector<long long>> dp(MAX + 1, std::vector<long long>(10));

    dp[1][0] = 0;
    for (auto it = dp[1].begin() + 1; it != dp[1].end(); it++) {
        *it = 1;
    }

    for (int i = 2; i <= MAX; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][1];
            } else if (j == 9) {
                dp[i][j] = dp[i - 1][8];
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            }
            dp[i][j] %= 1000000000;
        }
    }

    int N;
    std::cin >> N;
    long long sum = 0;
    for (auto it = dp[N].begin(); it != dp[N].end(); it++) {
        sum += *it;
    }
    sum %= 1000000000;

    std::cout << sum << std::endl;
    return 0;
}