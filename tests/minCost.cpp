#include <iostream>
using namespace std;

void showPath(int **m, int rows, int cols)
{
    int i = 0, j = 0;
    cout << "\n(" << i + 1 << "," << j + 1 << ")-->";
    while (i != rows && j != cols)
    {
        if (m[i + 1][j] <= m[i][j + 1] && m[i + 1][j] <= m[i + 1][j + 1])
        {
            i++;
        }
        else if (m[1][j + 1] <= m[i + 1][j] && m[1][j + 1] <= m[i + 1][j + 1])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
        cout << "(" << i + 1 << "," << j + 1 << ")-->";
    }
    cout << "(" << rows + 1 << "," << cols + 1 << ")-->";
}

void minPath(int **m, int rows, int cols)
{
    int **grid = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        grid[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == 0 && j == 0)
            {
                grid[i][j] = m[i][j];
            }
            else if (i == 0)
            {
                grid[i][j] = grid[i][j - 1] + m[i][j];
            }
            else if (j == 0)
            {
                grid[i][j] = grid[i - 1][j] + m[i][j];
            }
            else
            {
                int temp = min(grid[i - 1][j], grid[i][j - 1]);
                grid[i][j] = m[i][j] + min(grid[i - 1][j - 1], temp);
            }
        }
    }
    cout << "\nMin cost path sum is " << grid[rows - 1][cols - 1];
    showPath(grid, rows - 1, cols - 1);
}
int main()
{
    const int rows = 4; // You've used 3 rows in the minPath function
    const int cols = 3; // You've used 3 columns in the minPath function

    // Dynamically allocate memory for a 2D array
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols];
    }

    // Hardcoding example values for the 3x3 matrix
    matrix[0][0] = 3;
    matrix[0][1] = 2;
    matrix[0][2] = 8;

    matrix[1][0] = 1;
    matrix[1][1] = 9;
    matrix[1][2] = 7;

    matrix[2][0] = 0;
    matrix[2][1] = 5;
    matrix[2][2] = 2;

    matrix[3][0] = 6;
    matrix[3][1] = 4;
    matrix[3][2] = 3;

    minPath(matrix, rows, cols);
}