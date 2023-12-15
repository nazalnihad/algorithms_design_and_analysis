#include <iostream>
using namespace std;

void printCoins(int count[], int n, int coins[], int d)
{
    cout << "\n coins selected : ";
    n--;
    for (int i = 0; i < d; i++)
    {
        int value = count[n - coins[i]] + 1;
        if (value == count[n])
        {
            n -= coins[i];
            cout << coins[i] << ", ";
            i--;
        }
    }
}

void minCoins(int amount, int coins[], int d)
{
    int f[amount];
    f[0] = 0;
    for (int i = 1; i < amount; i++)
    {
        int temp = 10000;
        int j = 1;
        while (j <= d && i >= coins[j])
        {
            temp = min(f[i - coins[j]], temp);
            j++;
        }
        f[i] = temp + 1;
    }
    cout << "\nThe least amount of coins required are : " << f[amount - 1];
    printCoins(f, amount, coins, d);
}

int main()
{
    int n;
    cout << "Enter number of denomination coins: ";
    cin >> n;
    int coins[n];
    cout << "Enter value of denomination coins: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int amount;
    cout << "Enter amount to find change of: ";
    cin >> amount;
    minCoins(amount + 1, coins, n);

    return 0;
}