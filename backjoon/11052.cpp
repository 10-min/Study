#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> cost(N + 1);
    cost[0] = 0;

    std::vector<int> dp(N + 1);
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        std::cin >> cost[i];
        int max = 0;
        for (int j = 0; j < i; j++) {
            if (max > (dp[j] + cost[i - j]))
            {
                max = dp[j] + cost[i - j];
            }
        }
        dp[i] = max;
    }

    std::cout << dp[N] << std::endl;

    return 0;
}