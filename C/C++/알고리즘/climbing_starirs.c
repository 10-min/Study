#include <stdio.h>
#include <stdlib.h>

// Function to calculate the number of ways to climb n stairs
int climbStairs(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base cases: 1 way to stay at step 0 or 1 step
    }

    // Array to store the results of subproblems
    int* dp = (int*)malloc(sizeof(int) * n);

    // Initial conditions
    dp[0] = 1; // 1 way to stay at step 0
    dp[1] = 1; // 1 way to reach step 1

    // Fill the dp array using the recurrence relation dp(n) = dp(n-1) + dp(n-2)
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    

    return dp[n]; // Return the result for n steps
}

int main() {
    int n;

    // Input: number of steps
    printf("Enter the number of steps: ");
    scanf("%d", &n);

    // Output: number of distinct ways to climb the stairs
    printf("Number of ways to climb %d stairs: %d\n", n, climbStairs(n));

    return 0;
}
