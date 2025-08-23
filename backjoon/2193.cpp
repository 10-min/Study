#include <iostream>
#include <vector>
int main()
{
    const int MAX = 90;
    
    std::vector<std::vector<long long>> dp(MAX + 1, std::vector<long long>(2));
    dp[1][0] = 0;
    dp[1][1] = 1;

    for (int i = 2; i <= MAX; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }

    int N;
    std::cin >> N;
    std::cout << dp[N][0] + dp[N][1] << std::endl;
    return 0;
}