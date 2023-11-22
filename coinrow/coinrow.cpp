#include <iostream>

using namespace std;

// Function to find the maximum sum of values without selecting adjacent coins
int maxCoinRowSum(int coins[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return coins[0];
    }

    // Create an array to store the maximum sum at each position
    int dp[n];

    // Base cases
    dp[0] = coins[0];
    dp[1] = max(coins[0], coins[1]);

    // Fill in the rest of the array using dynamic programming
    for (int i = 2; i < n; ++i)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + coins[i]);
    }

    // The final result is stored at the last position of the array
    return dp[n - 1];
}

int main()
{
    // Example usage
    int coins[] = {2, 4, 6, 8, 10};
    int n = sizeof(coins) / sizeof(coins[0]);
    int result = maxCoinRowSum(coins, n);

    cout << "Maximum sum of values without selecting adjacent coins: " << result << endl;

    return 0;
}
