#include <iostream>
using namespace std;

void fibonacci(int n)
{
    int f[n + 1];

    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << "\n"
         << f[n] << " ";
}

int main()
{
    fibonacci(9);
    return 0;
}