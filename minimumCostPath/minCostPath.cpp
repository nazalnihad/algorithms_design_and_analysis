#include <iostream>
using namespace std;

int minPath(int grid[][3], int rows, int cols)
{
    int **m = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        m[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == 0 && j == 0)
            {
                m[i][j] = grid[i][j];
            }
            else if (i == 0)
            {
                m[i][j] = m[0][j - 1] + grid[i][j];
            }
            else if (j == 0)
            {
                m[i][j] = m[i - 1][j] + grid[i][j];
            }
            else
            {
                int temp = min(m[i - 1][j], m[i][j - 1]);
                m[i][j] = grid[i][j] + min(m[i - 1][j - 1], temp);
            }
        }
    }

    int result = m[rows - 1][cols - 1];

    // Deallocate memory
    for (int i = 0; i < rows; i++)
    {
        delete[] m[i];
    }
    delete[] m;

    return result;
}

int main()
{
    const int rows = 3;
    const int cols = 3;

    // Hardcoded 3x3 grid
    int exampleGrid[3][3] = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};

    int result = minPath(exampleGrid, rows, cols);

    cout << "The minimum path sum is: " << result << endl;

    return 0;
}
