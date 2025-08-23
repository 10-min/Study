#include <iostream>
#include <vector>

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= N; i++) {
        dp[i][i - 1] = dp[i - 1][i - 1];
        for (int j = i; j < N; j++) {
            if (A[j] > A[i - 1]) dp[i][j] = max(dp[i - 1][j], dp[i][i - 1] + 1);
            else dp[i][j] = dp[i - 1][j];
        }
    }

    int max = 0;
    for (int i = 1; i <= N; i++) {
        if (max < dp[i][i - 1]) max = dp[i][i - 1];
    }

    std::cout << max << std::endl;

    return 0;
}