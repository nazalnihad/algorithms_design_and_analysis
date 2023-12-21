#include <iostream>
using namespace std;

void knapsack(int weights[], int values[], int items, int capacity)
{
    int **m = new int *[items + 1];
    for (int i = 0; i <= items; i++)
    {
        m[i] = new int[capacity + 1];
    }

    for (int i = 0; i <= items; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                m[i][j] = 0;
            }
            else if (j - weights[i - 1] < 0)
            {
                m[i][j] = m[i - 1][j];
            }
            else
            {
                m[i][j] = max(m[i - 1][j], values[i - 1] + m[i - 1][j - weights[i - 1]]);
            }
        }
    }

    cout << m[items][capacity];
    int selected[items];
    int selectedCount = 0;
    int i = items;
    int j = capacity;

    while (i > 0 && j > 0)
    {
        if (m[i][j] != m[i - 1][j])
        {
            selected[selectedCount++] = i - 1;
            j -= weights[i - 1];
        }
        i--;
    }
    cout << "\nselected items : ";
    for (int k = selectedCount - 1; k >= 0; k--)
    {
        cout << selected[k] + 1 << " ";
    }
}
int main()
{
    // Hardcoded values for weights and values of items
    int weights[] = {2, 1, 3, 2};
    int values[] = {12, 10, 20, 15};
    int items = 4;    // Number of items
    int capacity = 5; // Capacity of the knapsack

    knapsack(weights, values, items, capacity); // Call the knapsack function with hardcoded values

    return 0;
}