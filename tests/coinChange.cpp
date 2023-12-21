#include <iostream>
#include <climits>

using namespace std;
void showCoins(int F[], int coins[], int amount, int d)
{
    cout << "\nSelected coins are: ";
    while (amount > 0)
    {
        for (int i = 0; i < d; i++)
        {
            if (amount >= coins[i] && F[amount] == F[amount - coins[i]] + 1)
            {
                cout << coins[i] << " ";
                amount -= coins[i];
                break;
            }
        }
    }
}

void coinChange(int denominations, int amount, int coins[])
{
    int F[amount + 1];
    F[0] = 0;
    int j;

    for (int i = 1; i <= amount; i++)
    {
        j = 0;
        int temp = INT_MAX;
        while (j <= denominations && i >= coins[j])
        {
            temp = min(F[i - coins[j]], temp);
            j++;
        }
        F[i] = temp + 1;
    }
    cout << F[amount - 1];
    showCoins(F, coins, amount, denominations);
}
int main()
{
    int denominations[] = {1, 3, 4, 5};
    int amount = 9;
    int coinsCount = 4;

    coinChange(coinsCount, amount, denominations);

    return 0;
}