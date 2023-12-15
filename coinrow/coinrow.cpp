#include <iostream>
using namespace std;

void printCoins(int collected[], int coins[], int n)
{
    cout << "\ncoins collected are : ";
    for (int i = n - 1; i >= 0; i -= 2)
    {
        if (collected[i] == collected[i - 1])
        {
            i--;
        }
        cout << coins[i] << " , ";
    }
}

int coinRow(int coins[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return coins[0];
    }

    int m[n];

    m[0] = coins[0];
    m[1] = coins[1];

    for (int i = 2; i < n; ++i)
    {
        m[i] = max(m[i - 1], m[i - 2] + coins[i]);
    }

    cout << "Max amount can be formed without selecting adjacent coins are : " << m[n - 1];
    printCoins(m, coins, n);
}

int main()
{
    int n;
    cout << "Enter no of coins : ";
    cin >> n;
    int coins[n];

    cout << "Enter the coins : ";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    coinRow(coins, n);

    return 0;
}
