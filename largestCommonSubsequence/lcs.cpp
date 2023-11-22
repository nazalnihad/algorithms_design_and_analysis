#include <iostream>
using namespace std;

void lcs(int row, int col, string text1, string text2)
{
    int mat[row + 1][col + 1];

    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= col; j++)
        {

            if (i == 0 || j == 0)
            {
                mat[i][j] = 0;
            }

            else if (text1[i - 1] == text2[j - 1])
            {
                mat[i][j] = mat[i - 1][j - 1] + 1;
                // x = x + text1[i];
            }

            else
            {
                mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
            }
        }
    }

    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= col; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    int x = row, y = col;
    // return mat[row][col];
    cout << "\n"
         << "The largest common subsequence length is : " << mat[row][col];
}

int main()
{
    string S1 = "ABBCDS";
    string S2 = "BSDFA";
    int m = S1.size();
    int n = S2.size();

    lcs(m, n, S1, S2);

    return 0;
}