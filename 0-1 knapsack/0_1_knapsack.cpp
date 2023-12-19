#include <iostream>
using namespace std;

void findMaxFit(int weights[], int values[], int capacity, int items)
{
    int **matrix = new int *[items + 1];

    for (int i = 0; i <= items; i++)
    {
        matrix[i] = new int[capacity + 1];
    }

    for (int i = 0; i <= items; i++)
    {
        // cout << i;
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                matrix[i][j] = 0;
            }
            else if (j - weights[i - 1] < 0)
            {
                matrix[i][j] = matrix[i - 1][j];
            }
            else
            {
                matrix[i][j] = max(matrix[i - 1][j], (values[i - 1] + matrix[i - 1][j - weights[i - 1]]));
            }
        }
    }

    cout << "Max weight with max profit that can be selected : " << matrix[items][capacity];

    int selectedCoins[items];
    int selectedCount = 0;
    int i = items;
    int j = capacity;

    while (i > 0 && j > 0)
    {
        if (matrix[i][j] != matrix[i - 1][j])
        {
            selectedCoins[selectedCount++] = i - 1;
            j -= weights[i - 1];
            i--;
        }
        else
        {
            i--;
        }
    }

    cout << "\nSelected Items no's : ";
    for (int k = selectedCount - 1; k >= 0; k--)
    {
        cout << selectedCoins[k] + 1 << " ";
    }
}

int main()
{
    int items;
    cout << "Enter the number of items: ";
    cin >> items;

    int weights[items];
    int values[items];

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < items; ++i)
    {
        cin >> weights[i];
    }

    cout << "Enter the values of the items : ";
    for (int i = 0; i < items; ++i)
    {
        cin >> values[i];
    }

    int capacity;
    cout << "Enter the capacity: ";
    cin >> capacity;

    findMaxFit(weights, values, capacity, items);

    return 0;
}