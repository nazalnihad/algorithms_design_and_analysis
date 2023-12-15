#include <iostream>
using namespace std;

void traceBack(int **grid, int rows, int cols)
{
    int i = rows - 1;
    int j = cols - 1;
    cout << "Path of optimal decisions:" << endl;
    cout << "(" << i << ", " << j << ")";
    while (i > 0 || j > 0)
    {
        if (i > 0 && j > 0)
        {
            if (grid[i - 1][j] >= grid[i][j - 1])
            {
                --i;
            }
            else
            {
                --j;
            }
        }
        else if (i > 0)
        {
            --i;
        }
        else
        {
            --j;
        }
        cout << " <- (" << i << ", " << j << ")";
    }
    cout << endl;
}

int maxCoinCollection(int **grid, int rows, int cols)
{
    int dp[rows][cols];
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

    return dp[rows - 1][cols - 1];
}

int main()
{
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
    int **grid = new int *[rows];
    for (int i = 0; i < rows; ++i)
    {
        grid[i] = new int[cols];
    }

    cout << "Enter the elements of the grid:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        cout << "ROW " << i << " : ";
        for (int j = 0; j < cols; ++j)
        {
            cin >> grid[i][j];
        }
    }

    int result = maxCoinCollection(grid, rows, cols);
    traceBack(grid, rows, cols);

    cout << "Maximum number of coins that can be collected: " << result << endl;

    return 0;
}
