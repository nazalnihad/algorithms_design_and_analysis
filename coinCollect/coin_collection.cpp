#include <iostream>

using namespace std;

// Function to find the maximum number of coins that can be collected
int maxCoinCollection(int grid[][3], int rows, int cols)
{
    // Create a 2D array to store the maximum number of coins at each position
    int dp[rows][cols];

    // Fill in the array using dynamic programming
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
            }
            else if (i == 0)
            {
                dp[i][j] = dp[i][j - 1] + grid[i][j];
            }
            else if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] + grid[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
    }

    // The final result is stored at the bottom-right corner of the array
    return dp[rows - 1][cols - 1];
}

int main()
{
    // Example usage
    int grid[][3] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}};
    int rows = 3;
    int cols = 3;
    int result = maxCoinCollection(grid, rows, cols);

    cout << "Maximum number of coins that can be collected: " << result << endl;

    return 0;
}
