#include <iostream>
#include <vector>

int main()
{
    int T, n;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        std::cin >> n;
        std::vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int j = 2; j <= n; j++)
        {
            if (j - 3 >= 0)
            {
                dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
            }
            else
            {
                dp[j] = dp[j - 1] + dp[j - 2];
            }
        }

        std::cout << dp[n] << std::endl;
    }
    

    return 0;
}