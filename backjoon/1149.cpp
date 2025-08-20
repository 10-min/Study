#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(3));
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    for (int i = 0; i < 3; i++) {
        int cost;
        std::cin >> cost;
        dp[1][i] = cost;
    }
    for (int i = 2; i <= N; i++) {
        int r, g, b;
        std::cin >> r >> g >> b;
        dp[i][0] = r + std::min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = g + std::min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = b + std::min(dp[i - 1][0], dp[i - 1][1]);
    }

    std::cout << *std::min_element(dp[N].begin(), dp[N].end()) << std::endl; 

    return 0;
}