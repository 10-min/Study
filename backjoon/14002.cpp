#include <iostream>
#include <vector>
#include <utility>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> A[i];
    }

    std::vector<std::vector<std::pair<int, int>>> dp(N + 1, std::vector<std::pair<int, int>>(N, {0, 0}));
    for (int i = 0; i < N; i++)
    {
        dp[0][i].first = 1;
        dp[0][i].second = -1;
    }
    for (int i = 1; i <= N; i++)
    {
        dp[i][i - 1] = dp[i - 1][i - 1];
        for (int j = i; j < N; j++)
        {
            if (A[j] > A[i - 1]) {
                if (dp[i - 1][j].first < dp[i][i - 1].first + 1)
                    dp[i][j].second = i - 1;
                else 
                    dp[i][j].second = dp[i - 1][j].second;
                dp[i][j].first = max(dp[i - 1][j].first, dp[i][i - 1].first + 1);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int max = 0;
    int index = 0;
    for (int i = 1; i <= N; i++)
    {
        if (max < dp[i][i - 1].first) {
            max = dp[i][i - 1].first;
            index = i - 1;
        }          
    }

    std::vector<int> result;

    for (int i = 0; i < max; i++) {
        result.push_back(A[index]);
        index = dp[index + 1][index].second;
    }
    std::cout << max << std::endl;
    for (int i = max - 1; i >= 0; i--) {
        std::cout << result[i] << " ";
    }


    return 0;
}